/*
  Em um experimento, uma determinada col�nia de bact�rias tem uma popula��o de
  50 mil. A popula��o � contada a cada duas horas e, ao final de cada intervalo
  de duas horas, a popula��o triplica. Fa�a uma fun��o recursiva que calcule o
  n�mero de bact�rias presentes no n-�simo per�odo de tempo.
*/

int n, bact (int n);

main()
{
      printf ("Entre com o periodo de tempo: ");
      scanf ("%d", &n);
      printf ("\nO numero de bacteria apos %d periodo(s) de tempo e' de %d.", n, bact (n));
      getch();
}

int bact (int n)
{
      int b = 50000;
      if (n == 1)
         return b;
      else
          b = bact (n - 1) * 3;
      return b;
}
