#include <memory>

#include "server/game-server.h"
#include "server/listener.h"

game_server::game_server(ip::address addr, uint8_t port) :
        addr(addr), port(port), doc_root(".") {
}

void game_server::run() {
    // Create and launch a listening port
    mk_shared<listener>(
        ioc,
        tcp::endpoint{addr, port},
        mk_shared<shared_state>(doc_root)
    )->run();

    // Capture SIGINT and SIGTERM to perform a clean shutdown
    net::signal_set signals(ioc, SIGINT, SIGTERM);
    signals.async_wait(
        [this](err_code const&, int) {
            // Stop the io_context. This will cause run()
            // to return immediately, eventually destroying the
            // io_context and any remaining handlers in it.
            this->ioc.stop();
        }
    );

    ioc.run();
}
