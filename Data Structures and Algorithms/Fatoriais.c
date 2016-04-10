/*
  Exemplo de fatoriais com recursão.
*/

int a, fat (int n);

main(){
       printf ("Digite um numero: ");
       scanf ("%d", &a);
       if ((a < 0) || (a > 12))
          printf ("\nErro!");
       else
           printf ("\n%d! = %d.", a, fat(a));
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
