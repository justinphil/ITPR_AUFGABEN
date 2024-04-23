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

const double PI = 3.14159265;

int main()
{
    Vektor erde(0, ERDRADIUS, 0); // Stellt den Erdradius als Vektor dar
    Vektor beobachter(0,ERDRADIUS + ((AUGENHOEHE + PLATTFORMHOEHE) / 1000 ), 0); // Stellt die Position des Beobachters als Vektor dar.
    Vektor sicht = beobachter.sub(erde); // Stellt die Sichtweite dar. Differenz zwischen Erde und Beobachter

    double winkel = 0;
    int iterationen = 0;

    do {
        winkel += 0.0000000000000001; // Winkel inkrementieren
        erde.rotiereUmZ(winkel * PI * 180); // Rotation des Erdvektors
        sicht = erde.sub(beobachter); // Berechnung der Sichtweite
        iterationen++;

    } while (erde.skalarProd(sicht) >= 0); // Solange bis die Vektoren orthogonal zueinander sind.
    
    double beta = beobachter.winkel(erde);

    //Ausgabe in die Konsole
    std::cout << "Sie koennen " << sicht.laenge() << std::setprecision(4) <<" KM weit sehen." << std::endl;
    std::cout << "Sie sind " << AUGENHOEHE+PLATTFORMHOEHE << std::setprecision(4) <<" Meter hoch." << std::endl;
    std::cout << "Der Winkel betraegt " << beta << " Grad." << std::endl;
    std::cout << "Anzahl Schritte: " << iterationen << std::endl;



    return 0;

}
