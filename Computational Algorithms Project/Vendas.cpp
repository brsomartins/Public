#include <iostream>
using namespace std;

main()
{
      int i, qtd [3], maisvend;
      float valor [3], total = 0, valormaisvend;
      
      for (i = 0; i < 3; i++)
      {
          cout << "Entre com o preco do objeto " << i + 1 << ". ";
          cin >> valor [i];
          cout << "Entre com a quantidade de vendas do objeto " << i + 1 << ". ";
          cin >> qtd [i];
          cout << "\n";
      }

      cout << "================================================================================\n";
      
      for (i = 0; i < 3; i++)
      {
          cout << "OBJETO " << i + 1 << ":";
          cout << "\nQuantidade vendida:\t" << qtd [i];
          cout << "\nValor unitario:\t\tR$ " << valor [i];
          cout << "\nValor total das vendas:\tR$ " << qtd [i] * valor [i];
          cout << "\n\n";
          total += qtd [i] * valor [i];
      }
      
      cout << "================================================================================\n";
      
      cout << "Valor total das vendas de todos os objetos:\tR$ " << total;
      cout << "\nComissao do vendedor:\t\t\t\tR$ " << 650 + total * 0.05 << "\n\n";
      
      cout << "================================================================================\n";
      
      maisvend = 0;
      
      for (i = 1; i < 3; i++)
      {
          if (qtd [i] > qtd [maisvend])
          {
             maisvend = i;
             valormaisvend = valor [i];
          }
      }
      
      cout << "O objeto " << maisvend + 1 << ", que custa R$ " << valormaisvend << ", foi o mais vendido.\n\n";
      
      system ("pause");     
}
