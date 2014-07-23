#include<iostream>
#include<cstring>

using namespace std;

int LiczSpacje(char *s);

int main()

{char napis[]= "Wlazł kotek na płotek i mruga";

cout << napis << "\nspacje: "<<LiczSpacje(napis);
}

int LiczSpacje(char *s)
{
    int ile=0;

  while(*s!='\0'){
	  
	      if (*s==' ')
          {ile++;}
		   s++;
    }
    return ile;
}
