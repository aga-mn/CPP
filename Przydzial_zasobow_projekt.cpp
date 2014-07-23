//Agata Molda-Nieweglowska   gr IZ04P04

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

//_____________________________________klasa ISTOTA__________________________________________________________________
class istota
{
public:
	int poziom_glodu;
    int poziom_milosci;
	int liczba_sekund_potrzeby;
	string nazwa_istoty;

	istota(string);

	int random_poziom_glodu();
	int random_poziom_milosci();
	int random_liczba_sekund_potrzeby();
	int spr_nazwa_istoty(string name_istoty);
	int zaspokojenie_glodu();
	int zaspokojenie_milosci();
	void drukuj();
	void drukuj2();
 };

//_________________________metody klasy istota____________________________________________________


istota::istota(string name_istoty)
{
	nazwa_istoty=name_istoty;
	poziom_glodu=random_poziom_glodu();
    poziom_milosci=random_poziom_milosci();
	liczba_sekund_potrzeby=random_liczba_sekund_potrzeby();
}


int istota::spr_nazwa_istoty(string name_istoty)
{
	if(nazwa_istoty==name_istoty) return 1; else return 0;
}

int istota::random_liczba_sekund_potrzeby()
{
int licz=rand() % 4;
return   ++licz;        //zeby nie zwrocilo zera
}

int istota::random_poziom_glodu()
{
	return   rand() % 15;
}

int istota::random_poziom_milosci()
{
	return rand() % 7;
}

void  istota::drukuj()
{
cout << setw(15)<<nazwa_istoty<<setw(15)<<" poziom glodu:  "<<poziom_glodu<< setw(15) <<
" poziom milosci:  "<<poziom_milosci<<endl;
}

void  istota::drukuj2()
{
cout <<"\tKarmiony kot: " << nazwa_istoty<<endl;
cout <<"\tpoziom glodu: " <<poziom_glodu<<endl;
cout <<"\tpoziom milosci: "<<poziom_milosci<<endl;
cout <<"\tKot zjada: "<<liczba_sekund_potrzeby <<" porcji\n";
}

int  istota::zaspokojenie_glodu(){
	int out=0;
	poziom_glodu=poziom_glodu-liczba_sekund_potrzeby;

if (poziom_glodu<=0) {
poziom_glodu=0;
out=1;
} else { out=0;}
return out;
}

int  istota::zaspokojenie_milosci(){
	int out=0;
	poziom_milosci=poziom_milosci+liczba_sekund_potrzeby;

if (poziom_milosci>=10) {
poziom_milosci=10;
out=1;
} else { out=0;}
return out;
}

//******************************************************************************************
//________________________________klasa ListaCykl___________________________________________

struct Element          //element listy - sklada sie ze wskaznika na istote i wskaznika na nastepny element
{
istota *ist;
Element *nastepny;
};

class ListaCykl
{
Element *top;
Element *back;
Element *flag;

public:
	ListaCykl();
	~ListaCykl(){}

void Dodaj(istota *item); //dodaje na koncu

Element * Szukaj(string item);
istota * getnastistota();
void Usun(string item);
void Wypisz();
};

//_________________________________metody klasy ListaCykl________________________________
ListaCykl::ListaCykl()
{
top=back=0;
flag=top;
}

void ListaCykl::Dodaj(istota *item) //dodaje na koncu
{
Element *nowy;
Element *biezacy=back;

if (top==0)
{
nowy=new Element;
nowy->ist=item;
nowy->nastepny=0;
top=back=nowy;
flag=top;
}

else
{
nowy=new Element;
biezacy->nastepny=nowy;
nowy->ist=item;
nowy->nastepny=top;
back=nowy;
}
}

void ListaCykl::Usun(string item)           //usuwa element o danej nazwie
{
Element *biezacy,*doskasowania,*poprzedni,*nastepny;
poprzedni=Szukaj(item);

if(back!=top){
doskasowania=poprzedni->nastepny;
nastepny=poprzedni->nastepny->nastepny;

if(top==doskasowania){
top=nastepny;
}

if(back==doskasowania){
back=poprzedni;
}

delete doskasowania;
poprzedni->nastepny=nastepny;
}
else {
    delete poprzedni;
    back=top=0;
    flag=0;
    }
}

void ListaCykl::Wypisz()
{
Element *biezacy;
biezacy=top;

if (top!=0)
{
if(top!=back){
biezacy->ist->drukuj();
biezacy=biezacy->nastepny;

while(biezacy!=top)
{biezacy->ist->drukuj();
biezacy=biezacy->nastepny;
}}
else{
    biezacy->ist->drukuj();
    }}
else
cout <<"Lista pusta\n";
}

istota *ListaCykl::getnastistota() {
istota *ist_tmp;
ist_tmp=0;
if(flag!=0) {
if(top!=back) {
ist_tmp=flag->ist;
flag=flag->nastepny;
}
else {
ist_tmp=flag->ist;
    }}
return ist_tmp;
}

//zwraca wskaznik co pokazuje element do wywalenia
Element *ListaCykl::Szukaj( string item) {
Element *biezacy,*poprzedni;
biezacy=poprzedni=top;

if (top!=0)
{if(biezacy->ist->spr_nazwa_istoty(item)) return back;           //---to jest top

poprzedni=biezacy;
biezacy=biezacy->nastepny;

while(biezacy!=top)
{
if(biezacy->ist->spr_nazwa_istoty(item)) return poprzedni;
poprzedni=biezacy;
biezacy=biezacy->nastepny;
}}
return biezacy;
}

//_____________________________zmienne globalne___________________________________________________
ListaCykl A,B;
istota *tmp_istota, *tmp_istota_pop, *tmp_istota_nast;

//_____________________________funkcja zewnetrzna_________________________________________________
void czekaj ( int liczba_sekund )
{
clock_t a;
a = clock () + liczba_sekund * CLOCKS_PER_SEC ;
while (clock() < a) {}
}

//____________________________funkcja Menu()_______________________________________________________
void Menu()
{
int dl_dzialania_ss=120;        //jednostek jedzenia w misce
tmp_istota_pop=0;
do
{
cout <<"\n\n\n\t\t***********************************************\n";
cout <<"\t\t*                WIELKIE KARMIENIE            *\n";
cout <<"\t\t***********************************************\n\n\n";

cout <<"\t\tW misce zostalo: "<<dl_dzialania_ss<<" porcji\n\n";

cout <<endl<<endl;

tmp_istota=A.getnastistota();
//istota poprzednia
cout <<"\t\t__________________Kot poprzedni__________________\n\n";
if(tmp_istota_pop!=0)
tmp_istota_pop->drukuj2();

if(tmp_istota!=0) {
cout <<"\t\t__________________Kot przy misce__________________\n\n";
cout <<"\t\t dostanie "<<tmp_istota->liczba_sekund_potrzeby<<" porcji\n\n";
tmp_istota->drukuj2();

//karmienie i sprawdzanie czy najedzona i szczesliwa
if(tmp_istota->zaspokojenie_glodu() && tmp_istota->zaspokojenie_milosci()){
cout <<"\tKot najedzony!"<<endl;
B.Dodaj(tmp_istota);
A.Usun(tmp_istota->nazwa_istoty);
}

cout <<"\n\n\n\t\t_______________________________________________\n";
cout <<"\t\t>            NAKARMIONE I SZCZESLIWE          <\n";
cout <<"\t\t_______________________________________________\n\n\n";
B.Wypisz();
czekaj(tmp_istota->liczba_sekund_potrzeby);

dl_dzialania_ss=dl_dzialania_ss-tmp_istota->liczba_sekund_potrzeby;
tmp_istota_pop=tmp_istota;

system("CLS");
} else dl_dzialania_ss=0;


} while (dl_dzialania_ss>0);

system ("CLS");
cout <<"\n\n\n\t\t***********************************************\n";
cout <<"\t\t*                KONIEC KARMIENIA            *\n";
cout <<"\t\t***********************************************\n\n\n";
cout <<"\n\n\n\t\t_______________________________________________\n";
cout <<"\t\t>            NAKARMIONE I SZCZESLIWE          <\n";
cout <<"\t\t_______________________________________________\n\n\n";
B.Wypisz();

cout <<"\n\n\n\t\t_______________________________________________\n";
cout <<"\t\t>                KOTY ZANIEDBANE              <\n";
cout <<"\t\t_______________________________________________\n\n\n";
A.Wypisz();


}

int main()
{
for (int i=1;i<10;i++){
stringstream s_nazwa;
s_nazwa<<"kot_"<<i;
A.Dodaj(new istota(s_nazwa.str()));}

Menu();

}


