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
    
    double sProduct = skalarProd(input);
    double l1 = laenge();
    double l2 = input.laenge();
    double cosine = sProduct / (l1 / l2);
    double winkelInRad = std::acos(cosine);
    return winkelInRad * 180 / pi; // Umrechnung in Grad 
}

/*
* @brief Function rotates the vector around the z-Axis 
*/
void Vektor::rotiereUmZ(const double rad)  
{
    double cosWinkel = std::cos(rad);
    double sinWinkel = std::sin(rad);

    double newX = x * cosWinkel - y * sinWinkel;
    double newY = x * sinWinkel + y * cosWinkel;
    double newZ = z;

    x = newX;
    y = newY;
    z = newZ;

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
