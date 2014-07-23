#include<iostream>
using namespace std;

//**************************************************************************************************

int RozmiarMaZnaczenie(char []);    //funkcja liczaca znaki w tablicy, dzieki niej ustalimy, ktory ciag jest najdluzszy
void DopelnianieGwiazdkami(char[],int); //dopisanie gwiazdek - dopelnienie do najdluzszego

//**************************************************************************************************

int main()
{
    short const max=40;
    char ciag1[max], ciag2[max], ciag3[max], ciag4[max];

    cout<<"Ciag1: ";
    cin.getline(ciag1, max);
    cout <<"Ciag2: ";
    cin.getline(ciag2, max);
    cout <<"Ciag3: ";
    cin.getline(ciag3, max);
    cout <<"Ciag4: ";
    cin.getline(ciag4, max);

int xxl; //w tej zmiennej zapamietam dlugosc najdluzszego ciagu

xxl= RozmiarMaZnaczenie(ciag1);
if (RozmiarMaZnaczenie(ciag2)>xxl)
xxl=RozmiarMaZnaczenie(ciag2);
else if(RozmiarMaZnaczenie(ciag3)>xxl)
xxl=RozmiarMaZnaczenie(ciag3);
else //if(RozmiarMaZnaczenie(ciag4)>xxl)
xxl=RozmiarMaZnaczenie(ciag4);

//znam dlugosc najdluzszego ciagu
//przed wypisaniem dopelniam pozostale gwiazdkami

cout<<xxl;

DopelnianieGwiazdkami(ciag1,xxl);
DopelnianieGwiazdkami(ciag2,xxl);
DopelnianieGwiazdkami(ciag3,xxl);
DopelnianieGwiazdkami(ciag4,xxl);

  for (int i=0;i<xxl;i++)
  { cout<<endl;
    cout<< ciag1[i]<<"  "<<ciag2[i]<<"  "<<ciag3[i]<<"  "<<ciag4[i];
  }

}

//******************************************************************************************

int RozmiarMaZnaczenie(char tablica[])
{
    int i=0;
int ile=0;
while(tablica[i]!=0)
{
    ile++;
    i++;
}
return ile;
}

//******************************************************************************************
void DopelnianieGwiazdkami(char tablica[],int n)
{
    for(int i=RozmiarMaZnaczenie(tablica);i<n;i++)
    tablica[i]='*';
}

