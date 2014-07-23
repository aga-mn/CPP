#include<iostream>
#include<cstdlib>

using namespace std;

struct Lista
{
  Lista *poprz;
  int liczba;

};

void InicjujListe(Lista** wlista); 
void DodajPozycje(int i, Lista** wlista); 
void WyswietlListe(Lista* wlista); 
void UsunElement(int numer, Lista*&poczatek);

int main()
{
	srand((unsigned(time(0))));
    Lista *head;
    head = NULL;

    int n=20;

InicjujListe(&head);

    for (int i=0;i<n;i++)
    {
        DodajPozycje(rand()%101, &head);
    }

    WyswietlListe(head);
    UsunElement(1,head);
     cout<<endl;
     WyswietlListe(head);
    UsunElement(1,head);
    cout<<endl;
     WyswietlListe(head);
}

void DodajPozycje(int i, Lista **wlista)
{
    Lista *temp;
    temp=new Lista;
    temp->liczba=i;
    temp->poprz=*wlista;
    *wlista=temp;
}

void WyswietlListe(Lista* wlista)
{

    while (wlista)
    {cout<<wlista->liczba<<" ";
    wlista=wlista->poprz;}
}

void InicjujListe(Lista** wlista)
{
    Lista *temp;
    temp=new Lista;
    temp->liczba=rand()%101;
    temp->poprz=NULL;
    *wlista=temp;
}

void UsunElement(int numer, Lista*&poczatek)
{
    Lista *biezacy;
    biezacy=poczatek;
    Lista *usuwany;

if (numer>0)

    {
    for (int i=1;i<numer-1 && biezacy->poprz->poprz; i++)
    biezacy=biezacy->poprz;

    if (biezacy->poprz)

    {usuwany=biezacy->poprz;
    biezacy->poprz=biezacy->poprz->poprz;

delete usuwany;
    }
    else
    {
        usuwany=biezacy->poprz;
        biezacy->poprz=0;
    delete usuwany;
    }
    }
else
{
usuwany=poczatek;
poczatek=biezacy->poprz; //usuwam glowe
cout <<"\n\nusuwany "<<usuwany<<endl;

delete usuwany;
}
}
