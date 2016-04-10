/*
  Faça uma função recursiva que, dado uma letra x no intervalo fechado A-Z, es-
  creva a sequência abaixo:
         
  A             (caso a letra inserida seja "D")
  A B A
  A B C B A
  A B C D C B A
  A B C B A
  A B A
  A
*/

char a;
void mostra (char a, char i);

main()
{
      printf ("Entre com uma letra: ");
      scanf ("%c", &a);
      printf ("\n");
      mostra (a, 'A');
      getch();
}

void mostra (char a, char i)
{
     if (i <= a)
     {
        printf ("%c ", i);
        mostra (a, i++);
     }
}
