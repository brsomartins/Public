/*
  Faça uma função recursiva que calcule e retorne o valor de:
  s(n) = 1!/1 - 1!/2 - 2!/4 + 3!/7 - 5!/12 +- ... } n parcelas
*/

// Não está funcionando corretamente

int a, fat (int n), fibo (int n), sfibo (int n);
float soma (int n);

main(){
       printf ("Entre com um numero: ");
       scanf ("%d", &a);
       if (a <= 0)
          printf ("\nErro!");
       else
           printf ("\ns(%d) = %.2f.", a, soma(a));
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

int fibo (int n){
    int f;
    if (n <= 3)
       if (n == 1)
          return 0;
       else
           return 1;
    else
        f = fibo(n - 1) + fibo(n - 2);
    return f;
}

int sfibo (int n){
    int sf;
    if (n == 1)
       return 0;
    else
        sf = fibo(n) + sfibo(n - 1);
    return sf;
}

float soma (int n){
      float s;
      if (n == 1)
         return 1;
      else
          if ((sfibo(n) % 2) == 0)
             s = soma(n - 1) - (fat(fibo(n)) / sfibo(n));
          else
              s = soma(n - 1) + (fat(fibo(n)) / sfibo(n));
      return s;
}
