#include <iostream>
#include <string>
using namespace std;

//_______________________________________OSOBA________________________________________________
class Osoba {
string nazwisko;
public:
Osoba();
Osoba(string n);
Osoba(const Osoba& os);
string czytaj_nazwisko() const;
Osoba& operator=(const Osoba& os);
friend istream& operator>>(istream&, Osoba& os);
friend ostream& operator<<(ostream& wy, const Osoba& os);
};

Osoba::Osoba(){nazwisko="brak nazwiska";}
Osoba::Osoba(string n){nazwisko=n;}
Osoba::Osoba (const Osoba& os){nazwisko=os.nazwisko;}
Osoba& Osoba::operator=(const Osoba &os) {nazwisko=os.nazwisko; return *this;}
string Osoba::czytaj_nazwisko() const{return nazwisko;}

ostream & operator << (ostream &wy, const Osoba &os) {   wy<< os.nazwisko;    return wy;}

istream & operator >> (istream& in, Osoba& os) {  in >> os.nazwisko; return in;    }

//______________________________________________SAMOCHOD___________________________________________________
class Samochod{

string marka;
int pojemnosc;
Osoba owner;

public:
Samochod(): marka(""),pojemnosc(0){}
Samochod(string nazwa);
Samochod(string nazwa, int poj);
Samochod(string nazwa, int poj, Osoba os);
Samochod(const Samochod &sam);

string Marka() {return marka;}
int Pojemnosc() {return pojemnosc;}
Osoba Owner() {return owner;}

void WpiszMarke(string nazwa);
void WpiszWlasciciela(Osoba os);
void WpiszPojemnosc (int poj);
void drukuj();
friend ostream& operator<<(ostream& wy, const Samochod& sam);

Samochod & operator=(const Samochod& sam);
};

void Samochod::WpiszMarke(string nazwa) {marka=nazwa;}
void Samochod::WpiszWlasciciela(Osoba os) {owner=os;}
void Samochod::WpiszPojemnosc (int poj) {pojemnosc=poj;}

Samochod::Samochod(string nazwa) {marka=nazwa; pojemnosc=0;}
Samochod::Samochod(string nazwa, int poj) {marka=nazwa; pojemnosc=poj;}
Samochod::Samochod(string nazwa, int poj, Osoba os) {marka=nazwa; pojemnosc=poj; owner=os;}
Samochod::Samochod(const Samochod &sam) {marka=sam.marka; pojemnosc=sam.pojemnosc; owner=sam.owner;}

void Samochod::drukuj() {cout << "\nmarka: "<< marka<<"\npojemnosc: "<<pojemnosc<<"\nwlasciciel: "<<owner;}

Samochod& Samochod::operator= (const Samochod &sam) {marka=sam.marka; pojemnosc=sam.pojemnosc; owner=sam.owner; return *this;}

ostream& operator<<(ostream& wy, const Samochod& sam)
{
wy << "\nmarka: "<< sam.marka<<"\npojemnosc: "<<sam.pojemnosc<<"\nwlasciciel: "<<sam.owner; return wy;
}



//_____________________________________OSOBOWY_____________________________________________________

class Osobowy: public Samochod
{
    int pasazer;
    double bagaznik;
    int drzwi;

    public:
    Osobowy(): Samochod() {pasazer=0; bagaznik=0; drzwi=0;}
    Osobowy(string nazwa): Samochod(nazwa) {pasazer=0; bagaznik=0; drzwi=0;}
    Osobowy(string nazwa, int poj): Samochod(nazwa,poj){pasazer=0; bagaznik=0; drzwi=0;}
    Osobowy(string nazwa, int poj, Osoba os): Samochod (nazwa,poj,os){pasazer=0; bagaznik=0; drzwi=0;}
    void WpiszPasazerow(int ile);
    void WpiszBagaznik (double bagaz);
    void WpiszDrzwi (int ile);
    friend ostream& operator<<(ostream& wy, Osobowy& sam);
};

void Osobowy::WpiszPasazerow(int ile) {pasazer=ile;}
void Osobowy::WpiszBagaznik(double bagaz){bagaznik=bagaz;}
void Osobowy::WpiszDrzwi(int ile){drzwi=ile;}

ostream& operator << (ostream & wy,  Osobowy &sam) {wy << "\nmarka: "<<sam.Marka()<<"\npojemnosc: "<<sam.Pojemnosc()<<
"\nwlasciciel: "<<sam.Owner()<<"\nliczba pasazerow: "<<sam.pasazer<<"\npojemnosc bagaznika: "<<sam.bagaznik<<
"\nliczba drzwi: "<<sam.drzwi; return wy;}

//______________________________________________CIEZAROWY_________________________________________________________
class Ciezarowy: public Samochod
{
double ladownosc;
int osie;
bool load;

public:
    Ciezarowy(): Samochod() {ladownosc=0; osie=0; load=false;}
    Ciezarowy(string nazwa): Samochod(nazwa) {ladownosc=0; osie=0; load=false;}
    Ciezarowy(string nazwa, int poj): Samochod(nazwa,poj){ladownosc=0; osie=0; load=false;}
    Ciezarowy(string nazwa, int poj, Osoba os): Samochod (nazwa,poj,os){ladownosc=0; osie=0; load=false;}

    void WpiszLadownosc(double volume);
    void WpiszOsie (int axis);
    void WpiszUrzadzenie ();
    friend ostream& operator<<(ostream& wy, Ciezarowy& sam);

};
    void Ciezarowy::WpiszLadownosc(double volume) {ladownosc=volume;}
    void Ciezarowy::WpiszOsie (int axis) {osie=axis;}
    void Ciezarowy::WpiszUrzadzenie () {load=true;}
    ostream& operator<<(ostream& wy, Ciezarowy& sam)
    {wy << "\nmarka: "<<sam.Marka()<<"\npojemnosc: "<<sam.Pojemnosc()<<
"\nwlasciciel: "<<sam.Owner()<<"\nladownosc: "<<sam.ladownosc<<"\nliczba osi: "<<sam.osie<<"\nurzadzenie: ";
if (sam.load) wy <<"tak"; else wy <<"nie"; return wy;

    }

//______________________________________________TEST_______________________________________________________________
int main()
{
Osoba a ("Kowalski");
Osoba b=a;
Osoba c;
cout <<"\nPodaj nazwisko\n"; cin >> c;
Samochod aut("bmw",1800,c);
cout <<aut<<endl<<endl;

Osobowy n("audi", 1800, b);
n.WpiszDrzwi(4);
n.WpiszPasazerow(5);
n.WpiszBagaznik(500);
Osobowy m; m=n;
cout <<m<<endl<<endl;

Osoba y("Kwiatkowski");
Ciezarowy x ("Scania",3000);
x.WpiszWlasciciela(y);
x.WpiszLadownosc(10000);
x.WpiszOsie(4);
x.WpiszUrzadzenie();
Ciezarowy z; z=x;
cout <<z<<endl<<endl;

}
