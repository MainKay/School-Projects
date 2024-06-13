#include <iostream>
#include <stdio.h>
#include <cstring>
#define MAX_LEN 128
using namespace std;


int str_len(char s[])
{
    int i;
    for (i=0; s[i] !='\0'; i++){
    }
    return i;
}

int lwr_str_cnt(char s[])
{
    int male_litery = 0;
    for (int i=0; s[i] !='\0'; i++){
        if (s[i] > 96 && s[i] < 123){ // Przyjeto rozwiazanie w kodzie ASCII, gdzie 97 to 'a', a 122 to 'z'
            male_litery++;
        }
    }
    return male_litery;
}

int upr_str_cnt(char s[])
{
    int duze_litery = 0;
    for (int i=0; s[i] !='\0'; i++){
        if (s[i] > 64 && s[i] < 91){ // Przyjeto rozwiazanie w kodzie ASCII, gdzie 65 to 'A', a 90 to 'Z'
            duze_litery++;
        }
    }
    return duze_litery;
}

int dgt_str_cnt(char s[])
{
    int cyfry = 0;
    for (int i=0; s[i] !='\0'; i++){
        if (s[i] >= '0' && s[i] <= '9' ){
            cyfry++;
        }
    }
    return cyfry;
}

int nalpha_str_cnt(char s[]){
    int male_litery = lwr_str_cnt(s);
    int duze_litery = upr_str_cnt(s);
    int cyfry = dgt_str_cnt(s);

    return male_litery + duze_litery + cyfry;
}

int chr_str_cnt(char c, char s[])
{
    int znak_c = 0;
    for (int i=0; s[i] !='\0'; i++){
        if (s[i] == c){
            znak_c++;
        }
    }
    return znak_c;
}

int chr_str_pos(char c, char s[])
{
    int i;
    for (i=0; s[i] !='\0'; i++){
        if (s[i] == c){
            return i;
        }
    }
    return -1;
}

int chr_str_rpos(char c, char s[])
{
    int i;
    for (i= str_len(s); i >= 0; i--){
        if (s[i] == c){
            return str_len(s);
        }
    }
    return -1;
}

void str_rev(char s[])
{
    int dlugosc = strlen(s);
    for (int i=0; i < dlugosc / 2; i++){
        char zmienna = s[i];
        s[i] = s[dlugosc - i - 1];
        s[dlugosc -i - 1] = zmienna;
        }
    }


int main()
{
    char line[ MAX_LEN ];
    char c;
    int pos;
    printf( "\n\nOkresl dlugosc napisu: " );
    gets( line );
    printf( "\nLiczba znakow: %d", str_len( line ) );
    printf( "\nLiczba malych liter: %d", lwr_str_cnt( line ) );
    printf( "\nLiczba duzych liter: %d", upr_str_cnt( line ) );
    printf( "\nLiczba cyfr: %d", dgt_str_cnt( line ) );
    printf( "\nLiczba liter i cyfr w napisie: %d", nalpha_str_cnt( line ) );
    printf( "\n\nPodaj pojedynczy znak: " );
    c = getchar();
    fflush( stdin );
    printf( "\nLiczba wystapien znaku %c: %d", c, chr_str_cnt( c, line ) );
    if( ( pos = chr_str_pos( c, line ) ) != -1 )
        printf( "\nPierwsze wystapienie znaku %c od poczatku: %d", c,
                pos + 1 );
    else
        printf( "\nZnak %c nie zostal znaleziony", c );
    if( ( pos = chr_str_rpos( c, line ) ) != -1 )
        printf( "\nPierwsze wystapienie znaku %c od konca: %d", c,
                pos + 0 );
    else
        printf( "\nZnak %c nie zostal znaleziony", c );
    printf( "\n\nNapis oryginalny : %s", line );
    str_rev( line );
    printf( "\nNapis odwrocony : %s", line );
    ( void )getchar();

    return 0;
}

