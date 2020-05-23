#pragma once

#include <memory>
#include <boost/asio/ip/tcp.hpp>

#include "server/net.h"
#include "server/shared-state.h"

class listener : public en_shared_this<listener> {
private:
    tcp::acceptor acceptor;
    tcp::socket socket;
    shared_ptr<shared_state> state;

    void fail(err_code er, char const* what);
    void on_accept(err_code er);
public:
    listener(
        net::io_context& io,
        tcp::endpoint endpt,
        shared_ptr<shared_state> const& state);
    // start accepting incoming connections
    void run();
};
