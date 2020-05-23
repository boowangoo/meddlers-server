#pragma once

#include <vector>

#include "game-piece.h"
#include "dev-card.h"
#include "resource.h"

class Inventory {
protected:
    std::vector<DevCard> devCards;
    std::vector<Brick> res_bricks;
    std::vector<Lumber> res_lumbers;
    std::vector<Wool> res_wools;
    std::vector<Grain> res_grains;
    std::vector<Ore> res_ores;
};

class Bank : Inventory {
};

class PlayerInv : Inventory {
private:
    std::vector<Settlement> pc_settlements;
    std::vector<City> pc_cities;
    std::vector<Road> pc_roads;
};
