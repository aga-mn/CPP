//Zadanie 706(K&R 5.5)
//Napisac swoja wersje funkcji int strncmp(cs,ct,n).
//Funkcja porównuje co najwyzej n znaków  tekstów zawartych w cs i ct;
//zwraca wartosc <0 dla cs<ct, wartosc 0 dla cs==ct, lub wartosc>0 dla cs>ct.

#include<iostream>
#include<cstring>  //skorzystam z strncmp zeby sprawdzic swoj wynik
using namespace std;

int PorowanajNapisy(char *s, char *t, int n);

int main()
{
    char napis1[30]="kotka bura";
    char napis2[30]="kotek szary";

    cout << PorowanajNapisy(napis1, napis2, 3)<<endl; //ma wyjsc 0
    cout << PorowanajNapisy(napis1, napis2, 7)<<endl; // ma wyjsc dodatnia
    cout << PorowanajNapisy(napis2, napis1, 5)<<endl; // ma wyjsc ujemna

cout <<"\nSprawdzam czy ten sam wynik otrzymam korzystajac z funkcji 'strncmp'\n";

    cout <<strncmp(napis1,napis2,3)<<endl;
    cout <<strncmp(napis1,napis2,7)<<endl;
    cout <<strncmp(napis2,napis1,5)<<endl;

}

int PorowanajNapisy(char *s, char *t, int n)
{
int i=0;
while (*s==*t && i<n-1)
{
       s++;t++;i++;
}

return *s-*t;
}
