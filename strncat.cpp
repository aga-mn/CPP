//Zadanie 705(K&R 5.5)
//Napisac swoja wersje funkcji strncat(s,ct,n).
//Funkcja wpisuje co najwyzej n znaków tekstu ct na koniec tekstu w s;
//tekst w s konczy znakiem '\0'; zwraca s.

#include<iostream>
#include<cstring>
using namespace std;

void WpiszZnaki(char *s, char *ct, int n);

int main()
{
    char imie[20]="Anna";
    char nazwisko[30]="Kowalska";

WpiszZnaki(imie, nazwisko, 18);

cout <<"Moja funkcja:  "<< imie<<endl;

char imie2[20]="Anna";
char nazwisko2[30]="Kowalska";

strncat(imie2,nazwisko2,10);
cout<<"Dla porownania funkcja biblioteczna:  "<<imie2;


}

void WpiszZnaki(char *s, char *ct, int n)
{
    while(*s++);
    s--;

    for (int i=0;i<n;i++)
    {
        *(s++)=*(ct++);
    }
*s='\0';

}
