#include <iostream>
#include <iterator>
#include <stack>

#include <SFML/Graphics.hpp>

#include <GOL_Grid.h>
#include <I_GameState.h>
#include <Setup.h>
#include <GOL.h>

int main()
{
    // Window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Conways Game Of Life");
    window.setFramerateLimit( 5 );

    std::stack<I_GameState*> state;
    state.push( new Setup( &window ) );

    GOL_Grid gol_grid = GOL_Grid( (int)window.getSize().x, (int)window.getSize().y );

    // GameLoop
    while (window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }// endIf

            // Stack will check if nullptr is returned and will Pop Stack,
            // if a ptr different than the Top is returned it will be Pushed
            I_GameState* newState = (*state.top()).HandleInput( event, gol_grid );
            if( newState == nullptr ){
                state.pop();
            }else if( newState != state.top() ){
                state.push( newState );
            }

        }// endWhile

        // Update the Game
        state.top()->Update( gol_grid );

        window.clear();
        for( auto it = gol_grid.Get_GolVec().begin(); it != gol_grid.Get_GolVec().end(); it++ ){
            window.draw( *it );
        }
        window.display();
    }// endWhile

    // delete The Rest in the Stack
    while( !state.empty() ){
        delete state.top();
        state.pop();
    }

    return 0;
}
