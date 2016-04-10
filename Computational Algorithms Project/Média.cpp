#include <iostream>
using namespace std;

main()
{
      float n1, n2, n3, n4, n5, n6, na, nb, media;
      
      cout << "Entre com as seis notas.\n";
      cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6;
      
      if ((n1 < 0) && (n1 > 10) || (n2 < 0) && (n2 > 10) ||
          (n3 < 0) && (n3 > 10) || (n4 < 0) && (n4 > 10) ||
          (n5 < 0) && (n5 > 10) || (n6 < 0) && (n6 > 10))
          cout << "Alguma(s) nota(s) atribuidas nao estao no intervalo entre 0 e 10.";
      else
      {
          na = n1;
          nb = n1;
          
          if (n2 > na)
             na = n2;
          if (n2 < nb)
             nb = n2;
             
          if (n3 > na)
             na = n3;
          if (n3 < nb)
             nb = n3;
             
          if (n4 > na)
             na = n4;
          if (n4 < nb)
             nb = n4;
             
          if (n5 > na)
             na = n5;
          if (n5 < nb)
             nb = n5;
             
          if (n6 > na)
             na = n6;
          if (n6 < nb)
             nb = n6;
             
          media = ((n1 + n2 + n3 + n4 + n5 + n6) - (na + nb)) / 4;
          
          cout << "\nA media das notas, descartando a maior e a menor, e': " << media << ".\n\n";
      }
      
      system ("pause");
}
