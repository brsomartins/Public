/*
  Os primeiros membros da Associa��o de Pit�goras definiram n�meros poligonais
  como n�meros de pontos em determinadas figuras geom�tricas. Os primeiros n�me-
  ros triangulares s�o:
                    .
            .      . .
      .    . .    . . .
  .  . .  . . .  . . . .
  1   3     6      10
    2    3      4
    
  Fa�a uma fun��o recursiva para encontrar o n-�simo n�mero triangular.
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
