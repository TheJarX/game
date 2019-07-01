//
// Created by gerard on 20/06/19.
//

#include "Jugador.h"

int Jugador::getScore() const {
    return score;
}

void Jugador::setScore(int score) {
    Jugador::score = score;
}

int Jugador::getHeight() const {
    return height;
}

void Jugador::setHeight(int height) {
    Jugador::height = height;
}

int Jugador::getWidth() const {
    return width;
}

void Jugador::setWidth(int width) {
    Jugador::width = width;
}

int Jugador::getX() const {
    return x;
}



int Jugador::getY() const {
    return y;
}

void Jugador::setY(int y) {
    Jugador::y = y;
}

int Jugador::getVy() const {
    return vy;
}

void Jugador::setVy(int vy) {
    Jugador::vy = vy;
}

void Jugador::resetScore() {

    Jugador::setScore(0);

}

void Jugador::resetPosition() {

    Jugador::setY(270);

}
