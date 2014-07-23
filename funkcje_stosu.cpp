//stos

#include <iostream>
#include <cstdlib>
using namespace std;

struct Element
{
  int liczba;
  Element *wskaznik;
};

void OdlozNaStos(int liczba, Element *&top);
void ZdejmijZeStosu(Element *&top);
int CzyPusty(Element *top); //zwraca 1 jesli stos jest pusty, 0 w przeciwnym wypadku
void DrukujStos(Element * top);

int main()
{
    Element *top;
    top=0;

cout <<"Ukladam na stosie liczby 1-7\n";

for (int i=1;i<=7;i++)
    {
        OdlozNaStos(i,top);
    }

    DrukujStos(top);

cout <<"\nZdejmuje 3 elementy:\n";

for (int i=0;i<3;i++)
{
        ZdejmijZeStosu(top);
}
    DrukujStos(top);

cout <<"\nOprozniam stos\n";
while (top)
{
    ZdejmijZeStosu(top);
}
DrukujStos(top);

cout <<"\nUkladam na stosie 10 liczb losowych 0-20\n";
for (int i=0;i<10;i++)
{
    OdlozNaStos(rand()%21, top);
}
DrukujStos(top);

cout <<"\nZdejmuje 2 elementy\n";
ZdejmijZeStosu(top);
ZdejmijZeStosu(top);

DrukujStos(top);

cout <<"\nOprozniam stos\n";
while (top)
{
    ZdejmijZeStosu(top);
}
DrukujStos(top);

char zz;
cin >>zz;

}

void OdlozNaStos(int liczba_wstaw, Element *&top)
{
    Element *nowy;
    nowy=new Element;
    nowy->liczba=liczba_wstaw;

    if (CzyPusty(top))
    {
        nowy->wskaznik=0;
        top=nowy;
    }
    else
    {
        nowy->wskaznik=top;
        top=nowy;
    }

}

void ZdejmijZeStosu(Element *&top)
{
    Element *biezacy;
    biezacy=top;

    if (!CzyPusty(biezacy))//jesli nie jest pusty
    {
        if (!biezacy->wskaznik) //jesli jest 1 element
        {
            delete biezacy;
            top=0;
        }
        else
        {
            top=biezacy->wskaznik;
            delete biezacy;
        }
    }

}

int CzyPusty(Element *top)
{
    return top? 0: 1;
}

void DrukujStos(Element * top)
{
    Element *biezacy;
    biezacy=top;

    if (!CzyPusty(biezacy))
    {
    while (biezacy)
      {
        cout << biezacy->liczba<<endl;
        biezacy=biezacy->wskaznik;
      }
    }
    else
    {cout <<"Stos pusty\n";}
}
