//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

class Liste
{
private:
    ListenElement* front;                                         // Zeiger auf das erste Listenelement
    ListenElement* back;                                         // Zeiger auf das letzte Listenelement

public:
    Liste();                                                     // Konstruktor mit Zeigerinitialisierung
    void pushBack(Student pData);
    void popFront();
    void pushFront(Student pData);
    bool empty();
    Student dataFront();
    void ausgabeVorwaerts() const;
    void ausgabeUmgekehrt() const;
    void deleteElement(int pMatNum);

};

#endif /*LISTE_H_*/
