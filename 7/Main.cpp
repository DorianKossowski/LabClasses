#include "Main.h"

#include<iostream>

int main ()
{
  std::cout<<"=== First Array ===\n";
  int size1 [] = {3, 9, 5, 1};
  Array* firstArray = 0;
  CreateArray (firstArray, size1, sizeof(size1)/sizeof(int));
  size1[1] = 100;
  FillWith(firstArray, 1);
  Print (*firstArray);          // 1 1 1
                                // 1 1 1 1 1 1 1 1 1
                                // 1 1 1 1 1
                                // 1

  
  std::cout<<"\nmodified\n";
  SetElement(2, 4, &firstArray, 10);
  SetElement(0, 2, &firstArray, 11);
  SetElement(1, 1, &firstArray, 12);

  SetElement(2, 8, &firstArray, 12); // Index out of bounds

  Print (*firstArray);           // 1 1 11
                                // 1 12 1 1 1 1 1 1 1
                                // 1 1 1 1 10
                                // 1

  PrintMax (firstArray);        // maximum
                                // max 0: 11
                                // max 1: 12
                                // max 2: 10
                                // max 3: 1
                                // global max: 12
  
  std::cout<<"\n=== Second Array ===\n";

  const int size2 [] = {7, 2};
  Array* secondArray = 0;
  CreateArray (secondArray, size2, sizeof(size2)/sizeof(int));
  FillWith(secondArray, 5);

  Print (*secondArray);          // 5 5 5 5 5 5 5
                                //5 5
  
  SetElement(0, 4, &secondArray, 10);
  SetElement(2, 1, &secondArray, 12); // Index out of bounds
  SetElement(1, 1, &secondArray, 12);

  std::cout<<"\nmodified\n";

  Print (*secondArray);          // 5 5 5 5 10 5 5
                                // 5 12

  Clear (&firstArray);
  Clear (&secondArray);
  
  return 0;
}
/* wynik dzialania programu:
=== First Array ===
1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1
1

modified
Index out of bounds
1 1 11
1 12 1 1 1 1 1 1 1
1 1 1 1 10
1

maximum
max 0: 11
max 1: 12
max 2: 10
max 3: 1
global max: 12

=== Second Array ===
5 5 5 5 5 5 5
5 5
Index out of bounds

modified
5 5 5 5 10 5 5
5 12
*/
