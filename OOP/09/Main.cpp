// Nazwa pliku wykonywalnego: PolyList

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Proszę napisać polimorficzną listę przechowujacej dane jako wartosci.
// W sklad takiej listy wchodza elementy Node, ktore musza byc dostosowane 
// do roznych typow przechowywanych.
// Czyli gdzies w srodku musi byc typ: Node<int> Node<float> 
// -> narzuca sie odpowiednia hierarchia.
// UWAGA: Wirtualne zachowanie potrzebne w implementacji isType mozna uzyskac po 
// zamanie typu na jego identyfikator (RTTI)
// UWAGA: Mozna kozystac z dokumentacji mechanizmu RTTI:
// http://en.cppreference.com/w/cpp/language/typeid
// https://en.wikibooks.org/wiki/C%2B%2B_Programming/RTTI

// W przypadku "metody" get zkladamy ze typy pasuja (mozna to sprawdzic za pomoca isType) 
// a wiec mozna wykonac odpowiednie rzutowanie.
// UWAGA: Prosze nie zapomniec o sprzatnieciu pamieci (virtual ~)

// Pliku Main.cpp, nie wolno modyfikowac.
// Ostateczny program powinien byc przyjazny dla programisty 
// (miec czytelny i dobrze napisany kod). 

// Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL.

#include <iostream>
#include "List.h"


int main() {
  using namespace std;

  List lista;
  lista.add<int>(7);
  lista.add<float>(4.56);   // dodaje na poczatku
  lista.add<double>(4.566); // to jest teraz pierwsza

  cout << boolalpha;

  const TNode<double>* f = dynamic_cast<const TNode<double>*>(lista.head());
  cout << f->get()<<endl;
  cout << lista.head()->isType<float>()  << endl;
  cout << lista.head()->isType<int>()  << endl;

  cout << lista.head()->next()->isType<float>()  << endl;
  cout << lista.head()->next()->isType<int>()  << endl;
  cout << lista.head()->next()->next()->isType<int>()  << endl;

  cout << List::get<double>(lista.head()) << std::endl; // pierwszy jest double
  
}
/* wynik
4.566
false
false
true
false
true
4.566
 */
