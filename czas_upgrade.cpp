#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

class Czas
{
int liSek;
vector<string> split(string strValue);
string format(int hh,int mm,int ss);

public:

Czas ();
Czas (string sCzas,string sMaska);
Czas (int hh,int mm,int ss);
Czas (int sek );
Czas (Czas &);

~Czas(){}

Czas&  operator = (const Czas &a);
Czas& operator = (string sCzas);

friend ostream & operator << (ostream &wy, Czas &a);
friend Czas operator + (Czas a,Czas b);
friend Czas operator - (Czas a,Czas b);
friend bool operator == (Czas &a, Czas &b);
friend bool operator != (Czas &a, Czas &b);
friend bool operator > (Czas &a, Czas &b);
friend bool operator < (Czas &a, Czas &b);
friend bool operator >= (Czas &a, Czas &b);
friend bool operator <= (Czas &a, Czas &b);
};

struct CzasPracy
{
    string *nazwisko;
    Czas *start;
    Czas *finish;
};

//*******************************************KONSTRUKTORY************************************************

Czas::Czas ()
{liSek=0;}
//______________________

Czas::Czas (Czas &a)
{liSek=a.liSek;}
//______________________

Czas::Czas (int hh,int mm,int ss)
{
liSek=ss+60*mm+3600*hh;
if(liSek>86400) liSek=liSek%86400;
}
//______________________
Czas::Czas (int sek)
{
liSek=sek;
if(liSek>86400)  liSek=liSek%86400;
}
//______________________
Czas::Czas (string sCzas,string sMaska)
{
vector<string> vec_sCzas;
vector<string> vec_sMaska;
vec_sCzas=split(sCzas);
vec_sMaska=split(sMaska);

int cz_tmp=0;
for (int  t = 0; t<vec_sMaska.size();t++)
{
	if	(vec_sMaska[t]=="hh"){
	cz_tmp=cz_tmp+atoi(vec_sCzas[t].c_str())*3600;
	}

	if	(vec_sMaska[t]=="mm"){
	cz_tmp=cz_tmp+atoi(vec_sCzas[t].c_str())*60;
	}

	if	(vec_sMaska[t]=="ss"){
	cz_tmp=cz_tmp+atoi(vec_sCzas[t].c_str());
	}
}
liSek=cz_tmp;
if(liSek>86400)   liSek=liSek%86400;
}

//*************************************OPERATORY***********************
 bool operator == (Czas &a, Czas &b)
{    return a.liSek==b.liSek;}

 bool operator != (Czas &a, Czas &b)
{    return a.liSek != b.liSek;}

 bool operator > (Czas &a, Czas &b)
{    return a.liSek > b.liSek;}

 bool operator < (Czas &a, Czas &b)
{    return a.liSek < b.liSek;}

 bool operator >= (Czas &a, Czas &b)
{    return a.liSek >= b.liSek;}

 bool operator <= (Czas &a, Czas &b)
{    return a.liSek <= b.liSek;}

ostream & operator << (ostream &wy, Czas &a)
{
int hh,mm,ss,tmp;

hh=a.liSek/3600;
tmp=a.liSek%3600;
mm=tmp/60;
ss=tmp%60;

wy <<a.format(hh,mm,ss);

return wy;
}

Czas operator + (Czas a,Czas b)
{
int tmp;
tmp=a.liSek+b.liSek;
Czas out(tmp);
return out;
}

Czas operator - (Czas a,Czas b)
{
int tmp;
tmp=a.liSek-b.liSek;

if(tmp<0) tmp=0;

Czas out(tmp);
return out;
}

Czas&  Czas::operator = (const Czas &a)
{
    liSek=a.liSek;
    return *this;
}

Czas& Czas::operator = (string sCzas)
{
Czas out(sCzas,"hh:mm:ss");
liSek=out.liSek;
return *this;
}

//****************************METODY******************************

string Czas::format(int hh,int mm,int ss)       //formatowanie do druku
{
stringstream s_hh,s_mm,s_ss;

if(hh<10) {s_hh<<"0"<<hh<<":"; } else { s_hh<<hh<<":"; }
if(mm<10) {s_mm<<"0"<<mm<<":"; } else { s_mm<<mm<<":"; }
if(ss<10) {s_ss<<"0"<<ss; } else { s_ss<<ss; }

return s_hh.str()+s_mm.str()+s_ss.str();
}

vector<string> Czas::split(string str)  //czytanie stringa i maski
{
    vector<string> Result;
    int start=0;
    int end=0;
	char separator=':';
    end = str.find_first_of(separator, start);
    while (end != string::npos)
    {
        Result.push_back(str.substr(start, end-start));
        start = end+1;
        end = str.find_first_of(separator, start);
        if(end==string::npos)
        {
           Result.push_back(str.substr(start));
        }
    }
    return Result;
}

//*********************************************************************
//*********************************************************************
void PerfectWorkingHours (CzasPracy Tab[], int n);
void PrintWorkingHours (CzasPracy Tab[], int n);
void Randomize(CzasPracy Tab[], int n);
void GetNames(CzasPracy Tab[], int n);

//_____________________________PROGRAM TESTUJACY________________________________________
int main()
{
CzasPracy Tab[40];
PerfectWorkingHours (Tab, 40) ;
Randomize(Tab, 40);
GetNames(Tab, 40);
PrintWorkingHours (Tab, 40);
}

//__________________________________________________________________
//________________________FUNKCJE___________________________________

void PerfectWorkingHours (CzasPracy Tab[], int n)

{
    for (int i=0;i<n;i++)
{
  Tab[i].start=new Czas("08:00:00", "hh:mm:ss");
  Tab[i].finish=new Czas("16:00:00", "hh:mm:ss");
}
}
//__________________________________________________________________________

void GetNames (CzasPracy Tab[], int n)
{
    vector <string> names;
    string name;
    fstream we;
    we.open("pracownicy.txt");

    while (we>>name)
    {
        names.push_back(name);
    }

    for (int i=0;i<n;i++)
    {
        Tab[i].nazwisko=new string;
        *Tab[i].nazwisko=names[i];
    }
}

//__________________________________________________________________________

void PrintWorkingHours (CzasPracy Tab[], int n)
{
    string comment;
    Czas z(7,0,0);
    Czas o (8,0,0);
    Czas p (9,0,0);

    cout <<setw(15)<< "pracownik"<< setw(15)<<"poczatek"<<setw(15)<<"koniec"
    <<setw(15)<<"czas pracy"<<setw(15)<<"komentarz\n\n";

        for (int i=0;i<n;i++)
    {
    Czas b;
    b=*Tab[i].finish-*Tab[i].start; //roznica finish-start - realny czas pracy dla kazdego
    if (b<z) comment = "zwolnienie";
    else if (b<o) comment ="ostrzezenie";
    else if (b<p) comment ="podwyzka";
    else comment = "awans";

    cout << setw(15)<<*Tab[i].nazwisko<<setw(15)<< *Tab[i].start<<setw(15)
    <<*Tab[i].finish<<setw(15)<<b<<setw(15)<<comment<< endl;
    }
}

//__________________________________________________________________________

void Randomize(CzasPracy Tab[], int n)
{
    srand(time(0));
    for (int i=0;i<n;i++)
    {
        int n=rand()%2700;
        Czas a(n);
         if (n%2==0)    //jesli n parzyste - dodajemy, nieparzyste - odejmujemy
        *Tab[i].start=*Tab[i].start+a;
        else
        *Tab[i].start=*Tab[i].start-a;

         int m=rand()%4500;
        Czas b(m);
         if (m%2==0)
        *Tab[i].finish=*Tab[i].finish+b;
        else
        *Tab[i].finish=*Tab[i].finish-b;
    }
}
