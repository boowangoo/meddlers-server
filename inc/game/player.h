#pragma once

#include <stdint.h>

#include "aliases.h"
#include "inventory.h"
#include "board.h"

// TODO: move to own header
enum class TradeResp { tradeAccept, tradeDeny };

class Player {
private:
    quant id;
    quant vp;
    quant knights;
    PlayerInv inv;
    void buy();
public:
    Player();
    void build(GamePiece pc, BoardSpace bs);

    // TODO: trade class
    void init_trade(Player p);
    void set_trade(Player p, uMap<Resource, quant> res);
    void submit_trade(Player p, uMap<Resource, quant> res);
};
