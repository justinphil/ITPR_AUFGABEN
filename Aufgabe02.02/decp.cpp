#include <iostream>
#include <string>
#include <random>

// Function to shuffle the alphabet array
void shuffleAlphabet(std::string& alphabet) {
    std::random_device rd;
    std::mt19937 g(rd());

    for (int i = alphabet.size() - 1; i > 0; --i) {
        int j = std::uniform_int_distribution<>(0, i)(g);
        std::swap(alphabet[i], alphabet[j]);
    }
}

// Function to encrypt a string using shuffled alphabet
std::string encryptString(const std::string& input, const std::string& alphabet) {
    std::string encryptedString = input;
    for (char& c : encryptedString) {
        if (isalpha(c)) {
            char original_char = std::toupper(c);
            size_t index = original_char - 'A';
            c = alphabet[index];
        }
    }
    return encryptedString;
}

// Function to decrypt a string using shuffled alphabet
std::string decryptString(const std::string& input, const std::string& alphabet) {
    std::string decryptedString = input;
    for (char& c : decryptedString) {
        if (isalpha(c)) {
            char encrypted_char = std::toupper(c);
            size_t index = 0;
            for (size_t i = 0; i < alphabet.size(); ++i) {
                if (alphabet[i] == encrypted_char) {
                    index = i;
                    break;
                }
            }
            c = 'A' + index;
        }
    }
    return decryptedString;
}

int main() {
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    shuffleAlphabet(alphabet);

    std::string input = "Hello, World!";
    std::string encrypted = encryptString(input, alphabet);
    std::string decrypted = decryptString(encrypted, alphabet);

    std::cout << "Original: " << input << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}