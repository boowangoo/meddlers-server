#pragma once

#include <string>

#include "meddlers-common.h"
#include "server/net.h"

class game_server {
private:
    ip::address addr;
    uint8_t port;
    str doc_root;
    net::io_context ioc;
public:
    game_server(ip::address addr, uint8_t port);
    void run();
};
