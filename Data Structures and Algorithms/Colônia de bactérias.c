/*
  Em um experimento, uma determinada colônia de bactérias tem uma população de
  50 mil. A população é contada a cada duas horas e, ao final de cada intervalo
  de duas horas, a população triplica. Faça uma função recursiva que calcule o
  número de bactérias presentes no n-ésimo período de tempo.
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
