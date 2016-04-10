/*
  Transforme a seguinte função não recursiva em uma função recursiva:

  main()
  {
        int n;
        
        void primo (int n, int i, int cont)
        {
             for (i = 1; i <= n; i++)
                 if ((n % i) == 0);
                    cont++;
             if (cont == 2)
                printf ("\nO numero e' primo.");
             else
                 printf ("\nO numero nao e' primo.");
        }
        
        printf ("Entre com um numero: ");
        scanf ("%d", &n);
        primo (n, 1, 0);
        getch();
  }
*/

main()
{
      int n;
        
      void primo (int n, int i, int cont)
      {
           if (i > n)
              if (cont == 2)
                 printf ("\nO numero e' primo.");
              else
                  printf ("\nO numero nao e' primo.");
           else
           {
               if ((n % i) == 0)
                  cont++;
               primo (n, i + 1, cont);
           }
      }

      printf ("Entre com um numero: ");
      scanf ("%d", &n);
      primo (n, 1, 0);
      getch();
}
