#ifndef MAP_H
#define MAP_H

#include "Tile.h"
#include <vector>

class Map
{
public:
    Map();
    ~Map();

    bool loadMap(const std::string &mapFile, SDL_Renderer *renderer);
    void drawMap(SDL_Renderer *renderer);

private:
    std::vector<std::vector<Tile *>> tileMap;
    int mapWidth;
    int mapHeight;
};

#endif // MAP_H
