#ifndef GOL_GRID_H
#define GOL_GRID_H

#include <vector>

#include <SFML/System/Vector2.hpp>

#include <GOLQuad.h>

class GOL_Grid
{
    public:
        typedef std::vector< GOLQuad > GOLQuad_vec;

        GOL_Grid( int x = 400, int y = 400, int QuadSIZE = 10 ){
            grid.x = x / QuadSIZE;
            grid.y = y / QuadSIZE;
            QuadSize = QuadSIZE;

            golquad_vec.reserve( grid.x * grid.y );

            for( int j = 0; j < grid.y; j+= 1 ){
                for( int i = 0; i < grid.x; i+= 1 ){
                    golquad_vec.push_back( GOLQuad( QuadSIZE , i, j ) );
                }
            }
        };
        virtual ~GOL_Grid() = default;

        ///////////////////////////////////////////////////////
        /// \brief Returns the Size of one Quad
        int Get_QuadSize(){ return QuadSize; };

        ///////////////////////////////////////////////////////
        /// \brief accepts a Vector2i ref and a GOLQuad_vec ref
        /// \brief GOLQuad_vec is a vector which holds GOLQauds
        /// \see typedef GOLQuad_vec
        void Set_Grid( sf::Vector2i& _grid, GOLQuad_vec& vec ){
            grid = _grid;
            golquad_vec = vec;
        };

        ///////////////////////////////////////////////
        /// \brief returns sf::vector2i which holds the
        /// \brief Dimensions of the Grid
        /// \see Set_Grid
        sf::Vector2i& Get_Grid(){ return grid; };

        ////////////////////////////////////////////////
        /// \brief returns a ref to Vector holding Quads
        /// \see Set_Grid
        GOLQuad_vec& Get_GolVec(){ return golquad_vec; };

        //////////////////////////////////////////////
        /// \brief inverts the Alive State of the Quad
        void Invert_QuadAlive( int x, int y ){
            x = x / QuadSize;
            y = y / QuadSize;
            if( x > 0 && x < grid.x ){
                if( y > 0 && y < grid.y ){
                    golquad_vec[x + grid.x * y].Set_Alive( !golquad_vec[x + grid.x * y].Is_Alive() );
                }// EndIf
            }// EndIf
        };
        void Invert_QuadAlive( sf::Vector2i vec ){
            vec.x = vec.x / QuadSize;
            vec.y = vec.y / QuadSize;
            if( vec.x > 0 && vec.x < grid.x ){
                if( vec.y > 0 && vec.y < grid.y ){
                    golquad_vec[vec.x + grid.x * vec.y].Set_Alive( !golquad_vec[vec.x + grid.x * vec.y].Is_Alive() );
                }// EndIf
            }// EndIf
        };

        ///////////////////////////////////////////////////////
        /// \brief Returns true if Quad is Alive in the moment
        /// \brief if the coordinates given are out of range
        /// \brief return simply false
        /// \brief accepts Coords as Pixels
        bool Is_QuadAlive( int x, int y ){
            x = x / QuadSize;
            y = y / QuadSize;
            if( x > 0 && x < grid.x ){
                if( y > 0 && y < grid.y ){
                    return golquad_vec[x + grid.x * y].Is_Alive();
                }// EndIf
            }// EndIf
            return false;
        };
        bool Is_QuadAlive( sf::Vector2i vec ){
            vec.x = vec.x / QuadSize;
            vec.y = vec.y / QuadSize;
            if( vec.x > 0 && vec.x < grid.x ){
                if( vec.y > 0 && vec.y < grid.y ){
                    return golquad_vec[vec.x + grid.x * vec.y].Is_Alive();
                }// EndIf
            }// EndIf
            return false;
        };

        //////////////////////////////////////////////////////
        /// \brief Returns true if Quad is Alive in the moment
        /// \brief if the coordinates given are out of range
        /// \brief return simply false
        /// \brief accepts Coords as Vector Index
        bool Is_QuadAlivePerIndex( int x, int y ){
            if( x > 0 && x < grid.x ){
                if( y > 0 && y < grid.y ){
                    return golquad_vec[x + grid.x * y].Is_Alive();
                }// EndIf
            }// EndIf
            return false;
        };
        bool Is_QuadAlivePerIndex( sf::Vector2i vec ){
            if( vec.x > 0 && vec.x < grid.x ){
                if( vec.y > 0 && vec.y < grid.y ){
                    return golquad_vec[vec.x + grid.x * vec.y].Is_Alive();
                }// EndIf
            }// EndIf
            return false;
        };

        //////////////////////////////////////////////
        /// \brief Inverts the Dying State of the Quad
        void Invert_QuadDying( int x, int y ){
            x = x / QuadSize;
            y = y / QuadSize;
            if( x > 0 && x < grid.x ){
                if( y > 0 && y < grid.y ){
                    golquad_vec[x + grid.x * y].Set_Dying( !golquad_vec[x + grid.x * y].Is_Dying() );
                }// EndIf
            }// EndIf
        };
        void Invert_QuadDying( sf::Vector2i vec ){
            vec.x = vec.x / QuadSize;
            vec.y = vec.y / QuadSize;
            if( vec.x > 0 && vec.x < grid.x ){
                if( vec.y > 0 && vec.y < grid.y ){
                    golquad_vec[vec.x + grid.x * vec.y].Set_Dying( !golquad_vec[vec.x + grid.x * vec.y].Is_Dying() );
                }// EndIf
            }// EndIf
        };

        //////////////////////////////////////////////////////
        /// \brief Returns true if Quad is Dying in the moment
        /// \brief if the coordinates given are out of range
        /// \brief return simply false
        bool Is_QuadDying( int x, int y ){
            x = x / QuadSize;
            y = y / QuadSize;
            if( x > 0 && x < grid.x ){
                if( y > 0 && y < grid.y ){
                    return golquad_vec[x + grid.x * y].Is_Dying();
                }// EndIf
            }// EndIf
            return false;
        };
        bool Is_QuadDying( sf::Vector2i vec ){
            vec.x = vec.x / QuadSize;
            vec.y = vec.y / QuadSize;
            if( vec.x > 0 && vec.x < grid.x ){
                if( vec.y > 0 && vec.y < grid.y ){
                    return golquad_vec[vec.x + grid.x * vec.y].Is_Dying();
                }// EndIf
            }// EndIf
            return false;
        };

        /////////////////////////////////////////////////////
        /// \brief Inverts the ComingToLife State of the Quad
        void Invert_QuadComingToLife( int x, int y ){
            x = x / QuadSize;
            y = y / QuadSize;
            if( x > 0 && x < grid.x ){
                if( y > 0 && y < grid.y ){
                    golquad_vec[x + grid.x * y].Set_ComingToLife( !golquad_vec[x + grid.x * y].Is_ComingToLife() );
                }// EndIf
            }// EndIf
        };
        void Invert_QuadComingToLife( sf::Vector2i vec ){
            vec.x = vec.x / QuadSize;
            vec.y = vec.y / QuadSize;
            if( vec.x > 0 && vec.x < grid.x ){
                if( vec.y > 0 && vec.y < grid.y ){
                    golquad_vec[vec.x + grid.x * vec.y].Set_ComingToLife( !golquad_vec[vec.x + grid.x * vec.y].Is_ComingToLife() );
                }// EndIf
            }// EndIf
        };

        ///////////////////////////////////////////////////////////////
        /// \brief Returns true if Quad is coming to Life in the moment
        /// \brief if the coordinates given are out of range
        /// \brief return simply false
        bool Is_QuadComingToLife( int x, int y ){
            x = x / QuadSize;
            y = y / QuadSize;
            if( x > 0 && x < grid.x ){
                if( y > 0 && y < grid.y ){
                    return golquad_vec[x + grid.x * y].Is_ComingToLife();
                }// EndIf
            }// EndIf
            return false;
        };
        bool Is_QuadComingToLife( sf::Vector2i vec ){
            vec.x = vec.x / QuadSize;
            vec.y = vec.y / QuadSize;
            if( vec.x > 0 && vec.x < grid.x ){
                if( vec.y > 0 && vec.y < grid.y ){
                    return golquad_vec[vec.x + grid.x * vec.y].Is_ComingToLife();
                }// EndIf
            }// EndIf
            return false;
        };

    private:
        int QuadSize;
        GOLQuad_vec golquad_vec;
        sf::Vector2i grid;

};

#endif // GOL_GRID_H
