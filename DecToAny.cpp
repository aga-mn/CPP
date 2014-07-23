// Zadanie 130
//Dana jest liczba calkowita p wyrazona w systemie dziesietnym.
//Zamienic liczbe p na liczbe wyrazona w ukladzie o podstawie q < 10.

#include <iostream>

using namespace std;

int SprawdzWymiarTablicy(int liczba, int podstawa);
int Potega(int liczba, int wykladnik);

int main()
{
    int liczba, podstawa, i, j;

    cout << "Podaj liczbe dziesietna ";
    cin >> liczba;
    cout << "Na jaki system liczbowy o podstawie <10 chcesz ja zamienic? ";
    cin  >> podstawa;

    if (podstawa <2 || podstawa >=10)
    cout << "Niestety, nie jest to mozliwe. ";

    else
    {int tab[SprawdzWymiarTablicy(liczba,podstawa)];

    for(i=0;liczba>0;i++)
    {
        tab[i]= liczba%podstawa;
        liczba=liczba/podstawa;
    }
 for (j=i-1;j>=0;j--)
    cout << tab[j];
    }
}
// sprawdza jaka jest najwyzsza potega danej podstawy w liczbie dziesietnej i liczy wymiar tablicy

int SprawdzWymiarTablicy(int liczba, int podstawa)
{int ile=0, i;
for (i=0; Potega(podstawa, i)<liczba; i++)
    ile++;
    return ile;
}

int Potega(int liczba, int wykladnik)

// w tym programie dzialamy tylko na liczbach calkowitych,
//zarówno podstawa jak i wyladnik potegi sa typu int
{
    int i;
    int wynik=1;

    for (i=1; i<=wykladnik; i++)
    wynik=wynik*liczba;
    return wynik;
}
