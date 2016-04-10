/*
  Faça uma função recursiva que calcule o produto de dois números, sem utilizar
  o operador "*".
*/

int a, b, m = 0;
void mult (a, b);

main()
{
      printf ("Entre com os dois numeros a serem multiplicados:\n");
      scanf ("%d%d", &a, &b);
      mult (a, b);
      getch();
}

void mult (a, b)
{
     if (b > 0)
     {
        m = m + a;
        b--;
        mult (a, b);
     }
     else
         printf ("\nO resultado e': %d", m);
}
