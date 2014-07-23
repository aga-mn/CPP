#include<iostream>
using namespace std;

class Ulamek
{

int licznik;
int mianownik;
int nwp(int p, int q);  //najwiekszy wspolny podzielnik

public:

Ulamek (int li=0, int mi=1);
int ZwrocLicznik () const {return licznik;};
int ZwrocMianownik () const {return mianownik;};
bool Rowne(Ulamek *wsk);
Ulamek WiekszyMianownik(Ulamek b);
Ulamek DodajUlamki(Ulamek b);
void Drukuj();
Ulamek operator+(const Ulamek &b);
Ulamek operator+(int n);
friend Ulamek operator+(int, Ulamek);
friend ostream& operator<<(ostream &wy, const Ulamek &f);
};

//************funkcje *******************************

Ulamek::Ulamek (int a, int b)
{
    int q=nwp(a,b);
    if(b<0) q=-q;   // mianownik doddatki
    licznik=a/q;
    mianownik=b/q;
}

int Ulamek::nwp(int p, int q)
{
    int r;
if (p<0) p=-p;
if (q<0) q=-q;

   if (p==0){if (q==0) return 1;else return q;}
else if (q==0) return p;

r=p%q;
while (r){p=q;q=r;r=p%q;}
return q;
}

bool Ulamek::Rowne(Ulamek *wsk)
{
 if (wsk->licznik==licznik && wsk->mianownik==mianownik) return true;
 else return false;
}

Ulamek Ulamek::WiekszyMianownik(Ulamek b)
{
    if (b.mianownik >= mianownik)
    return b;
    else return *this;
}

Ulamek Ulamek::DodajUlamki(Ulamek b)
{
    long rl, rm;
    rl=licznik*b.mianownik+b.licznik*mianownik;
    rm=mianownik*b.mianownik;
    return Ulamek(rl, rm);
}

void Ulamek::Drukuj()
{
    cout <<licznik<<'/'<<mianownik<<endl;
}

Ulamek Ulamek::operator+(const Ulamek &b)
{
    long rl, rm;
    rl=licznik*b.mianownik+b.licznik*mianownik;
    rm=mianownik*b.mianownik;
    return Ulamek(rl, rm);
}

Ulamek Ulamek::operator+(int n)
{
    return Ulamek(licznik+mianownik*n,mianownik);
}

Ulamek operator+(int n, Ulamek b)
{
    return Ulamek(b.licznik+b.mianownik*n, b.mianownik);

}

ostream& operator<<(ostream &wy, const Ulamek &f)
{
    wy<<f.licznik<<"/"<<f.mianownik;
    return wy;
}

//********************program testuj¹cy *****************************************

int main()
{
    Ulamek f0, f1(1), f2(6,8),f3;
    cout << "TEST KLASY ULAMEK\n";
    cout << f0.ZwrocLicznik()<<'/'<<f0.ZwrocMianownik()<<endl;
    cout << f1.ZwrocLicznik()<<'/'<<f1.ZwrocMianownik()<<endl;
    cout << f2.ZwrocLicznik()<<'/'<<f2.ZwrocMianownik()<<endl;

    if (f1.Rowne(&f2)) cout << "Ulamki sa rowne\n";
    else cout << "Ulamki nie sa rowne\n";

    f3=f1.WiekszyMianownik(f2);
    cout << f3.ZwrocLicznik()<<'/'<<f3.ZwrocMianownik()<<endl;

    Ulamek c1(1,2), c2(1,3), c3, c4(1,6), c5(1,3), c6, c7, c8;
    c3=c1+c2;
    c6=c4+c5;

    c3.Drukuj();
    c6.Drukuj();

    c7=c1+2;
    c7.Drukuj();

    c8=2+c1;
    //c8.Drukuj();

    cout << c8;
}


