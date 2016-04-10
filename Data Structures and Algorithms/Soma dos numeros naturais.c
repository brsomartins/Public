/*
  Faça uma função recursiva que calcule a soma dos n primeiros números naturais.
*/

int a, soma (int n);

main(){
       printf ("Entre com um numero: ");
       scanf ("%d", &a);
       if (a < 0)
          printf ("\nErro!");
       else
           printf ("\nA soma dos numeros %d primeiros numeros naturais e': %d.", a, soma(a));
       getch();
}

int soma (int n){
    int s;
    if (n == 0)
       return 0;
    else
        s = n + soma(n - 1);
    return s;
}
