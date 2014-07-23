//Zadanie 608
//Napisac funkcje reverse(s,t), która bada, czy jeden z lancuchów s i t
//nie jest odwróceniem drugiego lancucha. Funkcja zwraca 1 jesli jest odwróceniem,
//a 0 w przypadku przeciwnym.

#include<iostream>
#include<cstring>

using namespace std;

int reverse (char *s,char *t);

int main()
{
    char n1 [10]="kot szary";
    char n2 [10]="kot bury";
    char n3 [10]="yrub tok";
    char n4 [10]="kajak";

    cout << reverse(n1,n2)<<endl;
    cout << reverse(n2,n3)<<endl;
    cout << reverse(n4,n4)<<endl;

    char zz;
    cin >> zz;
}

//**************************************************************************************************

int reverse (char *s,char *t)
{
    int m=strlen(s);
    int n=strlen(t);

    bool czy_rowne=true;

    if (m!=n) {czy_rowne=false;}

    else
    {
        int i=0;

        while(czy_rowne && i<n)
        {
            if (s[i] != t[n-1-i])
            {czy_rowne=false;}
            i++;
         }
     }

    if (!czy_rowne) return 0;
    else return 1;
}
