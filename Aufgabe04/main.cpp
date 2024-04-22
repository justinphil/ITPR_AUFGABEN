//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

const double ERDRADIUS = 6371.0; // Erdradius in Kilometern
const double AUGENHOEHE = 1.7; // Augenhoehe in Metern
const double PLATTFORMHOEHE = 555.7; // Plattformhoehe in Metern

int main()
{
    double hoehe = AUGENHOEHE + PLATTFORMHOEHE;
    double sichtweite = 0.0;
    double sichtweitePrev = 0.0;

    // Position des Beobachters als Vektor
    Vektor beobachterPosition(0.0, 0.0, ERDRADIUS + hoehe);

    do {
        sichtweitePrev = sichtweite; // Speichern der vorherigen Schaetzung 

        // Berechnung der neuen Schaetzung
        double neueHoehe = sichtweite + hoehe;
        double neueEntfernung = sqrt(2 * ERDRADIUS * neueHoehe);

        // Horizont als Vektor
        Vektor horizontPunkt(neueEntfernung, 0.0, ERDRADIUS);

        // Berechnet die Distanz zwischen dem Beobachter und dem Horizont
        Vektor distanzVektor = horizontPunkt.sub(beobachterPosition);
        sichtweite = distanzVektor.laenge();

    } while (abs(sichtweite - sichtweitePrev) > 0.0001);

    std::cout << "Sichtweite zum Horizont: " << sichtweite << " km" << std::endl;

    return 0;

}
