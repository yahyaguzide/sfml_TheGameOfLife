#ifndef I_GAMESTATE_H
#define I_GAMESTATE_H

#include <vector>

#include <SFML/Window/Event.hpp>

#include <GOL_Grid.h>

class I_GameState
{
    public:
        virtual ~I_GameState() = default;

        virtual void Update( GOL_Grid& gol_grid ) = 0;
        virtual I_GameState* HandleInput( sf::Event& event, GOL_Grid& gol_grid ) = 0;


};

#endif // I_GAMESTATE_H
