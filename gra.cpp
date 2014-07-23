/*Zadanie 318*****
Napisac gre polegajaca na tym, ze komputer generuje liczbe losowa z zakresu od 0 do 9
zas zadaniem gracza jest odgadniecie tej liczby.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void gra ();       


int main ()
{
  char znak;

  do
  {
     gra();  //wywoluje funkcje 'gra' tak dlugo jak bede chciala grac dalej

     cout <<"Czy chcesz grac dalej (T/N)? " << endl;
     cin >> znak;
  }
  while (znak == 't');    //gra dalej jesli wybiore 't', przerywa jesli wybiore inny znak niz 't'

  cout << "Dziekujemy"<< endl;

}

//*****************funkcja 'gra'**********************************************************************

void gra ()
{
srand((unsigned(time(0))));

int liczba, liczba_los, ile;
ile=1;

do
{
    cout << "Zgadnij liczbe od 1 do 10\n";
    cin >> liczba;  			//wczytuje liczbe z klawiatury
    liczba_los = (rand()% 10); 	//liczby z przedzialu  0-9

    cout << "Wylosowana liczba to:  " << liczba_los << endl << "Twoja liczba to  " << liczba << endl;

    if (liczba_los != liczba)
        {
        cout <<"Niestety nie zgadles! Probuj dalej\n\n";
        ile++;
        }
    else
    cout << "Brawo!!!" << endl << "Zgadles za " << ile << " razem!\n";
}

while (liczba_los != liczba); //losuje 'do skutku'

}


