/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

// Struktordefiniton von Person
struct Person {

    string sVorname;
    string sNachname;
    int iGebJahr;
    int iAlter;
};

int main()
{
    // Deklaration von mehreren Personen
    Person nBenutzer;
    Person nKopieGesamt;
    Person nKopieEinzeln;

    // Eingabe der Informationen in nBenutzer
    cout << "Geben Sie ihren Vornamen ein: " << endl;
    cin >> nBenutzer.sVorname;
    cout << "Geben Sie ihren Nachnamen ein: " << endl;
    cin >> nBenutzer.sNachname;
    cout << "Geben Sie ihr Geburtsjahr ein: " << endl;
    cin >> nBenutzer.iGebJahr;
    cout << "Geben Sie ihr Alter an: " << endl;
    cin >> nBenutzer.iAlter;

    // Kopie
    nKopieGesamt = nBenutzer;
    
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.iGebJahr = nBenutzer.iGebJahr;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;

    // Ausgabe in Konsole
    cout << "Sie haben angegeben: " << endl;
    cout << "Name: " + nBenutzer.sNachname + ", " + nBenutzer.sVorname << "\nAlter: " << nBenutzer.iAlter << "(" << nBenutzer.iGebJahr << ")" << endl;

    cout << "Gesamtkopie: " << endl;
    cout << "Name: " + nKopieEinzeln.sNachname + ", " + nKopieEinzeln.sVorname << "\nAlter: " << nKopieEinzeln.iAlter << "(" << nKopieEinzeln.iGebJahr << ")" << endl;

    cout << "Einzelkopie: " << endl;
    cout << "Name: " + nKopieGesamt.sNachname + ", " + nKopieGesamt.sVorname << "\nAlter: " << nKopieGesamt.iAlter << "(" << nKopieGesamt.iGebJahr << ")" << endl;

    return 0;
    
}
