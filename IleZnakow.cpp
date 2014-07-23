//Zadanie 803 (Delanoy 6.6)
//Napisac program, który obliczy, ile znaków (parametr) zawiera na wejsciu ciag znaków.
//Ciag nie bedzie dluzszy niz 128 znaków.
//Nie nalezy korzystac z funkcji obslugi lancuchów.

#include<iostream>
using namespace std;

int IleZnakow(char s[], char znak);

int main()
{
    char napis [128];

    cout <<"Wpisz tekst: ";
    cin.getline(napis, 128);

    cout << "\n\nW tekscie: '"<<napis<<"' jest "<<IleZnakow(napis, 'e')<<" znakow 'e' ";

char zz;
cin >> zz;

}

int IleZnakow(char s[], char znak)
{
    int ile=0;
    for (int i=0;s[i]!='\0';i++)
    {
        if (s[i]==znak)
        {
            ile++;
        }
    }
    return ile;
}
