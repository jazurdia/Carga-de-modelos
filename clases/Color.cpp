#include "Color.h"

// Constructor por defecto
Color::Color() : red(0), green(0), blue(0) {}

// Constructor con componentes RGB
Color::Color(int red, int green, int blue) : red(red), green(green), blue(blue) {}

// Métodos para obtener los componentes del color
int Color::getRed() const {
    return red;
}

int Color::getGreen() const {
    return green;
}

int Color::getBlue() const {
    return blue;
}

// Métodos para establecer los componentes del color
void Color::setRed(int red) {
    this->red = red;
}

void Color::setGreen(int green) {
    this->green = green;
}

void Color::setBlue(int blue) {
    this->blue = blue;
}
