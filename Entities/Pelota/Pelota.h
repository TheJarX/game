//
// Created by gerard on 19/06/19.
//

#ifndef GAME_PELOTA_H
#define GAME_PELOTA_H


class Pelota {

private:
    int x,y,vx,vy;
    float radio;
public:
//    Pelota(){}

    Pelota(float pradio, int px, int py, int pvx, int pvy):
    radio{pradio}, x{px}, y{py}, vx{pvx}, vy{pvy}
    {}

    ~Pelota();


    void colision();

    float getRadio() const;

    void setRadio(float radio);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    int getVx() const;

    void setVx(int vx);

    int getVy() const;

    void setVy(int vy);

    void moveLeft();

    void moveRight();

    void resetPosition();

    void resetSpeed(int dir);

};


#endif //GAME_PELOTA_H
