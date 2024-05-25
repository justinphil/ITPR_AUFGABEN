//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

// Zahl bis zu welcher die Fibonacci Sequenz berechnet werden soll.
int iNumberRec = 47, iNumberIterative = 47;


// Berechnung der Fibonacci Zahl, mittels Rekursion
int fibonacciRec(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }

    else {
        return fibonacciRec(n-1) + fibonacciRec(n-2);
    }

}

// Berechnung der Fibonacci Zahl, mittels Iteration
int fibIterative(int n) {
    int prevFib = 1, currentFib = 0, newFib;
    if (n == 0)
        return 0;
    else if (n == 1)
        return currentFib;

    for (int i = 1; i <= n; i++) {
        newFib = prevFib + currentFib;
        prevFib = currentFib;
        currentFib = newFib;
    }
    return currentFib;
}

int main ()
{
    // Ausgabe der Fibonacci Zahlen mittels Rekursion
    std::cout << " (Rekursiv) Fibonacci - Zahlen von 0 bis " << iNumberRec << ":" << std::endl ;
    for (int i = 0; i <= iNumberRec ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacciRec(i) << std::endl ;
    }
    // Ausgabe der Fibonacci Zahlen mittels Iteration
    std::cout << "(Iterativ) Fibonacci - Zahlen von 0 bis " << iNumberIterative << ":" << std::endl;
    std::cout << fibIterative(iNumberIterative) << std::endl;


    return 0;
}
