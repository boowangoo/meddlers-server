#include "server/listener.h"

void listener::run() {
    acceptor.async_accept(
        socket,
        [self = shared_from_this()](err_code err) {
            self->on_accept(err);
        }
    );
}