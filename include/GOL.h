#ifndef GOL_H
#define GOL_H

#include <iterator>
#include <vector>

#include <I_GameState.h>
#include <Setup.h>

class GOL : public I_GameState
{
    public:
        GOL() = default;
        virtual ~GOL() = default;

        /////////////////////////////////////////////////
        /// \brief Checks if Quads are alive or dead
        /// \brief also sets them dying or coming to life
        /// \see Interface I_GameState
        virtual void Update( GOL_Grid& gol_grid ){

            // set all Quads that are ether dying or coming to life
            for( auto it = gol_grid.Get_GolVec().begin(); it != gol_grid.Get_GolVec().end(); it++ ){
                // if the Quad was Dying or coming to Life
                // set it Dead or Alive
                if( (*it).Is_ComingToLife() ){
                    (*it).Set_Alive( true );
                }else if( (*it).Is_Dying() ){
                    (*it).Set_Alive( false );
                }// EndElseIf
            }

        int X = 0;
            for( auto it = gol_grid.Get_GolVec().begin(); it != gol_grid.Get_GolVec().end(); it++ ){

                int alive_Neighbors = 0;
                for( int j = -1; j< 2; j+= 1 ){
                    for( int i = -1; i< 2; i+= 1 ){
                        if( i == 0 && j == 0 ){ i= 1; }

                        // I had few problems with float, it was possible that float numbers
                        // where smaller than the actual Number and it got rounded down
                        //
                        // i did not wanted to use two indices to track the position
                        // so i needed to define a integer X which tracks the Pos
                        // x is Calculated whit module grid_Size.x
                        // and y is Calculated via division
                        if( gol_grid.Is_QuadAlivePerIndex( X% gol_grid.Get_Grid().x + i, (int)(X/ gol_grid.Get_Grid().x) + j ) ){
                            alive_Neighbors += 1;
                        }// EndIf
                    }// EndFor
                }// EndFor

                if( alive_Neighbors < 2 || alive_Neighbors > 3 ){
                    (*it).Set_Dying();
                }else if( alive_Neighbors == 3 ){
                    (*it).Set_ComingToLife();
                }// EndElseIf

            X+= 1;
            }// EndFor
        };

        ///////////////////////////////////////////////////////
        /// \brief deletes itself and Returns nullptr if p was clicked
        /// \brief else it just returns this ptr
        virtual I_GameState* HandleInput( sf::Event& event, GOL_Grid& gol_grid ){
            if( event.type == sf::Event::KeyPressed ){
                if( event.key.code == sf::Keyboard::P )
                {
                    // It's Oke to Kermit Suicide
                    delete this;
                    // returning nullptr will tell the stack to pop
                    return nullptr;
                }// EndIf
            }
            return this;
        };
};

#endif // GOL_H
