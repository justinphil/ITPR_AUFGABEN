/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include "Student.h"

std::ofstream ofStream("Studenten.txt");
std::ifstream ifStream;

void sortiereStudenten(std::vector<Student>& studentenliste, const char& order) {
    switch(order) {
    case 'a':
        std::sort(studentenliste.begin(), studentenliste.end());
        break;

    case'd':
        std::sort(studentenliste.begin(), studentenliste.end(),  std::greater<Student>());
        break;

    default:
        std::cout << "Fehler bei der Eingabe. " << std::endl;
        break;

    }


}

/**
* @brief Schreibt die Daten von Studenten in den FileStream
* @param ausgabe outFileStream
* @param student Student
*/
void writeToFile(std::ostream& ausgabe, const Student& student) {
    ausgabe << student << std::endl;
}
/**
* @brief Speichert den Vektor Studentenliste 
* @param dateiName Name der Datei
* @param studentenListe Vektor 
*/
void saveToFile(const std::string& dateiName, const std::vector<Student>& studentenListe) {
    ofStream.open(dateiName);
    if (!ofStream) {
        std::cerr << "Fehler beim Öffnen der Datei '" << dateiName << "'." << std::endl;
        return;
    }

    for (const auto& student : studentenListe) {
        std::cout << student << std::endl;
    }

    ofStream.close();
    std::cout << "Daten erfolgreich in die Datei '" << dateiName << "' gespeichert." << std::endl;

}

int main()
{
    std::vector<Student> studentenListe;
    Student student;

    char abfrage;
    /*std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');*/

    /*if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
        studentenListe.push_back(student);
    }*/

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
                  << "(5): Datenelement loeschen" << std::endl
                  << "(6): Datenelement vorne hinzufuegen" << std::endl
                  << "(7): Daten aus einer Datei einlesen" << std::endl
                  << "(8): Daten in eine Datei sichern" << std::endl
                  << "(9): Datenbank sortieren" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.front();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        std::cout << student << std::endl;
                        studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                {
                    if(!studentenListe.empty())
                    {
                        std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                        for(const auto &student : studentenListe) {
                            std::cout << student;
                        }
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n\n";
                    }  
                }
                break;
            
            // Datenbank rueckwaerts ausgeben
            case '4':
                {
                    if (!studentenListe.empty())
                    {
                        std::cout << "Inhalt der Liste in ruecklaufender Reihenfolge:" << std::endl;
                        for (auto student = studentenListe.rbegin(); student != studentenListe.rend(); student++)
                            std::cout << *student;
                        
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n\n";
                    }
                }
                break;

            // Datenelement mit gegebener Matrikelnummer loeschen
            case '5':
                {
                    unsigned int matNr = 0;
                    std::cout << "Bitte geben Sie die Matrikelnummer ein: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    if(!studentenListe.empty())
                    {
                        std::cout << "Lösche Datenelement mit der Matrikelnummer: " << matNr << std::endl;
                        
                        auto student = std::find(studentenListe.begin(), studentenListe.end(), [&matNr](const Student& s) { 
                            return s.getMatNr() == matNr;
                        });
                        std::cout << "Der zu loeschende Student ist: " << *student << std::endl;
                        
                        studentenListe.erase(student);
                        
                        for(const auto &student : studentenListe) {
                            std::cout << student;
                        }

                    } else 
                    {
                        std::cout << "Die Liste ist leer!\n\n";
                    }
                }
                break;

            // Datenelement vorne hinzufuegen 
            case '6':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);
                    if(!studentenListe.empty())
                        studentenListe.insert(studentenListe.begin(), student);
                }
                break;
            
            // Daten aus einer Datei einlesen
            case '7':
                {                   
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::string dateiName = "studenten.txt";
                    
                    if (!studentenListe.empty()) {
                        studentenListe.clear();
                    }

                    std::cout << "Geben Sie den Namen der Datei ein (Mit Dateiendung): " << std::endl;
                    std::getline(std::cin, dateiName);

                    ifStream.open(dateiName);

                    // Datei oeffnen
                    if (ifStream.is_open()) {
                        std::string line; // Linie in der Datei
                        while (std::getline(ifStream, line)) { // Gehe durch die Datei solange es noch Linien gibt
                            if (!line.empty()) { // Wenn die Linie nicht leer ist

                                matNr = std::stoul(line); // Matrikelnummer
                                std::getline(ifStream, line); // Linie lesen
                                name = line; // Name
                                std::getline(ifStream, line); // Naechste Linie lesen
                                geburtstag = line; // Geburtstag
                                std::getline(ifStream, line); // Naechste Linie
                                adresse = line; // Adresse
                                
                                Student student(matNr, name, geburtstag, adresse); // Student anlegen
                                studentenListe.push_back(student); // Student in den Vector eingeben
                            }
                        }
                        ifStream.close();
                        std::cout << "Daten aus der Datei eingelesen." << std::endl;               
                    }
                    else 
                        std::cout << "Fehler beim oeffnen der Datei." << std::endl;
                    
                }
                break;

            // Daten in eine Datei sichern
            case '8':
                {
                    std::string dateiName = "studenten";
                    char overwrite = 'n';

                    if (!studentenListe.empty()) {
                        std::cout << "Geben Sie den Namen der Datei ein (ohne Dateieindung): " << std::endl;
                        std::cin >> dateiName;
                            
                        ifStream.open(dateiName + ".txt");

                            if (ifStream.good()) {
                                std::cout << "Die Datei '" << dateiName << ".txt' existiert bereits. Moechten Sie sie ueberschreiben? (j/n) ";
                                std::cin >> overwrite;

                                if (tolower(overwrite) == 'j')
                                {
                                    saveToFile(dateiName + ".txt", studentenListe); 
                                }
                                else
                                    std::cout << "Datei wurde nicht gespeichert." << std::endl;
                            }
                            else {
                                saveToFile(dateiName + ".txt", studentenListe);                           
                            }

                        ifStream.close();
                        
                        }

                    else
                        std::cout << "Die Datenbank ist leer, es gibt nichts zum speichern." << std::endl;

                }
                break;
            // Datenbank Sortieren
            case '9':
                {
                    std::cout << "Wie soll die Datendank sortiert werden? (a, d)" << std::endl;
                    char eingabe = std::cin.get();
                    sortiereStudenten(studentenListe, tolower(eingabe));
                    std::cout << "Datenbank wurde sortiert." << std::endl;
                }
                break;


            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
