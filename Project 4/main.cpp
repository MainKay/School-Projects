#include <iostream>
#include <cctype>
using namespace std;


void wyswietl_menu() {
    cout << "To jest program, ktory wczytuje przychody osiagniete" << endl;
    cout << "przez podatnika w kolejnych miesiacach roku podatkowego," << endl;
    cout << "oraz wykonujacy na tych wartosciach operacje." << endl << endl;
    cout << "Wybierz, jaka operacje chcesz przeprowadzic: " << endl;
    cout << "[1] Wczytaj dochody" << endl;
    cout << "[2] Wyswietl dochody" << endl;
    cout << "[3] Oblicz srednia i sume dochodow" << endl;
    cout << "[4] Wyznacz dochod minimalny i maksymalny" << endl;
    cout << "[5] Uporzadkuj dochody od najmniejszego do najwiekszego" << endl;
    cout << "[6] Dochody nad i pod srednia, oraz ich suma" << endl << endl;
    cout << "[z] Zakoncz program" << endl;
}


void wczytaj_dochody(int dochody[12]) {
    cout << "Podaj dochody z kazdego kolejnego miesiaca: " << endl;

    for (int i = 0; i < 12; i++){
        cout << i + 1 << " miesiac: ";
        cin >> dochody[i];
        if (dochody[i] < 0){
            cout << "Dochody nie moga byc mniejsze niz 0!" << endl << endl;
            break;

        }
    }
}

void wyswietl_dochody(int dochody[12]) {
    bool sa_dochody = false;
    for (int i = 0; i < 12; i++) {
        if (dochody[i] > 0) {
            sa_dochody = true;
            break;
        }
    }
    if (sa_dochody) {
        cout << "Oto Twoje dochody:" << endl;
        for (int i = 0; i < 12; i++) {
            cout << "Miesiac " << i + 1 << ": " << dochody[i] << " PLN." << endl << endl;
        }
    } else {
        cout << "Brak wczytanych dochodow!" << endl << endl;
    }
}

void srednia_suma_dochodow(int dochody[12]) {
    float suma = 0;
    bool sa_dochody = false;

    for (int i = 0; i < 12; i++) {
        suma += dochody[i];
        if (dochody[i] > 0) {
            sa_dochody = true;
        }
    }

    if (sa_dochody) {
        float srednia = suma / 12;
        cout << "Suma dochodow wynosi: " << suma << " PLN." << endl;
        cout << "Sredni dochod wynosi: " << srednia << " PLN." << endl;
    } else {
        cout << "Brak wczytanych dochodow!" << endl << endl;
    }
}

void maksymalny_minimalny_dochod(int dochody[12]) {
    int max = dochody[0];
    int min = dochody[0];
    bool sa_dochody = false;

    for (int i = 1; i < 12; i++) {
        if (dochody[i] > 0) {
            sa_dochody = true;
            if (dochody[i] > max) {
                max = dochody[i];
            }
            if (dochody[i] < min) {
                min = dochody[i];
            }
        }
    }

    if (sa_dochody) {
        cout << "Maksymalny dochod wynosi: " << max << " PLN." << endl;
        cout << "Minimalny dochod wynosi: " << min << " PLN." << endl << endl;
    } else {
        cout << "Brak wczytanych dochodow!" << endl << endl;
    }
}

void sortuj(int dochody[12]) {
    bool sa_dochody = false;
    for (int i = 0; i < 12; i++) {
        if (dochody[i] > 0) {
            sa_dochody = true;
            break;
        }
    }

    if (!sa_dochody) {
        cout << "Brak wpisanych dochodow!" << endl << endl;
        return;
    }

    for (int i = 0; i < 12 - 1; i++) {
        for (int j = 0; j < 12 - i - 1; j++) {
            if (dochody[j] > dochody[j + 1]) {
                int zmienna_1 = dochody[j];
                dochody[j] = dochody[j + 1];
                dochody[j + 1] = zmienna_1;
            }
        }
    }

    cout << "Posortowane dochody:" << endl;
    for (int i = 0; i < 12; i++) {
        cout << dochody[i] << " PLN." << endl << endl;
    }
}

void pod_nad_srednim_dochodem(int dochody[12]) {
    float suma_nad = 0, suma_pod = 0;
    float srednia = 0;
    int liczba_dochodow_wiekszych = 0;
    int liczba_dochodow_mniejszych = 0;
    bool sa_dochody = false;

    for (int i = 0; i < 12; i++) {
        if (dochody[i] > 0) {
            sa_dochody = true;
            srednia += dochody[i];
        }
    }

    if (sa_dochody) {
        srednia /= 12;
        for (int i = 0; i < 12; i++) {
            if (dochody[i] > srednia) {
                suma_nad += dochody[i];
                liczba_dochodow_wiekszych++;
            } else if (dochody[i] < srednia) {
                suma_pod += dochody[i];
                liczba_dochodow_mniejszych++;
            }
        }
        cout << "Liczba dochodow wiekszych od sredniej wynosi: " << liczba_dochodow_wiekszych << endl;
        cout << "Suma dochodow wiekszych od sredniej wynosi: " << suma_nad << " PLN." << endl;
        cout << "Liczba dochodow mniejszych od sredniej wynosi: " << liczba_dochodow_mniejszych << endl;
        cout << "Suma dochodow mniejszych od sredniej wynosi: " << suma_pod << " PLN." << endl << endl;
    } else {
        cout << "Brak wczytanych dochodów!" << endl << endl;
    }
}

int main() {

    int dochody[12];
    char znak;

    do {
        wyswietl_menu();
        cin >> znak;

        switch (znak) {
            case '1' : wczytaj_dochody(dochody);
                break;
            case '2' : wyswietl_dochody(dochody);
                break;
            case '3' : srednia_suma_dochodow(dochody);
                break;
            case '4' : maksymalny_minimalny_dochod(dochody);
                break;
            case '5' : sortuj(dochody);
                break;
            case '6' : pod_nad_srednim_dochodem(dochody);
                break;

        }
    } while (tolower(znak) != 'z');


    return 0;
}