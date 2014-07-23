#include<iostream>
#include<iomanip>
using namespace std;


class Pracownik {
    int id; // identyfikator
    string nazwisko; // lub char *nazwisko - wtedy destruktor
    double podatek_stawka; // % podatku
protected:
    double placa_brutto;
public:
    Pracownik(): id(0),nazwisko(""){};
    Pracownik(int prac_id, string prac_nazw): id(prac_id), nazwisko(prac_nazw){};
    void wpisz_podatek(double nowa_stawka);
    void wpisz_place(double nowa_placa);
    double oblicz_place_netto(); // po odtr¹ceniu podatku
    void drukuj_info(); // wyœwietla informacjê o pracowniku
    int podaj_id(){return id;}
    string podaj_nazwisko() {return nazwisko;}
    double podaj_podatek (){return podatek_stawka;}
};

void Pracownik::wpisz_podatek(double nowa_stawka)
{    podatek_stawka=nowa_stawka; }

void Pracownik::wpisz_place(double nowa_placa)
{     placa_brutto=nowa_placa; }

 double Pracownik::oblicz_place_netto()
{    return placa_brutto-(podatek_stawka*placa_brutto/100);     }

void Pracownik::drukuj_info ()// ma byc ladnie

{cout<<setw(20)<<"nazwisko = "<<nazwisko<<endl<<setw(20)<<"id = "<<id<<endl<<setw(20)<<"placa brutto = "<<placa_brutto<<endl<<setw(20)<<
"podatek = "<<placa_brutto*podatek_stawka/100<<endl<<setw(20)<<"placa netto = "<< oblicz_place_netto();}

//#################################################################################################
class Pracownik_godz : public Pracownik
{
double ile_godzin; // liczba przepracowanych godzin
double stawka_godz; // stawka godzinowa
public:
Pracownik_godz();
Pracownik_godz(int prac_id, string prac_nazw, double stawka): Pracownik(prac_id, prac_nazw){stawka_godz=stawka;}
void wpisz_godz(double ile);
void wpisz_stawke_godz(double stawka);
double oblicz_place();
void drukuj_info();
};

Pracownik_godz::Pracownik_godz()
{
Pracownik();
stawka_godz=0;
ile_godzin=0;
}

void Pracownik_godz::wpisz_godz(double ile){ile_godzin=ile;}
void Pracownik_godz::wpisz_stawke_godz(double stawka) {stawka_godz=stawka;}
double Pracownik_godz::oblicz_place(){return stawka_godz*ile_godzin;}

void Pracownik_godz::drukuj_info()
{ cout<<endl<<endl<<setw(20)<<"nazwisko = "<<podaj_nazwisko() <<endl<<setw(20)<<"id = "<<podaj_id()<<endl<<setw(20)<<
"placa brutto = "<<oblicz_place()<<endl<<setw(20)<<"podatek = "<<oblicz_place()*podaj_podatek()/100<<
endl<<setw(20)<<"placa netto = "<< oblicz_place()-(oblicz_place()*podaj_podatek()/100)<<endl<<
setw(20)<<"liczba godzin = "<<ile_godzin<<endl<<setw(20)<<"stawka = "<<stawka_godz<<endl<<endl;
}

int main()
{
    Pracownik a(1234, "Kowalski");
    a.wpisz_place(2000);
    a.wpisz_podatek(20);
    a.drukuj_info();

    Pracownik_godz b(2345,"Nowak",50);
    b.wpisz_podatek(20);
    b.wpisz_godz(100);
    b.drukuj_info();

}
