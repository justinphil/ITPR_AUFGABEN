//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    const friend std::ostream operator << (std::ostream& os, const Student& student);
    const bool operator == (const Student& student);
    const friend bool operator > (const Student& student1, const Student& student2);
    const friend bool operator < (const Student& student1, const Student& student2);


private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

#endif
