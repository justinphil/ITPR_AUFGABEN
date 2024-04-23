//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

const double pi = 3.14159265359;

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/*
* @brief Function returns the value of the vector
*/
double Vektor::laenge() const{
    double quadratSumme = x * x + y * y + z * z;
    return std::sqrt(quadratSumme);
}
/*
* @brief Function subtracting another Vector from this one.
*/
Vektor Vektor::sub(const Vektor& input) const {
    double newX = x - input.x;
    double newY = y - input.y;
    double newZ = z - input.z;

    return Vektor(newX, newY, newZ);
}

/*
* @brief Function that returns the scalarproduct / dot product.
*/
double Vektor::skalarProd(const Vektor& input) const {
    double ergebnis = x * input.x + y * input.y + z * input.z;
    return ergebnis;
}

/*
* @brief Function returns the angle of the vector int relation to another
*/
double Vektor::winkel(const Vektor& input) const {
    double cosine = skalarProd(input) / (this->laenge() / input.laenge());
    double winkel = acos(cosine) * 180/pi; // Umrechnung in Grad 
    return winkel; 
}

/*
* @brief Function rotates the vector around the z-Axis 
*/
void Vektor::rotiereUmZ(const double rad)  
{

    double newX = x * cos(rad) - y * sin(rad);
    double newY = x * sin(rad) + y * cos(rad);

    x = newX;
    y = newY;
}


/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}
