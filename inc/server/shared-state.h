#pragma once

#include "meddlers-common.h"
#include "server/sessions.h"

class shared_state {
    str doc_root;
    u_set<websocket_session*> sessions;
public:
    shared_state(str doc_root);
    str get_doc_root();

    void join(websocket_session& session);
    void leave(websocket_session& session);
    void send(str msg);
};
