//Zadanie 704(K&R, 5.5)
//Napisać własną wersję procedury char *strncpy(s,ct,n).
//Procedura kopiuje co najwyżej n znaków tekstu z ct do s.
//Jeśli ct ma mniej niż n znaków, dopełnia s znakami '\0'; zwraca s.

#include<iostream>
#include<cstring>

using namespace std;

void KopiujZnaki (char *dokad, char *skad, int ile_znakow);

int main()
{
  char napis[30]="kotek wlazl na plotek";
  char napis2[30]="kocur";

cout << "Funkcja biblioteczna: \t"<< strncpy(napis, napis2, 5)<<endl;

	char napis3[30]="kotek wlazl na plotek";
	char napis4[30]="kocur";

KopiujZnaki(napis3, napis4, 5);

cout << "Funkcja KopiujZnaki: \t" <<napis<<endl;

}

void KopiujZnaki (char *dokad, char *skad, int ile_znakow)
{
for (int i=0;i<ile_znakow;i++)
  *dokad++=*skad++;
}
