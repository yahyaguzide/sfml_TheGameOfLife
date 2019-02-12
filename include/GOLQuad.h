#ifndef GOLQUAD_H
#define GOLQUAD_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/System/Vector2.hpp>

class GOLQuad: public sf::Drawable
{
    public:

        GOLQuad( bool Alive = false): pos( sf::Vector2f(0, 0) ), QuadSize( 10 ) {
            alive = Alive;
            dying = false;
            comingToLife = false;
            color = alive? sf::Color::Red : sf::Color::Black;

            vertices[0].position = pos;
            vertices[1].position = pos;
            vertices[2].position = pos;
            vertices[3].position = pos;

            vertices[3].position.x += QuadSize;

            vertices[1].position.y += QuadSize;

            vertices[2].position.x += QuadSize;
            vertices[2].position.y += QuadSize;

            for( int i = 0; i < 4; i+= 1)
                vertices[i].color = color;
        };
        GOLQuad( float X, float Y, bool Alive = false ): QuadSize( 10 ){
            alive = Alive;
            dying = false;
            comingToLife = false;
            color = alive? sf::Color::Red : sf::Color::Black;

            pos.x = (int)X * QuadSize;
            pos.y = (int)Y * QuadSize;

            vertices[0].position = pos;
            vertices[1].position = pos;
            vertices[2].position = pos;
            vertices[3].position = pos;

            vertices[3].position.x += QuadSize;

            vertices[1].position.y += QuadSize;

            vertices[2].position.x += QuadSize;
            vertices[2].position.y += QuadSize;

            for( int i = 0; i < 4; i+= 1)
                vertices[i].color = color;

        };
        GOLQuad( int QuadSize_, float X, float Y, bool Alive = false ){
            alive = Alive;
            dying = false;
            comingToLife = false;
            color = alive? sf::Color::Red : sf::Color::Black;

            pos.x = (int)X * QuadSize;
            pos.y = (int)Y * QuadSize;

            QuadSize = QuadSize_;

            vertices[0].position = pos;
            vertices[1].position = pos;
            vertices[2].position = pos;
            vertices[3].position = pos;

            vertices[3].position.x += QuadSize;

            vertices[1].position.y += QuadSize;

            vertices[2].position.x += QuadSize;
            vertices[2].position.y += QuadSize;

            for( int i = 0; i < 4; i+= 1)
            {
                vertices[i].color = color;
            }
        };
        virtual ~GOLQuad() = default;

        void draw( sf::RenderTarget& target, sf::RenderStates states ) const{

            target.draw(vertices, 4, sf::Quads);
        };

        int Get_QuadSize(){ return QuadSize; };

        float Get_PosX(){ return pos.x; };

        float Get_PosY(){ return pos.y; };

        bool Is_Alive(){ return alive; };
        bool Is_Dying(){ return dying; };
        bool Is_ComingToLife(){ return comingToLife; };

        void Set_Alive( bool Alive = true ){
            alive = Alive;
            color = alive? sf::Color::Red : sf::Color::Black;

//            if( alive ){
//                std::cout << "Cell at: " << pos.x << ", " << pos.y << " is alive\n";
//            }else{
//                std::cout << "Cell at: " << pos.x << ", " << pos.y << " is Dead\n";
//            }

            // Reset States
            comingToLife = false;
            dying = false;

            for( int i = 0; i < 4; i+= 1){
                vertices[i].color = color;
            }// EndFor
        };
        void Set_Dying( bool Dying = true ){
            if( alive ){
                dying = Dying;

                if( dying ){
                    vertices[1].color = sf::Color::Blue;
                    vertices[3].color = sf::Color::Blue;
                }else{
                    for( int i = 0; i < 4; i+= 1){
                        vertices[i].color = color;
                    }// EndFor
                }// EndElse
            }// ElseIf
        };
        void Set_ComingToLife( bool ComingToLife = true ){
            if( !alive ){
                comingToLife = ComingToLife;

                if( comingToLife ){
                    vertices[1].color = sf::Color::Green;
                    vertices[3].color = sf::Color::Green;
                }else{
                    for( int i = 0; i < 4; i+= 1){
                        vertices[i].color = color;
                    }// EndFor
                }// EndElse
            }// EndIf
        };

    private:
        sf::Vector2f pos;
        int QuadSize;
        bool alive;
        bool dying;
        bool comingToLife;

        sf::Color color;
        sf::Vertex vertices[4];
};

#endif // GOLQUAD_H
