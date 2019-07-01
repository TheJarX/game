//
// Created by gerard on 19/06/19.
//

//#include <complex>
#include<stdlib.h>
#include "Pelota.h"


Pelota::~Pelota() {

    radio = 0;
    x = 0;
    y = 0;
    vx = 0;
    vy = 0;


}

float Pelota::getRadio() const {
    return radio;
}

void Pelota::setRadio(float radio) {
    Pelota::radio = radio;
}

int Pelota::getX() const {
    return x;
}

void Pelota::setX(int x) {
    Pelota::x = x;
}

int Pelota::getY() const {
    return y;
}

void Pelota::setY(int y) {
    Pelota::y = y;
}

int Pelota::getVx() const {
    return vx;
}

void Pelota::setVx(int vx) {
    Pelota::vx = vx;
}

int Pelota::getVy() const {
    return vy;
}

void Pelota::setVy(int vy) {
    Pelota::vy = vy;
}



void Pelota::colision() {

    Pelota::setVx(0);
    Pelota::setVy(0);
}

void Pelota::moveLeft() {

    int vx = Pelota::getVx();

    Pelota::setVx( -vx );

}

void Pelota::moveRight() {

    int vx = Pelota::getVx();

    Pelota::setVx( abs(vx) );

}

void Pelota::resetPosition() {

    Pelota::setY(270);
    Pelota::setX(400);

}

void Pelota::resetSpeed(int dir){

    Pelota::setVy(5);
    Pelota::setVx(5);


}


