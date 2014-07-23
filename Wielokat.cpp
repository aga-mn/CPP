//Agata Molda-Nieweglowska IZ04P04

#include<iostream>
using namespace std;

class Wielokat {
int l_bokow; // liczba boków
int *boki; // tablica z d³ugoœciami boków
public:
Wielokat(); // konstruktor domyœlny
Wielokat(int l_bokow); // konstruktor, gdy podana liczba boków
Wielokat(const Wielokat &w); // konstruktor kopiuj¹cy
~Wielokat(){delete []boki;} // destruktor
// przeci¹¿ony operator przypisania
Wielokat& operator=(const Wielokat &w);
// wstawianie dlugoœci boku
void wpiszBok(int ktory, int dlugosc);
// wyœwietlanie boków
void drukuj();
// obliczanie obwodu
int obwod();
// w wersji obecnej: wyœwietlanie komunikatu
// "Nie potrafie policzyc powierzchni"
int area();
int PodajBok(int ktory);
};

Wielokat::Wielokat() {l_bokow=0;}
Wielokat::Wielokat(int n){l_bokow=n; boki=new int[n];  for (int i=0;i<n;i++) boki[i]=0; }
Wielokat::Wielokat(const Wielokat &w)
{l_bokow=w.l_bokow; boki=new int[l_bokow];
for(int i=0;i<l_bokow;i++) boki[i]=w.boki[i]; }

void Wielokat::wpiszBok(int ktory, int dlugosc) {boki[ktory]=dlugosc;}

int Wielokat::obwod()
{    int suma=0;
    for (int i=0;i<l_bokow;i++) suma+=boki[i];
    return suma;}

void Wielokat::drukuj()
{    cout <<"Liczba bokow: "<<l_bokow<<"\nDlugosci bokow: ";
    for (int i=0;i<l_bokow;i++) cout << boki[i]<<"  ";
}
int Wielokat::area()
{    cout <<"\nNie moge policzyc powierzchni\n";
return 0;}

int Wielokat::PodajBok(int ktory)
{    return boki[ktory];    }

class Prostokat: public Wielokat
{
  public:
  Prostokat(): Wielokat(4){}
  Prostokat(int a,int b):Wielokat(4) {wpiszBok(0,a); wpiszBok(1,b); wpiszBok(2,a); wpiszBok(3,b);}
  Prostokat (Prostokat&a): Wielokat(a){}
  int area();
};

int Prostokat::area()
{  int a,b;
        a=PodajBok(0);
        if (PodajBok(1)!=a) b=PodajBok(1);
        else if(PodajBok(2)!=a) b=PodajBok(2);
        else b=PodajBok(3);

        return a*b;
        }

class Kwadrat: public Prostokat
{
 public:
 Kwadrat(): Prostokat(){}
 Kwadrat (int a): Prostokat(a,a){}
 Kwadrat (Kwadrat &a): Prostokat(a){}
};


int main()
 {
     //******************Test klasy Wielokat
     cout <<"******************Test klasy Wielokat******************\n\n";
Wielokat a(5);
Wielokat b = Wielokat(3); // Wielokat b(3)
Wielokat c = a;
c.drukuj();
int bok;
cout << "\nWpisz dlugosci bokow trojkata: ";

for (int i = 0; i<3; i++)
{cin >> bok;
b.wpiszBok(i, bok);}
b.drukuj(); cout << endl;
cout<<"Obwod: "<< b.obwod();
b.area();

//******************Test klasy Prostokat
cout <<"\n\n******************Test klasy Prostokat******************\n\n";

Prostokat p(3,4);
p.drukuj();
cout << "\nObwod: "<<p.obwod();
cout << "\nPowierzchnia: "<<p.area();

//******************Test klasy Kwadrat
cout <<"\n\n******************Test klasy Kwadrat******************\n\n";
Kwadrat kk(8);
Kwadrat k=kk;
k.drukuj();
cout << "\nObwod: "<<k.obwod();
cout << "\nPowierzchnia: "<<k.area();

char zz;
cin >>zz;

}

