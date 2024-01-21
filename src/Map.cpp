#include "Map.h"
#include "TextureManager.h" // Assume this is the class you created earlier

Map::Map() : mapWidth(0), mapHeight(0) {}

Map::~Map()
{
    for (auto row : tileMap)
    {
        for (Tile *tile : row)
        {
            delete tile;
        }
    }
    tileMap.clear();
}

bool Map::loadMap(const std::string &mapFile, SDL_Renderer *renderer)
{
    // This function should load the map file and populate the tileMap
    // For simplicity, I'm assuming a fixed-size map and fixed tile size

    int tileSize = 32; // Assuming each tile is 32x32 pixels
    SDL_Texture *tileTexture = TextureManager::loadTexture("path/to/tile.bmp", renderer);

    for (int y = 0; y < mapHeight; ++y)
    {
        std::vector<Tile *> row;
        for (int x = 0; x < mapWidth; ++x)
        {
            row.push_back(new Tile(x * tileSize, y * tileSize, tileSize, tileTexture));
        }
        tileMap.push_back(row);
    }
    return true;
}

void Map::drawMap(SDL_Renderer *renderer)
{
    for (auto row : tileMap)
    {
        for (Tile *tile : row)
        {
            tile->draw(renderer);
        }
    }
}
