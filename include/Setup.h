#ifndef SETUP_H
#define SETUP_H

#include <SFML/Window/Window.hpp>

#include <I_GameState.h>
#include <GOL.h>

class Setup : public I_GameState
{
    public:
        Setup( sf::Window* _window ): window(_window) {};
        virtual ~Setup() = default;

        //////////////////////////////////////////////////////
        /// \brief is not needed in Setup
        /// \brief but is defined to complete the StateMachine
        /// \see Interface I_GameState
        virtual void Update( GOL_Grid& gol_grid ){};

        /////////////////////////////////////////////////////////////
        /// \brief Sets Quads Alive or Dying
        /// \brief left click will Invert the Alive State of the Quad
        /// \brief right click will Invert the Dying State of the Quad
        /// \brief Enter Changes the Sate of the StateMachine
        /// \see Interface I_GameState
        virtual I_GameState* HandleInput( sf::Event& event, GOL_Grid& gol_grid ){
            if( event.type == sf::Event::MouseButtonPressed ){
                if( event.mouseButton.button == sf::Mouse::Right ){
                    // Invert Dying State
                    gol_grid.Invert_QuadDying( sf::Mouse::getPosition( *window ) );
                    gol_grid.Invert_QuadComingToLife( sf::Mouse::getPosition( *window ) );

                }else if( event.mouseButton.button == sf::Mouse::Left ){
                    // Invert Alive State
                    gol_grid.Invert_QuadAlive( sf::Mouse::getPosition( *window ) );

                }// EndElseIf
            }else if( event.type == sf::Event::KeyPressed ){
                if( event.key.code == sf::Keyboard::Enter )
                {
                    // Return a GOL Object
                    // this Starts the Game
                    return new GOL();
                }// EndIf
            }// EndElseIf

            return this;
        };

    private:
        sf::Window* window;
};

#endif // SETUP_H
