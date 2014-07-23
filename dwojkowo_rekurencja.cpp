#include <iostream>

using namespace std;

void dwojkowo(int liczba);


int main()
{
    cout<<"Podaj liczbe ";
    int n;
    cin>>n;
    dwojkowo(n);

}

void dwojkowo(int liczba)
{
    int reszta=liczba%2;
    if (liczba>1)

    {
        dwojkowo(liczba/2);
    }
    cout <<reszta;
}
