/*
  Faça uma função recursiva que calcule e retorne o valor de:
  s(n) = 1 + 1/1! + 1/2! + 1/3! + ... + 1/n!
*/

// Não está funcionando corretamente

int a, fat (int n);
float sifat (float n);

main(){
       printf ("Entre com um numero: ");
       scanf ("%d", &a);
       if (a < 0)
          printf ("\nErro!");
       else
           printf ("\ns(%d) = %.2f.", a, sifat(a));
       getch();
}

int fat (int n){
    int f;
    if (n == 0)
       return 1;
    else
        f = n * fat(n - 1);
    return f;
}

float sifat (float n){
      float sif;
      if (n <= 1)
         return 1;
      else
          sif = 1 / fat(n) + sifat(n - 1);
      return sif;
}
