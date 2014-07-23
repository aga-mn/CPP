#include<iostream>
using namespace std;

struct Wezel
{
    int liczba;
    Wezel *nast;
};
Wezel *glowa;
Wezel *ogon;


void Wstaw(int liczba);
void Drukuj();
void UsunGlowe();

int main()
{
glowa=0;
ogon=0;


    Wstaw(1);
    Wstaw(2);
    Wstaw(3);
    Wstaw(4);
    Wstaw(5);
    Wstaw(6);
    Wstaw(7);
    Wstaw(8);
    Wstaw(9);

    Drukuj();

    UsunGlowe();
    UsunGlowe();
 UsunGlowe();
  UsunGlowe();
   UsunGlowe();
 //   UsunGlowe();
   //  UsunGlowe();
   //UsunGlowe();
UsunGlowe();

cout <<endl<<endl;

  Drukuj();


}

void Wstaw(int liczba_wstaw)
{
    Wezel *nowy;

    if(glowa==0){
    nowy = new Wezel;
    nowy->liczba=liczba_wstaw;
    nowy->nast=0;
    glowa=nowy;
    ogon=glowa;
    }
    else {
    nowy = new Wezel;
    nowy->liczba=liczba_wstaw;
    nowy->nast=0;
    ogon->nast=nowy;
    ogon=nowy;
    }
}

void Drukuj() {
Wezel *biezacy;
biezacy=glowa;

if(glowa!=0)
{

while(biezacy->nast){
  cout<< biezacy->liczba;
biezacy=biezacy->nast;
}
  cout<< biezacy->liczba;

}
else
{
  cout<< "Kolejka pusta";
}
}

void UsunGlowe()
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
