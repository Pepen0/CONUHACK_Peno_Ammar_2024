#ifndef GAME_STATE_H
#define GAME_STATE_H

class GameState
{
public:
    virtual void handleEvents() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual ~GameState() {}
};

#endif // GAME_STATE_H
