#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Wezel
{int liczba;
char nazwa;
Wezel *nast;};


void Wstaw(int liczba_wstaw,char nazwa_wstaw, Wezel * &glowa, Wezel * &ogon);
void Drukuj (Wezel *glowa);
void UsunGlowe(Wezel * &glowa, Wezel * &ogon);


int main()
{
Wezel *glowa1, *glowa2, *glowa3, *glowa4;
Wezel *ogon1, *ogon2, *ogon3, *ogon4;

glowa1=glowa2=glowa3=glowa4=0;
ogon1=ogon2=ogon3=ogon4=0;

Wstaw(11,'A', glowa1, ogon1);
Wstaw(12,'A',glowa1, ogon1);

Wstaw(21,'B', glowa2, ogon2);
Wstaw(21,'B',glowa2, ogon2);
Wstaw(23,'B',glowa2, ogon2);
Wstaw(24,'B',glowa2, ogon2);

Wstaw(31,'C', glowa3, ogon3);

char dzialanie;
char ost_oper[80]="START";
do
{

cout <<"\t************** WITAMY NA POCZCIE **************\n\n";
cout <<"\tOSTATNIA OPERACJA:"<<ost_oper<<"\n\n";

cout <<endl<<endl<<endl;
cout <<"[Kolejka 1]: ";
Drukuj(glowa1);
cout <<endl<<endl;

cout <<"[Kolejka 2]: ";
Drukuj(glowa2);
cout <<endl<<endl;

cout <<"[Kolejka 3]: ";
Drukuj(glowa3);
cout <<endl<<endl;

cout <<"[Kolejka 4]: ";
Drukuj(glowa4);
cout <<endl<<endl;


cout <<endl<<endl<<endl;
cout <<"[Kolejka 1]\t[Kolejka 2]\t[Kolejka3]\t[Kolejka 4]\n";
cout <<" Dodaj(1)\t Dodaj(2)\t Dodaj(3)\t Dodaj(4)\n";
cout <<" Usun (5)\t Usun (6)\t Usun (7)\t Usun (8)";

cin >> dzialanie;

switch (dzialanie)
{
case '1':
Wstaw(ogon1 ? ogon1->liczba+1 : 0 ,'A', glowa1, ogon1);
strcpy (ost_oper,"Przyszedl klient do kolejki A");
break;
case '2':
Wstaw(ogon2 ? ogon2->liczba+1 : 0,'B', glowa2, ogon2);
strcpy (ost_oper,"Przyszedl klient do kolejki B");

break;
case '3':
Wstaw(ogon3 ? ogon3->liczba+1 : 0,'C', glowa3, ogon3);
strcpy (ost_oper,"Przyszedl klient do kolejki C");
break;
case '4':
Wstaw(ogon4 ? ogon4->liczba+1 : 0,'D', glowa4, ogon4);
strcpy (ost_oper,"Przyszedl klient do kolejki D");
break;
case '5':
UsunGlowe(glowa1, ogon1);
strcpy (ost_oper,"Odszedl klient z kolejki A");
break;
case '6':
UsunGlowe(glowa2, ogon2);
strcpy (ost_oper,"Odszedl klient z kolejki B");
break;
case '7':
UsunGlowe(glowa3, ogon3);
strcpy (ost_oper,"Odszedl klient z kolejki C");
break;
case '8':
UsunGlowe(glowa4, ogon4);
strcpy (ost_oper,"Odszedl klient z kolejki D");
break;
default: break;
}
system("CLS");

} while (dzialanie != '0');

system ("CLS");
cout <<"\n\n\n\n\n\t************************ KONIEC PRACY ************************\n\n\n\n\n\t\t\tZ A P R A S Z A M Y      J U T R O\n\n\n";


}

void Wstaw(int liczba_wstaw,char nazwa_wstaw, Wezel * &glowa, Wezel * &ogon)
{
Wezel *nowy;
if (glowa==0)
{

nowy=new Wezel;
nowy->liczba=liczba_wstaw;
nowy->nazwa=nazwa_wstaw;
nowy-> nast=0;
glowa=nowy;
ogon=glowa;
}

else
{
nowy=new Wezel;
nowy->liczba=liczba_wstaw;
nowy->nazwa=nazwa_wstaw;
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
while (biezacy)
{
cout <<biezacy->nazwa<<'_'<<biezacy->liczba<<' ';
biezacy=biezacy->nast;
}
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
{
glowa=biezacy->nast;
delete biezacy;
}


}

}




