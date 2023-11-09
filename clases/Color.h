#ifndef COLOR_H
#define COLOR_H

class Color {
public:
    // Constructores
    Color(); // Constructor por defecto, color negro
    Color(int red, int green, int blue); // Constructor con componentes RGB

    // Métodos para obtener los componentes del color
    int getRed() const;
    int getGreen() const;
    int getBlue() const;

    // Métodos para establecer los componentes del color
    void setRed(int red);
    void setGreen(int green);
    void setBlue(int blue);

private:
    int red;
    int green;
    int blue;
};

#endif // COLOR_H
