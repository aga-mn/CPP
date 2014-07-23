#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

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

//string  format(string s_maska);

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
    Czas *start;
    Czas *finish;
};

CzasPracy Tab[30];
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
if(liSek>86400) liSek=liSek%86400;            //liSek=liSek-int(liSek/86400)*86400;
}
//______________________
Czas::Czas (int sek)
{
liSek=sek;
if(liSek>86400)  liSek=liSek%86400;              //liSek=liSek-int(liSek/86400)*86400;
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
if(liSek>86400)   liSek=liSek%86400;              //liSek=liSek-int(liSek/86400)*86400;
}

//*************************************OPERATORY******************************************
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

//*******************************************METODY*****************************************************

string Czas::format(int hh,int mm,int ss){
stringstream s_hh,s_mm,s_ss;

if(hh<10) {s_hh<<"0"<<hh<<":"; } else { s_hh<<hh<<":"; }
if(mm<10) {s_mm<<"0"<<mm<<":"; } else { s_mm<<mm<<":"; }
if(ss<10) {s_ss<<"0"<<ss; } else { s_ss<<ss; }

return s_hh.str()+s_mm.str()+s_ss.str();
}

/*string  Czas::format(string s_maska)
{
vector<string> vec_sMaska;
vec_sMaska=split(sMaska);

int hh,mm,ss,tmp;
hh=liSek/3600;
tmp=liSek%3600;
mm=tmp/60;
ss=tmp%60;

return format(hh,mm,ss);

}*/

vector<string> Czas::split(string str)
{
    vector<string> vecstrResult;
    int startpos=0;
    int endpos=0;
	char separator=':';
    endpos = str.find_first_of(separator, startpos);
    while (endpos != -1)
    {
        vecstrResult.push_back(str.substr(startpos, endpos-startpos)); // add to vector
        startpos = endpos+1; //jump past sep
        endpos = str.find_first_of(separator, startpos); // find next
        if(endpos==-1)
        {
            //lastone, so no 2nd param required to go to end of string
            vecstrResult.push_back(str.substr(startpos));
        }
    }
    return vecstrResult;
}

//******************************************************************************************************
//******************************************************************************************************
void PerfectWorkingHours ();
void PrintWorkingHours ();
void Randomize();

int main()
{
PerfectWorkingHours () ;
Randomize();
PrintWorkingHours ();

}

void PerfectWorkingHours ()

{
    for (int i=0;i<30;i++)
{
  Tab[i].start=new Czas("08:00:00", "hh:mm:ss");
  Tab[i].finish=new Czas("16:00:00", "hh:mm:ss");
}
}

void PrintWorkingHours ()
{
    string comment;
    Czas z(7,0,0);
    Czas o (8,0,0);
    Czas p (9,0,0);
        for (int i=0;i<30;i++)
{

    Czas b;
    b=*Tab[i].finish-*Tab[i].start;
    if (b<z) comment = "zwolnienie";
    else if (b<o) comment ="ostrzezenie";
    else if (b<p) comment ="podwyzka";
    else comment = "awans";

  cout << *Tab[i].start<<" - "<<*Tab[i].finish<<" czas pracy: "<<b<<"  "<<comment<< endl;
}
}

void Randomize()
{
    srand(time(0));
    for (int i=0;i<30;i++)
    {
        int n=rand()%2700;
        Czas a(n);
         if (n%2==0)
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
