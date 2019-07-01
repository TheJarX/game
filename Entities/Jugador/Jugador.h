//
// Created by gerard on 20/06/19.
//

#ifndef GAME_JUGADOR_H
#define GAME_JUGADOR_H


class Jugador {

private:
    int score, height, width, x, y, vx, vy;

public:
    Jugador(int score, int height, int width, int x, int y, int vy):
        score{score}, height{height}, width{width}, x{x}, y{y}, vy{vy}
        {}

    int getScore() const;

    void setScore(int score);

    int getHeight() const;

    void setHeight(int height);

    int getWidth() const;

    void setWidth(int width);

    int getX() const;

    int getY() const;

    void setY(int y);

    int getVy() const;

    void setVy(int vy);

    void resetScore();

    void resetPosition();
};


#endif //GAME_JUGADOR_H
