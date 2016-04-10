/*
  Faça uma função recursiva para transformar um número binário em decimal.
  Ex.: (1011)_2 = 1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 1 * 2^0 = (11)_10
*/

int n;
int trans (int n, int i);

main()
{
      printf ("Entre com um numero binario: ");
      scanf ("%d", &n);
      printf ("\n%d e' equivalente ao decimal %d.", n, trans (n, 1));
      getch();
}

int trans (int n, int i)
{
    int t;
    if (n == 0)
       return 0;
    else
        t = (n % 10) * i + trans (div (n, 10), 2 * i);
    return t;
}
