/*
  Os primeiros membros da Associação de Pitágoras definiram números poligonais
  como números de pontos em determinadas figuras geométricas. Os primeiros núme-
  ros triangulares são:
                    .
            .      . .
      .    . .    . . .
  .  . .  . . .  . . . .
  1   3     6      10
    2    3      4
    
  Faça uma função recursiva para encontrar o n-ésimo número triangular.
*/

int n;
int tri (int n);

main()
{
      printf ("Entre com um numero: ");
      scanf ("%d", &n);
      printf ("O %do numero da serie de numeros triangulares e': %d.", n, tri (n)); 
      getch();
}

int tri (int n)
{
    int t;
    if (n == 1)
       return 1;
    else
        t = tri (n - 1) + n;
    return t;
}
