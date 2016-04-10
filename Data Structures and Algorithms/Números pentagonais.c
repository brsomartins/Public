/*
  Os primeiros membros da Associa��o de Pit�goras definiram n�meros poligonais
  como n�meros de pontos em determinadas figuras geom�tricas. Os primeiros n�me-
  ros pentagonais s�o:
      
  1   5   12    22
    4   7    10
      3    3
    
  Fa�a uma fun��o recursiva para encontrar o n-�simo n�mero pentagonal.
*/

int n;
int pen (int n);

main()
{
      printf ("Entre com um numero: ");
      scanf ("%d", &n);
      printf ("O %do numero da serie de numeros pentagonais e': %d.", n, pen (n)); 
      getch();
}

int pen (int n)
{
    int p;
    if (n == 1)
       return 1;
    else
        p = pen (n - 1) + 3 * (n - 1) + 1;
    return p;
}
