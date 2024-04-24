//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* newElement = new ListenElement(pData, nullptr);

    if (front == nullptr)
    {
        front = newElement;
        back = newElement;
    }
    else
    {
        newElement->setPrev(back);
        back->setNext(newElement);
        back = newElement;
    }
}
/**
* @brief Hinzufuegen eines Listenelements am Anfang der List
* 
* @param pData Zeiger auf ein Objek der Klasse Student
* @return void
*/
void Liste::pushFront(Student pData)
{
    ListenElement* newElement = new ListenElement(pData, nullptr);

    if (front == nullptr)
    {
        front = newElement;
        back = newElement;
    } else
    {
        newElement->setNext(front);
        front->setPrev(newElement);
        front = newElement;
    }
}


/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* temp = front;
    if (front == back)
    {
        delete front;
        front = nullptr;
        back = nullptr;
    } else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete temp;
    }
}


/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}


/**
 * @brief Loescht das Element mit der uebergebenen Matrikelnummer aus der Liste
 * @return void
 */
void Liste::deleteElement(int pMatNum)
{
    ListenElement* cursor = front;
    ListenElement* prev = nullptr;
    // Wenn die Liste leer ist, wird nichts geloescht
    if(front == nullptr)
        return; 
    
    // Schleife die die Position des Elements mit der uebergebenen Matrikelnummer findet
    while (cursor!= nullptr) {
        if (cursor->getData().getMatNr() == pMatNum) {
            prev->setNext(cursor->getNext()); // Das naechste Element wird auf das vorherige Element gesetzt
            delete cursor; // Das Element wird geloescht
            return; 
        }
        prev = cursor; // Cursor wird auf das vorherige Element gesetzt
        cursor = cursor->getNext(); // Cursor wird auf das naechste Element gesetzt
    }
    std::cout << "Element mir MatNr " << pMatNum << " wurde nicht gefunden" << std::endl;
}


/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
* @brief Funktion gibt die Liste vom letzten zum ersten Element aus
* 
* @return void
*/
void Liste::ausgabeUmgekehrt() const
{
    ListenElement* cursor = back;

    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getPrev();
    }
    std::cout << std::endl;
}
