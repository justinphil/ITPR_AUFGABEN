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
    double winkelZumHorizont = 0.0;
    int schritte = 0;

    // Position des Beobachters als Vektor
    Vektor beobachterPosition(0.0, ERDRADIUS + hoehe, 0.0);

    do {
        schritte++;
        sichtweitePrev = sichtweite; // Speichere die vorherige Schätzung

        // Berechne die neue Sichtweite
        double neueHoehe = sichtweite + hoehe;
        double neueEntfernung = sqrt(pow((ERDRADIUS + neueHoehe), 2) - pow(ERDRADIUS, 2));

        // Erstelle den Vektor für den Horizontpunkt
        Vektor horizontPunkt(neueEntfernung, ERDRADIUS, 0.0);

        // Berechne die Distanz zwischen dem Beobachter und dem Horizontpunkt
        Vektor distanzVektor = horizontPunkt.sub(beobachterPosition);
        sichtweite = distanzVektor.laenge();
        
        /*distanzVektor.ausgabe();
        std::cout << abs(sichtweite - sichtweitePrev) << std::endl;*/

        winkelZumHorizont = acos(ERDRADIUS / (ERDRADIUS + hoehe));

    } while (abs(sichtweite - sichtweitePrev) > 0.0001);

    std::cout << "Sie koennen " << sichtweite << " Km weit sehen." << std::endl;
    std::cout << "Sie sind " << hoehe << " Meter hoch." << std::endl;
    std::cout << "Der Winkel betraegt " << winkelZumHorizont * 180 / 3.141561<< " Grad." << std::endl;
    std::cout << "Anzahl Schritte: " << schritte << std::endl;



    return 0;

}
