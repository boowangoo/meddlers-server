#include <cstdint>
#include <cstdlib>
#include <boost/asio.hpp>
#include <iostream>

#include "server/game-server.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage:\t" <<
            "meddlers-server <address> <port>\n" <<
            "Example:\t" <<
            "meddlers-server 0.0.0.0 8080\n";
        return EXIT_FAILURE;
    }

    auto addr = ip::make_address(argv[1]);
    auto port = static_cast<uint8_t>(std::atoi(argv[2]));

    std::make_shared<game_server>(addr, port)->run();


    std::cout << "Hello world" << std::endl;
    return EXIT_SUCCESS;
}
