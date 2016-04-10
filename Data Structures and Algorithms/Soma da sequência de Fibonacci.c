/*
  Faça uma função recursiva que calcule a soma dos n primeiros termos da sequên-
  cia de Fibonacci.
*/

int a, sfibo (int n), fibo (int n);

main(){
       printf ("Entre com um numero: ");
       scanf ("%d", &a);
       if (a <= 0)
          printf ("\nErro!");
       else
           printf ("\nA soma dos %d primeiros termos da sequencia de Fibonacci e': %d.", a, sfibo(a));
       getch();
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
