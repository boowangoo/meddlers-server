#pragma once

#include <unordered_map>
#include <boost/optional.hpp>

#include "aliases.h"
#include "player.h"

enum class EdgeDir {
    edgeTopLeft, edgeTopRight,
    edgeMidLeft, edgeMidRight,
    edgeBotLeft, edgeBotRight
};
enum class NodeDir {
    nodeTopLeft, nodeTopMid, nodeTopRight,
    nodeBotLeft, nodeBotMid, nodeBotRight
};

class BoardSpace {
private:
    opt<Player> occupier;
public:
    BoardSpace();
    void place();
};

class BoardNode : BoardSpace {
private:
    opt<NodePiece> piece;
};

class BoardEdge : BoardSpace {
private:
    opt<Road> road;
};

class Tile : BoardSpace {
private:
    uMap<EdgeDir, opt<BoardEdge>> edges;
    uMap<NodeDir, opt<BoardNode>> nodes;
public:
    void remove_robber();
};
