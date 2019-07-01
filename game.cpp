#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <future>
#include "Entities/Pelota/Pelota.h"
#include "Entities/Jugador/Jugador.h"

bool setTimeout(int i);

using namespace std;
using namespace sf;
//void setTimeout();
int main()
{

    srand(time(NULL));

    int dir = rand()%2;

    Pelota pelota(10.f,400,260,5,5);
    Jugador jugador1(0,100,20,10,270,7);
    Jugador jugador2(0,100,20,770,270,7);

    int ext_der = 800;
    int ext_izq = 0;
    int ext_sup = 0;
    int ext_inf = 600;

    int x,y,vx, vy, ny;
    int jugador1_y, jugador2_y, jugador1_score, jugador2_score;

    float radio = pelota.getRadio();

    bool stopped = false;


    RenderWindow window(VideoMode(ext_der, ext_inf), "PONG",Style::Titlebar | Style::Close );

    CircleShape ball(radio);
    ball.setFillColor(Color::Yellow);
    Font forwardFont;

    forwardFont.loadFromFile("/home/gerard/game/fff_forward.ttf");


    RectangleShape player1( Vector2f( jugador1.getWidth(), jugador1.getHeight() ) );
    player1.setFillColor(Color::White);

    RectangleShape player2( Vector2f( jugador2.getWidth(), jugador2.getHeight() ) );
    player2.setFillColor(Color::White);

    while (window.isOpen())
    {
        x = pelota.getX();
        y = pelota.getY();


        jugador1_y = jugador1.getY();
        jugador2_y = jugador2.getY();

        jugador1_score = jugador1.getScore();
        jugador2_score = jugador2.getScore();

        string str_score = to_string(jugador1_score) + " : " + to_string(jugador2_score);
        Text score(str_score, forwardFont, 50);

        string winner = jugador1_score>=5?"Jugador 1":"Jugador 2";
        Text win_title(winner + " gana!",forwardFont, 50);

        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }


        window.clear(Color::Black);



        /**
         * Condicionales para el control de los jugadores
         * */
        if (Keyboard::isKeyPressed(Keyboard::W) && jugador1_y >= ext_sup )
        {
            ny = jugador1.getVy();

            jugador1.setY((jugador1_y + (-ny)));
        }

        if (Keyboard::isKeyPressed(Keyboard::S) && (jugador1.getY()+jugador1.getHeight()) <= ext_inf)
        {
            ny = jugador1.getVy();

            jugador1.setY( abs(jugador1_y) + ny );
        }

        if (Keyboard::isKeyPressed(Keyboard::Up) && jugador2_y >= ext_sup )
        {
            ny = jugador2.getVy();

            jugador2.setY((jugador2_y + (-ny)));
        }

        if (Keyboard::isKeyPressed(Keyboard::Down) && (jugador2.getY()+jugador2.getHeight()) <= ext_inf)
        {
             ny = jugador2.getVy();

            jugador2.setY( abs(jugador2_y) + ny );
        }

        /**
         * Condicionales para el comportamiento de la pelota
         * */

        if (x <= ext_izq  )
        {
            if( ( pelota.getX() - jugador1.getX() )<= 0
                && ( (pelota.getY() <= jugador1.getY() + jugador1.getHeight())
                        && pelota.getY() >= jugador1.getY() ) ){

                    pelota.moveRight();


            }else{
                    pelota.colision();


                    if(!stopped && jugador2_score<5){

                        jugador2.setScore( jugador2.getScore() + 1  );

                    }

                    stopped = true;


            }

        }


        if (x >= ext_der - ( pelota.getRadio() * 2 ) )
        {
            if( ( jugador1.getX() - pelota.getX() )<=0
                &&  ( (pelota.getY() <= jugador2.getY() + jugador2.getHeight())
                      && pelota.getY() >= jugador2.getY() ) ){

                    pelota.moveLeft();

            }else{
                pelota.colision();


                if(!stopped && jugador1_score<5){

                jugador1.setScore( jugador1.getScore() + 1  );

                }

                stopped = true;

            }

        }

        if ( y <= ext_sup)
        {
            ball.setFillColor(Color::Yellow);
            vy = pelota.getVy();

            pelota.setVy( abs(vy) );
        }

        if ( y >= ext_inf - (pelota.getRadio() * 2))
        {
            ball.setFillColor(Color::Yellow);
            vy = pelota.getVy();
            pelota.setVy( -vy );
        }

        x += pelota.getVx();
        y += pelota.getVy();

          pelota.setX( x );
          pelota.setY( y );

            if(Keyboard::isKeyPressed(Keyboard::R))
            {
                pelota.resetPosition();
                pelota.resetSpeed(0);
                stopped = false;
            }

            if(Keyboard::isKeyPressed(Keyboard::N))
            {
                jugador1.resetScore();
                jugador2.resetScore();

                jugador1.resetPosition();
                jugador2.resetPosition();
            }


        player1.setPosition( jugador1.getX(), jugador1_y);
        player2.setPosition( jugador2.getX(), jugador2.getY() );


        score.setPosition(340,30);

        win_title.setPosition(160, 200);

        if((jugador1_score>=5 || jugador2_score>=5) ){

            window.draw(win_title);


        }

        if(!stopped && (jugador1_score<5 && jugador2_score < 5))
        {
        ball.setPosition( pelota.getX(), pelota.getY());
                window.draw(ball);
        }
        window.draw(score);
        window.draw(player1);
        window.draw(player2);

        window.display();
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(240);

    }

    return 0;


}


