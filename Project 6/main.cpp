#include <iostream>
#include <stdio.h>
#include <cstring>
#define MAX_LEN 128
using namespace std;


int str_len(char *s)
{
    char *tab = s;
    while (*s) {
        s++;
    }
    return s - tab;
}

int lwr_str_cnt(char *s)
{
    int male_litery = 0;
    while (*s) {
        if (*s > 96 && *s < 123){
            male_litery++;
        }
        s++;
    }
    return male_litery;
}

int upr_str_cnt(char *s)
{
    int duze_litery = 0;
    while (*s) {
        if (*s > 64 && *s < 91){
            duze_litery++;
        }
        s++;
    }
    return duze_litery;
}

int dgt_str_cnt(char *s)
{
    int cyfry = 0;
    while (*s) {
        if (*s >= '0' && *s <= '9' ){
            cyfry++;
        }
        s++;
    }
    return cyfry;
}

int nalpha_str_cnt(char *s){
    int male_litery = lwr_str_cnt(s);
    int duze_litery = upr_str_cnt(s);
    int cyfry = dgt_str_cnt(s);

    return male_litery + duze_litery + cyfry;
}

int chr_str_cnt(char c, char *s)
{
    int znak_c = 0;
    while (*s) {
        if (*s == c) {
            znak_c++;
        }
        s++;
    }
    return znak_c;
}

int chr_str_pos(char c, char *s)
{
    char *tab = s;
    while (*s) {
        if (*s == c) {
            return s - tab;
        }
        s++;
    }
    return -1;
}

int chr_str_rpos(char c, char *s)
{
    char *end = s + str_len(s) - 1;
    while (end >= s) {
        if (*end == c){
            return str_len(s) - (end - s);
        }
        end--;
    }
    return -1;
}

void str_rev(char *s) {
    char *end = s + str_len(s) - 1;
    while (s < end) {
        char temp = *s;
        *s = *end;
        *end = temp;
        s++;
        end--;
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

