///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

// Verschluesselt den String mittels des Feldes schluessel.
string verschluesseln(char schluessel[2][26], string wort)
{	
	string encWort = "";

	// for-loop fuer jeden Charakter im String
	for (char c : wort) {

		// Abfrage ob der Char im Alphabet gegeben ist oder nicht.
		// Wenn es gegeben ist, dann wird verschluesselt, wenn nicht, dann bleibt der Char bestehen.
		if (isalpha(c)) {
			// Konvertierung des Char in einen int um zu indexen.
			int index = toupper(c) - 'A';
			// Unterscheidung ob Grossbuchstaben oder Kleinbuchstaben verwendet werden sollen.
			if (isupper(c))
				encWort += schluessel[1][index];
			else
				encWort += schluessel[0][index];
		}
		else {
			// Wenn es kein Buchstabe ist, dann wird der Char unveraendert gespeichert.
			encWort += c;
		}
			
	}

	return encWort;
}

// Entschluesselt den eingebenen String mittels des Schluessels.
string entschluesseln(char schluessel[2][26], string wort)
{
	string decWort = wort;

	// Solange es Chars im String gibt
	for (char c : decWort) {
		
		// Ist es ein Buchstabe
		if (isalpha(c)) {

			char encChar = toupper(c);
			char offset = isupper(c) ? 'A' : 'a';
			int index = 0;

			// Suche nach Position des Chars im Schluessel
			for (int i = 0; i < 26; i++) {

				if (schluessel[1][i] == encChar) {
					index = i;
					break;
				}
			}

			// Setze entschluesselten Char
			c = offset + index;

		}
		else
			decWort += c;
	}

	return decWort;
}

// Platziert die Chars zufaellig im Feld
void shuffle(char arr[], int size) {
	
	// Gleicher Seed fuer die Laufzeit des Programms fuer Random Zahlen.
	srand(time(0));
	
	// for-Loop die durch jeden char im Feld iteriert und diese tauscht.
	for (int i = size - 1; i > 0; i--) {
		int j = rand() % (i + 1);
			char temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;	
	}
}


int main()
{
	char schluessel[2][26];
	string wort = "";

	// Fuellen der beiden Reihen, des Feldes schluessel, mit Klein-/Gro�buchstaben.
	for (int i = 0; i < 26; i++) {
		schluessel[0][i] = (char)(i + 97);
		schluessel[1][i] = (char)(i + 65);
	}

	// Zufaellige platzierung der Chars im Char-Feld.
	shuffle(schluessel[0], 26);
	shuffle(schluessel[1], 26);
	
	// Ausgabe des Feldes schluessel.
	for (int i = 0; i < 26; i++)
		cout << "(" << (char)(i + 65) << ")" << schluessel[1][i] << schluessel[0][i] << " ";
	cout << endl;
	// Eingabe eines Strings zum Verschluesseln.
	cout << "Geben Sie einen String ein, der zu verschluesseln ist: " << endl; 
	getline(cin, wort);

	// Ausgabe in die Konsole.
	cout << "Ihr Wort: " << wort << endl;
	cout << "Verschluesselt: " << verschluesseln(schluessel, wort) << endl;
	cout << "Entschluesselt: " << entschluesseln(schluessel, verschluesseln(schluessel, wort)) << endl;

	return 0;
}
