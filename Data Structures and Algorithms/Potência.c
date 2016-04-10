/*
  Faça uma função recursiva que calcule e retorne a função potência x^z, sendo x
  real, e z um inteiro.
*/

// Faltam as condicionais no local indicado

float a, pot (float x, int z);
int b;

main(){
       printf ("Entre com a base da potencia: ");
       scanf ("%f", &a);
       printf ("Entre com o expoente da potencia: ");
       scanf ("%d", &b);
       // Faltam as condicionais
       printf ("O resultado da exponenciacao e': %f.", pot(a, b));
       getch();
}

float pot (float x, int z){
      float p;
      if (z == 0)
         return 1;
      else
          if (z > 0)
             p = x * pot(x, z - 1);
          else
              p = 1 / pot (x, -z);
      return p;
}
