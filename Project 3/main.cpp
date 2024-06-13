#include <iostream>
using namespace std;

    float a1, b1, c1, a2, b2, c2, w, wx, wy, x, y;

    void uklad_liniowy() {

        w = a1 * b2 - a2 * b1;
        wx = c1 * b2 - c2 * b1;
        wy = a1 * c2 - a2 * c1;

    if (w != 0) {
        x = wx/w;
        y = wy/w;
        cout << "Rozwiazanie ukladu rownan: " << endl << endl;
        cout << "x = " << x << ", y = " << y << endl;

    } else if (w == 0 && wx == 0 && wy == 0){
        cout << "Uklad ma nieskonczenie wiele rozwiazan. Jest nieoznaczony." << endl;
    } else if (w == 0 && (wx != 0 || wy != 0)){
        cout << "Uklad nie ma rozwiazan. Jest sprzeczny." << endl;
    }
    }

int main() {

    cout << "Dany jest uklad rownan liniowych z dwiema niewiadomymi:\nA1x + B1y = C1\nA2x + B2y = C2" << endl;
    cout << "Podaj jego wartosci: " << endl;
    cout << "Podaj wartosc A1: " << endl;
    cin >> a1;
    cout << "Podaj wartosc B1: " << endl;
    cin >> b1;
    cout << "Podaj wartosc C1: " << endl;
    cin >> c1;
    cout << "Podaj wartosc A2: " << endl;
    cin >> a2;
    cout << "Podaj wartosc B2: " << endl;
    cin >> b2;
    cout << "Podaj wartosc C2: " << endl;
    cin >> c2;

    uklad_liniowy();

    return 0;
}