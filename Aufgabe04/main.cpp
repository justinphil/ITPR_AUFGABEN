//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

const double ERDRADIUS = 6371.0; // Erdradius in Metern
const double AUGENHOEHE = 1.7; // Augenhoehe in Metern
const double PLATTFORMHOEHE = 555.7; // Plattformhoehe in Metern

int main()
{
    double sichtweite = 0.0;
    double hoehe = AUGENHOEHE + PLATTFORMHOEHE;
    

    std::cout << "Die maximale Sichtweite beträgt: " << (sichtweite - 1) << " km" << std::endl;

    return 0;

}
