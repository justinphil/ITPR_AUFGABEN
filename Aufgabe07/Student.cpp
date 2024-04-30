//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ostream>
#include "Student.h"

/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Gibt alle Daten des Studenten in einer Zeile aus
 */
std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << student.getName() << ", MatNr. " << student.getMatNr() << ", geb. am " 
       << student.getGeburtstag() << ", wohnhaft in " << student.getAdresse();
    return os; // Return the ostream object after writing to it
}


const bool Student::operator==(const Student& student)
{
    if(matNr == student.matNr)
        return true;
    else
        return false;
}

const bool operator>(const Student& student1, const Student& student2)
{
    if(student1.getMatNr() > student2.getMatNr())
        return true;
    else
        return false;
}

const bool operator<(const Student& student1, const Student& student2)
{
    if(student1.getMatNr() < student2.getMatNr())
        return true;
    else
        return false;
}

