//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;


//
int berechnungPositionImAlphabet(int pInt) {
    int calc = pInt - 64;
    return calc;
}


int main()
{   
    {
        // Konstanter Integer iZweite
        const int iZweite = 1;

        // iFeldSize ist eine Konstante Zahl, die die Größe des Feldes iFeld bestimmt.
        const int iFeldSize = 2;
        int iFeld[iFeldSize] = {};

        // Init von Spielfeld einem 2 Dimensionalem Array
        const int iZeilen = 2;
        const int iSpalten = 3;
        int spielfeld[iZeilen][iSpalten] = { {1, 2, 3}, {4, 5 , 6} };


        // Zuweisung der Werte in iFeld
        iFeld[0] = 1;
        iFeld[1] = 2;
        
        // Ausgabe von iFeld
        for (int i = 0; i < iFeldSize; i++)
            std::cout << iFeld[i] << endl;

        // Ausgabe von spielfeld mittels for-Schleifen
        for (int i = 0; i < iZeilen; i++) {
            std::cout << "(" << i <<")";
            for (int j = 0; j < iSpalten; j++) {
                std::cout << "  " << spielfeld[i][j];
            }
            std::cout << endl;
        }
        
        // Ausgabe von const iZweite
        std::cout << "Konstante iZweite: " << iZweite << endl;
    }
    
    // Init der Variablen
    int iErste = 0;
    int iZweite = 0;
    int iSumme = 0;
    int iQuotient = 0;

    // Init von mehreren Double
    double dSumme = 0;
    double dQuotient = 0;
    double dSummeCast = 0;
    double dQuotientCast = 0;

    // init der Strings
    string sVorname = "";
    string sNachname = "";
    string sVornameName = "";
    string sNameVorname = "";

    // Init von Integern
    int iName1 = 0;
    int iName2 = 0;


    // Einlesen der Zahlen aus der Konsole
    std::cout << "Geben Sie die erste Zahl ein: " << endl;
    std::cin >> iErste;
    std::cout << "Geben Sie die zweite Zahl ein: " << endl;
    std::cin >> iZweite;

    // Einlesen von Strings aus der Konsole
    std::cout << "Geben Sie Ihren Vornamen ein: " << endl;
    std::cin >> sVorname;
    std::cout << "Geben Sie Ihren Nachnamen ein: " << endl;
    std::cin >> sNachname; 


    // Rechenoperationen als Int in Int
    iSumme = iErste + iZweite;
    iQuotient = iErste / iZweite;
    // Als Int in Double
    dSumme = iErste + iZweite;
    dQuotient = iErste / iZweite;

    // Als TypeCast in Double
    dSummeCast = (double)iErste + (double)iZweite;
    dQuotientCast = (double)iErste / (double)iZweite;

    // Zusammenführung von Strings
    sVornameName = sVorname + ", " + sNachname;
    sNameVorname = sNachname + ", " + sVorname;

    // Konvertierung zu Großbuchstaben, damit man weniger Arbeit hat.
    iName1 = toupper(sVorname[0]);    
    iName2 = toupper(sVorname[1]);


    // Ausgaben in die Konsole
    std::cout << "Integer Rechnung: " << iSumme << " und " << iQuotient << endl;
    std::cout << "Double Rechnung: " << dSumme << " und " << dQuotient << endl;
    std::cout << "TypeCast Rechnung: " << dSummeCast << " und " << dQuotientCast << endl;
    
    std::cout << "Vorname, Nachname: " << sVornameName << endl;
    std::cout << "Nachname, Vorname: " << sNameVorname << endl;

    std::cout << "Konstante iZweite " << iZweite << endl;
    std::cout << sVorname[0] + ": " << iName1 << sVorname[1] + ": " << iName2 << endl;
    std::cout << sVorname[0] << "): " << berechnungPositionImAlphabet(iName1) << endl;
    std::cout << sVorname[1] << "): " << berechnungPositionImAlphabet(iName2) << endl;
    
    return 0;
    
}
