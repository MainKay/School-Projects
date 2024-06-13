#include <iostream>
#include <limits>
using namespace std;

float gora, dol, liczba;

float czytaj_liczbe_z_zakresu() {
    cout << "Podaj zakres w ktorym ma sie znalezc Twoja liczba: " << endl << endl;
    cout << "Zakres gorny liczby: " << endl;
    cin >> gora;
    cout << "Zakres dolny liczby: " << endl;
    cin >> dol;

    while (gora <= dol) {
        cout << "Wprowadzono bledny zakres. Wprowadz zakres jeszcze raz." << endl << endl;
        cout << "Zakres gorny liczby: " << endl;
        cin >> gora;
        cout << "Zakres dolny liczby: " << endl;
        cin >> dol;
    }

    cout << "Podaj liczbe z wybranego zakresu: ";

    while (!(cin >> liczba)) {
        cout << "Bledne dane! Podaj liczbe calkowita." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wprowadz liczbe z wybranego zakresu: ";
    }

    while (liczba < dol || liczba > gora) {
        cout << "Liczba spoza zakresu, podaj inna liczbe: ";
        cin >> liczba;
    }

    cout << "Twoja liczba to: " << liczba << "." << endl;

    return liczba;
}

int main() {
    czytaj_liczbe_z_zakresu();
    return 0;
}