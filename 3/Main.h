#ifndef MAIN_H
#define MAIN_H

#include <cstring>

typedef char** KsiegaCzarow;
typedef char* Czary;

//dodaj do listy nowy czar 
void UtworzCzar(const char* tekst,char** wskP,char** wskK);
//wypisz czar
void RzucCzar(char* wskP,char* wskK);
//dodaj czar do ksiegi czarow
void DodajCzar (char*** ksiega,Czary wskP,Czary wskK);
//wypisz czary nalezace do ksiegi
void Czytaj(char*** ksiega);	
//zwolnij pamiec z ksiegi
void SpalKsiege(KsiegaCzarow ksiega);
//zwolnij pamiec z poszczegolnych czarow
void ZniszczCzar(Czary wskP,Czary wskK);
#endif