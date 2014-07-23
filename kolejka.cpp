#include<iostream>
using namespace std;

struct Wezel
{int liczba;
Wezel *nast;};


void Wstaw(int liczba_wstaw, Wezel * &glowa, Wezel * &ogon);
void Drukuj (Wezel *glowa);
void UsunGlowe(Wezel * &glowa, Wezel * &ogon);


int main()
{
Wezel *glowa1;
Wezel *glowa2;
Wezel *ogon1;
Wezel *ogon2;

    glowa1=glowa2=0;
    ogon1=ogon2=0;

    Wstaw(1, glowa1, ogon1);
    Wstaw(2,glowa1, ogon1);
    Wstaw(3,glowa1, ogon1);
    Wstaw(4,glowa1, ogon1);

    //cout << glowa1;

    Drukuj (glowa1);

    cout <<endl<<endl;

//Wstaw (156, glowa2, ogon2);

  //  Drukuj(glowa2);

    UsunGlowe(glowa1, ogon1);

    Drukuj(glowa1);

}

void Wstaw(int liczba_wstaw, Wezel * &glowa, Wezel * &ogon)
{
    Wezel *nowy;
    if (glowa==0)
{
    nowy=new Wezel;
    nowy->liczba=liczba_wstaw;
    nowy-> nast=0;
    glowa=nowy;
    ogon=glowa;
}
else
{
     nowy=new Wezel;
    nowy->liczba=liczba_wstaw;
    nowy->nast=0;
    ogon->nast=nowy;
    ogon=nowy;
}

}

void Drukuj(Wezel *glowa)
{
    Wezel *biezacy;
    biezacy=glowa;

    if (glowa!=0)
    {
        while (biezacy->nast)
        {
            cout <<biezacy->liczba<<' ';
            biezacy=biezacy->nast;
        }
        cout << biezacy->liczba;
    }
    else
    {
        cout <<"Kolejka pusta";
    }
}

void UsunGlowe(Wezel * &glowa, Wezel * &ogon)
{
    Wezel *biezacy;
    biezacy=glowa;

 if (glowa!=0)
 {
 if (!biezacy->nast)
 {
     delete biezacy;
     glowa=0;
     ogon=0;
 }
 else
    {glowa=biezacy->nast;
    delete biezacy;
    }
 }

}
