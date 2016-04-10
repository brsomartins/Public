/*
  Faça uma função recursiva que calcule o n-ésimo termo da sequência de
  Fibonacci.
*/

int a, fibo (int n);

main(){
       printf ("Entre com um numero: ");
       scanf ("%d", &a);
       if (a <= 0)
          printf ("\nErro!");
       else
           printf ("\nO %do termo da sequencia de Fibonacci e': %d.", a, fibo(a));
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
