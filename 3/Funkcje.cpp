#include "Main.h"
#include<iostream>
using namespace std;

unsigned int wielkoscKsiegi = 0;

void UtworzCzar(const char* tekst,char** wskP,char** wskK)
{
	//oblicz dlugosc czaru
	const size_t dlugosc = strlen(tekst);
	
	//stworz tablice i uzupelnij ja czarem
	char* nowyCzar = new char[dlugosc + 1];	//+1 na znak "\0"
	memset(nowyCzar,0,dlugosc + 1);
	strcat(nowyCzar, tekst);

	//przypisz wskazniki do poczatku i konca czaru
	*wskP = nowyCzar;
	*wskK = nowyCzar + dlugosc;

}
void RzucCzar(char* wskP,char* wskK)
{
	//oblicz dlugosc czaru
	const int dlugosc = wskK - wskP;

	//stworz tymcz wskaznik i przypisz do niego poczatek czaru
	char* tymczWsk = wskP;
	for(int i=0; i<dlugosc; i++)
	{
		cout<<*(tymczWsk++);
	}
	cout<<"\n";
}
void DodajCzar (char*** ksiega,Czary wskP,Czary wskK)
{
	//stworz wieksza tymcz tablice
	char** tymczKsiega = new char*[wielkoscKsiegi + 1];

	const size_t dlugosc = wskK - wskP;
	char* nowyCzar = new char[dlugosc + 1]; //+1 na znak "\0"
	memset(nowyCzar,0,dlugosc + 1);
	strncat(nowyCzar, wskP, dlugosc);

	//przepisz aktualne czary z ksiegi
	for(int i=0; i<wielkoscKsiegi; i++)
	{
		tymczKsiega[i] = (*ksiega)[i];
	}

	//dodaj nowy czar 
	tymczKsiega[wielkoscKsiegi] = nowyCzar;

	//usun stara ksiege
	delete[] *ksiega;

	//przypisz nowa ksiege do wskaznika
	*ksiega = tymczKsiega;

	//zwieksz ilosc czarow w ksiedze
	wielkoscKsiegi++;
}
void Czytaj(char*** ksiega)
{
	cout<<"KSIEGA CZAROW"<<endl;
	for(int i=0; i<wielkoscKsiegi; i++)
	{
		cout<<(*ksiega)[i]<<"\n"<<endl;
	}
}
void SpalKsiege(KsiegaCzarow ksiega)
{
	for(int i=0; i<wielkoscKsiegi; i++)
	{
		delete[] ksiega[i];
	}
	delete[] ksiega;
}
void ZniszczCzar(Czary wskP,Czary wskK)
{
	delete[] wskP;
	wskP = 0;
	wskK = 0;
}