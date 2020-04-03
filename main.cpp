#include <sstream>
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

class zmiana{
       ifstream plik1;
       ofstream plik2;
       string orginal[1000];
       string sort[1000];

  public:
        zmiana();
        ~zmiana();
       
        void wczytaj();     
		string stringSort(string s);  
};

zmiana::zmiana(){ 
    plik1.open("c:\\palindromy.txt");
    plik2.open("c:\\wynikJSON.txt");
}

void zmiana::wczytaj(){
	
	string napis;
	int index;
	int i=0;
	
	plik2<<"[";
	
	while(!plik1.eof()){ 
        plik1>>napis;
        
        orginal[i]=napis;
		sort[i]=stringSort(napis);
		cout<<sort[i]<<endl;;
		i++;
	}
	
	for(int j=0;j<i;j++){
		if(sort[j]==sort[j+1]){
			plik2<<"{\"slowo"<<"\":\""<<orginal[j]<<"\",\"anagram\":\""<<orginal[j+1]<<"\"},";
		}
	}
	
	plik2<<"]";

}

string zmiana::stringSort(string s){
	
	int t[256]; //dane wejsciowe
	string wynik;
	
	//przypisanie kazdej komurce wartosci
	for (int i=0; i<=256; i++)
        t[i]=0;

    //zapelnienie tablicy t[i] danymi
    for (int i=0; i<=s.length()-1; i++)
    {
        t[i]=(int)s[i];
    }

    int los1 = rand()%s.length();
    int los2 = rand()%s.length();
    
    srand(time(NULL));
    
    int help;
    
    help = t[los1];
    t[los1] = t[los2];
    t[los2] = help;
   	
   	for (int i=0; i<=s.length()-1; i++)
    {
        wynik+=(char)t[i];
    }
	
	return wynik;
	
}

zmiana::~zmiana(){
    plik1.close();
    plik2.close();
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	zmiana change; 
    change.wczytaj();
	
	return 0;
}
