#include <iostream>
using namespace std;

main()
{
      int tempo;
      float litros_usados, velocidade, distancia;
      
      cout << "Entre com o tempo gasto e a velocidade media, respectivamente.\n";
      cin >> tempo;
      cin >> velocidade;
      
      distancia = tempo * velocidade;
      litros_usados = distancia / 10;
      
      cout << "\nVelocidade media: " << velocidade << " km/h.\n";
      cout << "Tempo gasto: " << tempo << " min.\n";
      cout << "Distancia percorrida: " << distancia << " m.\n";
      cout << "Litros gastos: " << litros_usados << " L.\n\n";
      
      system ("pause");
}
