#include <iostream>
#include <string>
using namespace std;

struct ksiazka {
    char tytul[80];
    char autor[80];
    int liczbaStron;
    bool wypozyczona;
    bool rekordSkasowany;
};

void Menu(){
    cout << "To jest program gromadzacy dane o ksiazkach. Wybierz opcje: " << endl;
    cout << "[1] - Dodaj ksiazke\n[2] - Edytuj ksiazke\n[3] - Usun ksiazke\n[4] - Wypozycz ksiazke" << endl;
    cout << "[5] - Zwroc ksiazke\n[6] - Wyswietl wszystkie ksiazki\n[7] - Wyswietl tylko ksiazki wypozyczone" << endl << endl;
    cout << "[z] - Zakoncz program" << endl << endl;
}

void Wyswietl_Ksiazki(ksiazka ksiazki[], int licz){
    if (licz < 1) {
        cout << endl << "Najpierw wprowadz ksiazke!" << endl << endl;
    } else {
        cout << "Oto zapisane ksiazki:" << endl << endl;
        for (int i = 0; i < licz; i++) {
            cout << "Ksiazka numer [" << i+1 << "]: " << ksiazki[i].tytul << (ksiazki[i].wypozyczona ? " (Wypozyczona)" : "") << endl << endl;
        }
    }
}

void Edytuj_Ksiazke(ksiazka ksiazki[], int k){
    cout << "Podaj nowy tytul ksiazki: " << endl;
    cin.ignore();
    cin.getline(ksiazki[k].tytul, 80);

    cout << "Podaj nowego autora: " << endl;
    cin.getline(ksiazki[k].autor, 80);

    cout << "Podaj nowa ilosc stron: " << endl;
    cin >> ksiazki[k].liczbaStron;
}

void Usun_Ksiazke(ksiazka ksiazki[], int &liczba, int k) {
    for (int i = k - 1; i < liczba - 1; ++i) {
        ksiazki[i] = ksiazki[i + 1];
    }
    liczba--;
}

void Wypozycz_Ksiazke(ksiazka ksiazki[], int k) {
    if (!ksiazki[k].wypozyczona) {
        ksiazki[k].wypozyczona = true;
        cout << "Ksiazka " << ksiazki[k].tytul << " zostala wypozyczona." << endl;
    } else {
        cout << "Ksiazka " << ksiazki[k].tytul << " jest juz wypozyczona." << endl;
    }
}

void Zwroc_Ksiazke(ksiazka ksiazki[], int k) {
    if (ksiazki[k].wypozyczona) {
        ksiazki[k].wypozyczona = false;
        cout << "Ksiazka " << ksiazki[k].tytul << " zostala zwrocona." << endl;
    } else {
        cout << "Ksiazka " << ksiazki[k].tytul << " nie jest wypozyczona." << endl;
    }
}

void Wyswietl_Wypozyczone_Ksiazki(ksiazka ksiazki[], int licz) {
    if (licz < 1) {
        cout << endl << "Najpierw wprowadz ksiazke!" << endl << endl;
    } else {
    cout << "Wypozyczone ksiazki:" << endl << endl;
    for (int i = 0; i < licz; i++) {
        if (ksiazki[i].wypozyczona) {
            cout << "Ksiazka numer [" << i + 1 << "]: " << ksiazki[i].tytul << endl << endl;
        }
        }
    }
}

int main()
{
    char wybor, z_1;
    int liczba = 0;
    int k;
    const int n = 20;
    ksiazka ksiazki[n];

    do {
        Menu();
        cout << "Wybierz opcje: ";
        cin >> wybor;
        cin.ignore();

        switch (wybor) {
            case '1':
                do {
                    for (int i = liczba; i < n; i++) {
                        cout << "Podaj tytul ksiazki: ";
                        cin.getline(ksiazki[i].tytul, 80);
                        cout << "Podaj autora ksiazki: ";
                        cin.getline(ksiazki[i].autor, 80);
                        cout << "Podaj ilosc stron ksiazki: ";
                        cin >> ksiazki[i].liczbaStron;
                        ksiazki[i].wypozyczona = false;
                        ksiazki[i].rekordSkasowany = false;
                        cout << "Czy chcesz dodac kolejna ksiazke? (T/N): " << endl;
                        cin >> z_1;
                        cin.ignore();
                        liczba++;
                        if (z_1 == 'N' || z_1 == 'n') break;
                    }
                } while (z_1 == 'T' || z_1 == 't');
                break;

            case '2':
                Wyswietl_Ksiazki(ksiazki, liczba);
                cout << "Wybierz numer ksiazki, ktora chcesz edytowac: " << endl;
                cin >> k;
                if (k > 0 && k <= liczba) {
                    Edytuj_Ksiazke(ksiazki, k-1);
                } else {
                    cout << "Nieprawidlowy numer ksiazki!" << endl;
                }
                break;

            case '3':
                Wyswietl_Ksiazki(ksiazki, liczba);
                cout << "Wybierz numer ksiazki, ktora chcesz usunac: " << endl;
                cin >> k;
                if (k > 0 && k <= liczba) {
                    Usun_Ksiazke(ksiazki, liczba, k);
                } else {
                    cout << "Nieprawidlowy numer ksiazki!" << endl;
                }
                break;

            case '4':
                Wyswietl_Ksiazki(ksiazki, liczba);
                cout << "Wybierz numer ksiazki, ktora chcesz wypozyczyc: " << endl;
                cin >> k;
                if (k > 0 && k <= liczba) {
                    Wypozycz_Ksiazke(ksiazki, k-1);
                } else {
                    cout << "Nieprawidlowy numer ksiazki!" << endl;
                }
                break;

            case '5':
                Wyswietl_Ksiazki(ksiazki, liczba);
                cout << "Wybierz numer ksiazki, ktora chcesz zwrocic: " << endl;
                cin >> k;
                if (k > 0 && k <= liczba) {
                    Zwroc_Ksiazke(ksiazki, k-1);
                } else {
                    cout << "Nieprawidlowy numer ksiazki!" << endl;
                }
                break;

            case '6':
                Wyswietl_Ksiazki(ksiazki, liczba);
                break;

            case '7':
                Wyswietl_Wypozyczone_Ksiazki(ksiazki, liczba);
                break;

            default:
                if (wybor != 'z' && wybor != 'Z')
                    cout << "Zly wybor!";
                break;

        }
    } while (wybor != 'z' && wybor != 'Z');
    return 0;
}

