//Zadanie 804 (Delanoy 6.7)
//Napisac program, który usunie wszystkie podane znaki (parametr) z tekstu podanego na wejsciu.
//Tekst bedzie sie miescil w wierszu o dlugosci 128 znaków.
//Tak zmodyfikowany lancuch ma byc zapamietany w miejscu starego.

#include <iostream>

using namespace std;

void UsunZnak(char s[], char znak);

int main()
{
    char napis [128];

    cout << "Podaj napis: ";

    cin.getline(napis, 128);

    UsunZnak(napis, 'e');
    cout <<napis<<endl;

char zz;
cin >> zz;
}

void UsunZnak(char s[], char znak)
{int i,j;
for (i=j=0;s[i]!='\0';i++)
if (s[i]!=znak)
s[j++]=s[i];
    s[j]='\0';
}
