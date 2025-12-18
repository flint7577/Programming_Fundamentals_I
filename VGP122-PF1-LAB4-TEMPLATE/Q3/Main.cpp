/* Write a program to count the number of vowels and consonants in a character array, using
pointers. */


#include <iostream>
using namespace std;

int main() {

	string input;

    cout << "Enter a string: ";
    getline(cin, input);

    int length = input.length();
    char* text = new char[length + 1];

    for (int i = 0; i < length; i++) {
        text[i] = input[i];
    }
    text[length] = '\0';

    int vowels = 0;
    int consonants = 0;

    char* ptr = text;

    while (*ptr != '\0') {

        char c = tolower(*ptr);

        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowels++;
            else
                consonants++;
        }

        ptr++;
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;

    delete[] text;
    return 0;
}