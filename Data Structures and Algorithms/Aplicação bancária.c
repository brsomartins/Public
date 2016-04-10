/*
  Uma quantia de R$ 500 é investida em uma aplicação que paga juros de 10% capi-
  talizados anualmente. Faça uma função recursiva que calcule a quantia total de
  aplicação no início do n-ésimo ano. Lembre-se que no início do primeiro ano
  tem-se aplicados R$ 500.
*/

int n;
float juros (int n);

main()
{
      printf ("Entre com o tempo de aplicacao (em anos): ");
      scanf ("%d", &n);
      printf ("\nO valor inicial aplicado rendeu R$ %.2f nesse(s) %d ano(s).", juros (n), n);
      getch();
}

float juros (int n)
{
      float t = 500;
      if (n == 1)
         return t;
      else
          t = juros (n - 1) + juros (n - 1) * 0.1;
      return t;
}
