//Zadanie 702 (K&R zad.5.3)
//Napisac tablicowa i wskaznikowa wersje funkcji strcat dowiazujaca tekst z t
//do konca tekstu w s.

#include<iostream>

using namespace std;

void DowiazTekst(char *s, char *t);

int main()

{
 char napis1[80]="Wlazl kotek na plotek ";
 char napis2[80]="i mruga";

DowiazTekst(napis1,napis2);

cout<<napis1;

}

void DowiazTekst(char *s, char *t){

while(*s++);
{s--;}

while(*s++ = *t++);
}
