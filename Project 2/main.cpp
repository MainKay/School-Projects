#include <iostream>
#include <cmath>
using namespace std;

float a, b, c, delta, wynik1, wynik2;

void funkcja_delta() {
    delta = (b * b) - (4 * a * c);
}

void funkcja_x0() {
    if (delta == 0) {
        wynik1 = wynik2 = -b / (2 * a);
        cout << "Delta wynosi 0. x = " << wynik1 << endl;
    } else if (delta < 0) {
        cout << "Delta ujemna. Brak rozwiazania." << endl;
    }
}

void funkcja_x1_x2() {
    funkcja_delta();
    if (delta > 0) {
        wynik1 = (-b - sqrt(delta)) / (2 * a);
        wynik2 = (-b + sqrt(delta)) / (2 * a);
        cout << "Wynik to: x1 = " << wynik1 << ", x2 = " << wynik2 << endl;
    }
    funkcja_x0();
}

int main() {
    cout << "Dane jest rowananie kwadratowe: Ax^2 + Bx + C = 0.\nWprowadz dane." << endl;
    cout << "Wprowadz zmienna a: " << endl;
    cin >> a;
    cout << "Wprowadz zmienna b: " << endl;
    cin >> b;
    cout << "Wprowadz zmienna c: " << endl;
    cin >> c;

    funkcja_x1_x2();

    return 0;
}