/*
  Os primeiros membros da Associação de Pitágoras definiram números poligonais
  como números de pontos em determinadas figuras geométricas. Os primeiros núme-
  ros pentagonais são:
      
  1   5   12    22
    4   7    10
      3    3
    
  Faça uma função recursiva para encontrar o n-ésimo número pentagonal.
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
