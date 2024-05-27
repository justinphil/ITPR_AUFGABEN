/**
 * Praktikum Informatik 1 
 * 
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //fuer i
        std::cout <<  std::endl;
    }  //fuer j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{   

    //Ueberprueft ob posX und posY innerhalb 0 und der maximalen Groessen sind. 
    if ((posX >= 0 && posX < GROESSE_X) && (posY >= 0 && posY < GROESSE_Y))
        return true;
    else 
        return false;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // Hier erfolgt jetzt Ihre Implementierung ...
            if (j == 0 && i == 0)
                continue;

            if (!aufSpielfeld(posX + j, posY +i))
                continue;

            if (spielfeld[i + posY][j + posX] != gegner)
                continue;

            // Pruefe ob es auf einem benachbarten Feld einen eigenen Stein gibt
            int loop = 2;
            while (loop <= 7) {
                if (!aufSpielfeld(posX + loop * j, posY + loop * i))
                    break;
                if (spielfeld[posY + loop * i][posX + loop * j] == 0)
                    break;
                if (spielfeld[posY + loop * i][posX + loop * j] == aktuellerSpieler)
                    return true;
                loop++;
            }
        }
    }
    return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    // Setze den aktuellen Zug auf dem Spielfeld
    spielfeld[posY][posX] = aktuellerSpieler;
    // Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            if (i == 0 && j == 0)
                continue;

            int newPosX = posX + j;
            int newPosY = posY + i;

            // Ueberpruefe, ob das benachbarte Feld auf dem Spielfeld liegt und ein gegnerischer Stein darauf ist
            if (aufSpielfeld(newPosX, newPosY) && spielfeld[newPosY][newPosX] == gegner)
            {
                int tempX = newPosX + j;
                int tempY = newPosY + i;

                // Bewegt in die aktuelle Richtung, bis ein eigener Stein oder der Rand erreicht wird
                while (aufSpielfeld(tempX, tempY) && spielfeld[tempY][tempX] == gegner)
                {
                    tempX += j;
                    tempY += i;
                }

                // Wenn ein eigener Stein gefunden wurde, werden alle dazwischenliegenden Steine in eigene Steine umgewandelt
                if (aufSpielfeld(tempX, tempY) && spielfeld[tempY][tempX] == aktuellerSpieler)
                {
                    while (newPosX != tempX || newPosY != tempY)
                    {
                        spielfeld[newPosY][newPosX] = aktuellerSpieler;
                        newPosX += j;
                        newPosY += i;
                    }
                }
            }
        }
    }
    
}

int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    int moeglicheZuege = 0;

    // Ueberprueft ob ein Zug gueltig ist und addiert dann einen moeglichen Zug
    for (int j = 0; j < GROESSE_Y; j++) 
    {
        for (int i = 0; i < GROESSE_X; i++) 
        {
            if (spielfeld[j][i] == 0 && zugGueltig(spielfeld, aktuellerSpieler, i, j))
                moeglicheZuege++;

        }
    }

    
    return moeglicheZuege;
}


bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // Checken ob ein Zug moeglich ist 
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    // Setze das Symbol des Spielers je nachdem welcher Spieler gerade spielt
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;

        // Konvertiere die Eingabe in eine Position auf dem Spielfeld
        posX = (int) eingabe[0] % 32 - 1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //Akzeptiere Zug
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
        
    }
    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    return true;
}


void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    int runden = 0;
    bool spielerHatAusgesetzt[2] = {false, false};
    zeigeSpielfeld(spielfeld);

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Hier erfolgt jetzt Ihre Implementierung ...

    // Solange Zuege moeglich sind
    while (true)
    {
        bool zugGemacht = false;
        std::cout << "Runden: " << runden++ << std::endl;

        // Wenn der aktuelle Spieler keinen Zug moeglich hat, so setze er aus
        if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0) {
            spielerHatAusgesetzt[aktuellerSpieler - 1] = true;
            std::cout << "Spieler " << aktuellerSpieler << " hat keine gueltigen Zuege mehr und setzt aus." << std::endl;
        }
        else {
            
            if (spielerTyp[aktuellerSpieler - 1] == MENSCH)
            {
                // Menschlicher Zug
                zugGemacht = menschlicherZug(spielfeld, aktuellerSpieler);
            }
            else
            {
                // Computer Zug
                zugGemacht = computerZug(spielfeld, aktuellerSpieler);
            }
        
        }

        zeigeSpielfeld(spielfeld);
            

        if (zugGemacht || spielerHatAusgesetzt[aktuellerSpieler - 1])
        {
            // Wechsle den aktuellen Spieler
            aktuellerSpieler = (aktuellerSpieler == 1) ? 2 : 1;
        }

        // Beenden, wenn beide Spieler keine Z�ge mehr haben
        if (spielerHatAusgesetzt[0] && spielerHatAusgesetzt[1])
        {
            break;
        }
            
    }


    // Bestimmt den Gewinner des Spiels
    switch (gewinner(spielfeld))
    {
        // Hier erfolgt jetzt Ihre Implementierung ...
        case 0:
            std::cout << "Unentschieden!" << std::endl;
            break;
        case 1:
            std::cout << "Spieler 1 hat gewonnen!" << std::endl;
            break;
        case 2:
            std::cout << "Spieler 2 hat gewonnen!" << std::endl;
            break;
    }
}

int main()
{
    char weiterSpielen;
    do {
        if (TEST == 1)
        {
            bool gesamtErgebnis = ganzenTestAusfuehren();
            if (gesamtErgebnis == true)
            {
               std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
            }
            else
            {
                std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
                exit(1);
            }
            std::cout << std::endl << std::endl;
        }

        int spielerTyp[2] = { COMPUTER , COMPUTER };

        // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
        // implementiert haben (waeren sonst doppelt)
        //int spielfeld[GROESSE_Y][GROESSE_X];

	    //initialisiereSpielfeld(spielfeld);

	    //zeigeSpielfeld(spielfeld);

	    // int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
	    // spielen(spielerTyp);
	    //
	    // Hier erfolgt jetzt Ihre Implementierung ...

		//std::cout << "" << std::endl;
		char eingabe;

		std::cout << "Ist Spieler 1 ein Computer ? (j/n) " << std::endl;
        
		std::cin >> eingabe;
		if (tolower(eingabe) == 'j')
			spielerTyp[0] = COMPUTER;
		else if (tolower(eingabe) == 'n')
			spielerTyp[0] = MENSCH;
		else
			std::cout << "Ist Spieler 2 ein Computer ? (j/n) " << std::endl;
		std::cin >> eingabe;
		if (tolower(eingabe) == 'j')
			spielerTyp[1] = COMPUTER;
		else if (tolower(eingabe) == 'n')
			spielerTyp[1] = MENSCH;


		spielen(spielerTyp);
		std::cout << "Mochten Sie eine neue Partie spielen? (j/n) ";
		std::cin >> weiterSpielen;
    } while (tolower(weiterSpielen) == 'j');
    
    return 0;
}
