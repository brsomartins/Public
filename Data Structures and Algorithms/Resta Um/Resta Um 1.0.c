#define TAM 7;
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct desc
{
       struct desc2 *prim, *ult;
       int qcolunas;
};
       
struct desc *inicio;

struct desc2
{
       struct ptr *ant, *prox;
       struct desc2 *ant2, *prox2;
       int qlinhas;
};
       
struct desc2 *aux3, *aux4;
       
struct ptr
{
       struct ptr *prox, *ant;
       char dado1, dado2;;
};
       
struct ptr *aux, *aux2, *aux5;

void criamatriz()
{
     int i, j;
     inicio = (struct desc *) malloc (sizeof (struct desc));
     inicio->qcolunas = TAM;
     inicio->prim = (struct desc2 *) malloc (sizeof (struct desc2));
     inicio->prim->qlinhas = TAM;
     inicio->prim->ant2 = (struct desc2 *) NULL;
     inicio->prim->ant = (struct ptr *) NULL;
     inicio->prim->prox = (struct ptr *) NULL;
     inicio->prim->prox2 = (struct desc2 *) NULL;
     inicio->ult = inicio->prim;
     aux3 = inicio->prim;
     for (i = 0; i < 6; i++)
     {
         aux3->prox2 = (struct desc2 *) malloc (sizeof (struct desc2));
         aux3->prox2->ant2 = aux3;
         aux3 = aux3->prox2;
         aux3->qlinhas = 7;
         aux3->ant = (struct ptr *) NULL;
         aux3->prox = (struct ptr *) NULL;
         aux3->prox2 = (struct desc2 *) NULL;
         inicio->ult = aux3;
     }
     aux3 = inicio->prim;
     for (i = 0; i < 7; i++)
     {
         aux3->ant = (struct ptr *) malloc (sizeof (struct ptr));
         aux3->ant->ant = (struct ptr *) NULL;
         aux3->ant->prox = (struct ptr *) NULL;
         aux3->prox = aux3->ant;
         aux = aux3->ant;
         for (j = 0; j < 6; j++)
         {
             aux->prox = (struct ptr *) malloc (sizeof (struct ptr));
             aux->prox->ant = aux;
             aux = aux->prox;
             aux->prox = (struct ptr *) NULL;
             aux3->prox = aux;
         }
         aux3 = aux3->prox2;                                      
     }
     aux3 = (struct desc2 *) NULL;
     aux = (struct ptr *) NULL;
}
     
void inicializa()
{
     int i, j;
     aux3 = inicio->prim;
     for (i = 0; i < 7; i++)
     {
         aux = aux3->ant;
         if ((i == 0) || (i == 1) || (i == 5) || (i == 6))
         {
            for (j = 0; j < 7; j++)
            {
                if ((j == 0) || (j == 1) || (j == 5) || (j == 6))
                {
                   aux->dado1 = ' ';
                   aux->dado2 = '2';
                }
                else
                {
                    aux->dado1 = '*';
                    aux->dado2 = '1';
                }
                aux = aux->prox;
            }
         }
         else
         {
             if (i == 3)
             {                      
                for (j = 0; j < 7; j++)
                {
                    if (j == 3)
                    {
                       aux->dado1 = '0';
                       aux->dado2 = '0';
                       aux = aux->prox;
                    }
                    else
                    {
                        aux->dado1 = '*';
                        aux->dado2 = '1';
                        aux = aux->prox;
                    }
                }
             }
             else
             {
                 for (j = 0; j < 7; j++)
                 {
                     aux->dado1 = '*';
                     aux->dado2 = '1';
                     aux = aux->prox;
                 }
             }
         }
         aux3 = aux3->prox2;
     }
     aux3 = (struct desc2 *) NULL;
     aux = (struct ptr *) NULL;                
}
     
void mostra()
{
     int i, j, k, cont = 0, cont2 = 0;
     system ("cls");
     printf ("11111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
     printf ("\t\t\t\t   TABULEIRO\n\n");
     printf ("11111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
     printf ("\t\t\t\tx 0 1 2 3 4 5 6 \n\n");
     for (i = 0; i < 7; i++)
     {
         printf ("\t\t\t\t");
         aux3 = inicio->prim;
         printf ("%d ", cont2);
         cont2++;
         for (j = 0; j < 7; j++)
         {
             aux = aux3->ant;
             for (k = 0; k < cont; k++)
                 aux = aux->prox;
             printf ("%c ", aux->dado1);
             aux3 = aux3->prox2;
         }
         cont++;
         printf ("\n");
     }
     printf ("\n11111111111111111111111111111111111111111111111111111111111111111111111111111111");
}
      
int avalia1()
{
    int i, j, k, l, fal = 0, ver = 1, cont = 0, cont2 = 0;
    aux3 = inicio->prim;
    for (i = 0; i < 7; i++)
    {
        if ((i == 0) || (i == 1) || (i == 5) || (i == 6))
        {
           aux = aux3->ant;
           for (j = 0; j < 3; j++)
               aux = aux->prox;
           aux2 = aux->prox;
           aux5 = aux2->prox;                                
           if ((aux->dado2 == '1') && (aux2->dado2 == '1') && (aux5->dado2 == '0'))
              return (ver);
        }
        else
        {
            aux = aux3->ant;
            for (j = 0; j < 5; j++)
            {
                aux2 = aux->prox;
                aux5 = aux2->prox;
                if ((aux->dado2 == '1') && (aux2->dado2 == '1') && (aux5->dado2 == '0'))
                   return (ver);
                aux = aux->prox;
            }
        }
        aux3 = aux3->prox2;
    }
    return (fal);
}

int avalia2()
{
    int i, j, k, l, fal = 0, ver = 1, cont = 0, cont2 = 0;                     
    aux3 = inicio->prim;
    for (i = 0; i < 7; i++)
    {
        if ((i == 0) || (i == 1) || (i == 5) || (i == 6))
        {
           aux = aux3->prox;
           for (j = 0; j < 3; j++)
               aux=aux->ant;
           aux2 = aux->ant;
           aux5 = aux2->ant;
           if ((aux->dado2 == '1') && (aux2->dado2 == '1') && (aux5->dado2 == '0'))
              return (ver);
        }
        else
        {
            aux = aux3->prox;
            for (j = 0; j < 5; j++)
            {
                aux2 = aux->ant;
                aux5 = aux2->ant;
                if ((aux->dado2 == '1') && (aux2->dado2 == '1') && (aux5->dado2 == '0'))
                   return (ver);
                aux = aux->ant;
            }
        }
        aux3 = aux3->prox2;
    }
    return (fal);
}
                
int avalia3()
{
    int i, j, k, l, fal = 0, ver = 1, cont = 0, cont2 = 0;
    for (i = 0; i < 7; i++)
    {
        aux3 = inicio->prim;
        cont2 = 0;
        for (j = 0; j < 5; j++)
        {
            aux3 = inicio->prim;
            for (k = 0; k < cont2; k++)
                aux3 = aux3->prox2;
            aux = aux3->ant;
            for (k = 0; k < cont; k++)
                aux = aux->prox;
            aux3 = aux3->prox2;
            aux2 = aux3->ant;
            for (k = 0; k < cont; k++)
                aux2 = aux2->prox;
            aux3 = aux3->prox2;
            aux5 = aux3->ant;
            for (k = 0; k < cont; k++)
                aux5 = aux5->prox;
            if ((aux->dado2 == '1') && (aux2->dado2 == '1') && (aux5->dado2 == '0'))
               return (ver);
            cont2++;
        }
        cont++;
    }
    return (fal);
}

int avalia4()
{
    int i, j, k, l, fal = 0, ver = 1, cont = 0, cont2 = 0;                               
    for (i = 0; i < 7; i++)
    {
        aux3 = inicio->ult;
        cont2 = 0;
        for (j = 0; j < 5; j++)
        {
            aux3 = inicio->ult;
            for (k = 0; k < cont2; k++)
                aux3 = aux3->ant2;
            aux = aux3->ant;
            for (k = 0; k < cont; k++)
                aux = aux->prox;
            aux3 = aux3->ant2;
            aux2 = aux3->ant;
            for (k = 0; k < cont; k++)
                aux2 = aux2->prox;
            aux3 = aux3->ant2;
            aux5 = aux3->ant;
            for (k = 0; k < cont; k++)
                aux5 = aux5->prox;
            if ((aux->dado2 == '1') && (aux2->dado2 == '1') && (aux5->dado2 == '0'))
               return (ver);
            cont2++;                                    
        }
        cont++;
    }                
    return (fal);
}

void menu();

void joga()
{
     int i, j, k, l, l1, c1, l2, c2, cont = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0, cont7 = 0, contmaster = 0, x, y, z, w;
     while (1)
     {
           do
           {
             if (cont5 == 1)
             {
                mostra();
                printf("\nErro: as coordenadas fornecidas nao comem nenhuma peca.\nPressione qualquer tecla para tentar novamente.");
                getch();
                mostra();
             }
             do
             {
               if (cont7 == 1)
               {
                  mostra();
                  printf ("\nErro: as coordenadas fornecidas nao comem nenhuma peca.\nPressione qualquer tecla para tentar novamente.");
                  getch();
                  mostra();
               }
               do
               {
                 if (cont4 == 1)
                 {
                    mostra();
                    printf ("\nErro: as coordenadas fornecidas sao muito proximas.\nPressione qualquer tecla para tentar novamente.");
                    getch();
                    mostra();
                 }
                 do
                 {
                   if (cont2 == 1)
                   {
                      mostra();
                      printf("\nErro: as coordenadas fornecidas nao comem nenhuma peca.\nPressione qualquer tecla para tentar novamente.");
                      getch();
                      mostra();
                   }
                   do
                   {
                     if (cont == 1)
                     {
                        mostra();
                        printf("\nErro: as coordenadas fornecidas sao iguais.\nPressione qualquer tecla para tentar novamente.");
                        getch();
                        mostra();
                     }
                     do
                     {
                       if (cont3 == 1)
                       {
                          printf("\nErro: campo invalido.\nPressione qualquer tecla para tentar novamente.");
                          getch();
                          mostra();
                       }
                       do
                       {
                         if (cont6 == 1)
                         {
                            mostra();
                            printf ("\nErro: as coordenadas fornecidas correspondem a um espaco em branco.\nPressione qualquer tecla para tentar novamente.");
                            getch();
                            mostra();
                         }
                         printf ("\nEntre com as coordenadas da peca que voce movera':\n");
                         do
                         {
                           printf (" > Linha:  ");
                           scanf ("%d", &l1);
                         }
                         while ((l1 > 6) || (l1 < 0));
                         do
                         {
                           printf (" > Coluna: ");
                           scanf ("%d", &c1);
                         }
                         while ((c1 > 6) || (c1<0));
                         aux3 = inicio->prim;
                         for (i = 0; i < c1; i++)
                             aux3 = aux3->prox2;
                         aux = aux3->ant;
                         for (i = 0; i < l1; i++)
                             aux = aux->prox;
                         if (aux->dado2 == '0')
                            cont6 = 1;
                         else
                             cont6 = 0;
                       }
                       while (cont6 == 1);
                       cont3=1;
                     }
                     while (((l1 == 0) || (l1 == 1) || (l1 == 5) || (l1 == 6)) && ((c1 == 0) || (c1 == 1) || (c1 == 5) || (c1 == 6)));
                     cont3 = 0;
                     do
                     {
                       if (cont3 == 1)
                       {
                          mostra();
                          printf("\nErro: campo invalido.\nPressione qualquer tecla para tentar novamente.");
                          getch();
                          mostra();
                       }
                       printf ("\nEntre com as coordenadas do local para onde voce movera' a peca:\n");
                       do
                       {
                         printf (" > Linha:  ");
                         scanf ("%d", &l2);
                       }
                       while ((l2 > 6) || (l2 < 0));
                       do
                       {
                         printf (" > Coluna: ");
                         scanf ("%d", &c2);
                       }
                       while ((c2 > 6) || (c2 < 0));
                       cont3 = 1;
                     }
                     while (((l2 == 0) || (l2 == 1) || (l2 == 5) || (l2 == 6)) && ((c2 == 0) || (c2 == 1) || (c2 == 5) || (c2 == 6)));
                     cont3++;
                     cont = 1;
                   }
                   while ((l1 == l2) && (c1 == c2));
                   cont++;
                   cont2 = 1;
                 }
                 while ((l1 != l2) && (c1 != c2));
                 cont2++;
                 cont4 = 1;
               }
               while (((l1 == l2) && (c2 == c1 + 1)) || ((l1 == l2) && (c1 == c2 + 1)) || ((c1 == c2) && (l2 == l1 + 1)) || ((c1 == c2) && (l1 == l2 + 1)));
               cont4++;
               if ((l1 == l2) && (c2 == c1 + 2))
                  cont7 = 0;
               else
               {
                   if ((l1 == l2) && (c1 == c2 + 2))
                      cont7 = 0;
                   else
                   {
                       if ((c1 == c2) && (l2 == l1 + 2))
                          cont7 = 0;
                       else
                       {
                           if ((c1 == c2) && (l1 == l2 + 2))
                              cont7 = 0;
                           else
                               cont7 = 1;
                       }
                   }
               }
             }
             while (cont7 == 1);
             cont7 = 0;
             cont5 = 1;
             if (l1 == l2)
             {
                if (c1 < c2)
                {
                   aux3 = inicio->prim;
                   for (i = 0; i < c1; i++)
                       aux3 = aux3->prox2;
                   aux = aux3->ant;
                   for (i = 0; i < l1; i++)
                       aux = aux->prox;
                   aux3 = aux3->prox2;
                   aux2 = aux3->ant;
                   for (i = 0; i < l1; i++)
                       aux2 = aux2->prox;
                   aux3 = aux3->prox2;
                   aux5 = aux3->ant;
                   for (i = 0; i < l1; i++)
                       aux5 = aux5->prox;
                   if ((aux->dado2 == '1') && (aux2->dado2 == '1') && (aux5->dado2 == '0'))
                   {
                      cont5 = 0;
                      aux->dado2 = '0';
                      aux->dado1 = '0';
                      aux2->dado1 = '0';
                      aux2->dado2 = '0';
                      aux5->dado1 = '*';
                      aux5->dado2 = '1';
                      mostra();
                      printf ("\nCar");
                      beep (440, 200);
                      printf ("re");
                      beep (880, 200);
                      printf ("gan");
                      beep (440, 200);
                      printf ("do");
                      beep (880, 200);
                      printf ("...");
                      sleep (200);
                   }
                   else
                       cont5 = 1;
                }
                else
                {
                    aux3 = inicio->prim;
                    for (i = 0; i < c1; i++)
                        aux3 = aux3->prox2;
                    aux = aux3->ant;
                    for (i = 0; i < l1; i++)
                        aux = aux->prox;
                    aux3 = aux3->ant2;
                    aux2 = aux3->ant;
                    for (i = 0; i < l1; i++)
                        aux2 = aux2->prox;
                    aux3 = aux3->ant2;
                    aux5 = aux3->ant;
                    for (i = 0; i < l1; i++)
                        aux5 = aux5->prox;
                    if ((aux->dado2 == '1') && (aux2->dado2 == '1') && (aux5->dado2 == '0'))
                    {
                       cont5 = 0;
                       aux->dado2 = '0';
                       aux->dado1 = '0';
                       aux2->dado1 = '0';
                       aux2->dado2 = '0';
                       aux5->dado1 = '*';
                       aux5->dado2 = '1';
                       mostra();
                       printf ("\nCar");
                       beep (440, 200);
                       printf ("re");
                       beep (880, 200);
                       printf ("gan");
                       beep (440, 200);
                       printf ("do");
                       beep (880, 200);
                       printf ("...");
                       sleep (200);
                    }
                    else
                        cont5 = 1;
                }
             }          
             else
             {
                 if (l1 < l2)
                 {
                    aux3 = inicio->prim;
                    for (i = 0; i < c1; i++)
                        aux3 = aux3->prox2;
                    aux = aux3->ant;
                    for (i = 0; i < l1; i++)
                        aux = aux->prox;
                    aux2 = aux->prox;
                    aux5 = aux2->prox;
                    if ((aux->dado2 == '1') && (aux2->dado2 == '1') && (aux5->dado2 == '0'))
                    {
                       cont5 = 0;
                       aux->dado2 = '0';
                       aux->dado1 = '0';
                       aux2->dado1 = '0';
                       aux2->dado2 = '0';
                       aux5->dado1 = '*';
                       aux5->dado2 = '1';
                       mostra();
                       printf ("\nCar");
                       beep (440, 200);
                       printf ("re");
                       beep (880, 200);
                       printf ("gan");
                       beep (440, 200);
                       printf ("do");
                       beep (880, 200);
                       printf ("...");
                       sleep (200);
                    }
                    else
                        cont5 = 1;
                    }
                    else
                    {
                        aux3 = inicio->prim;
                        for (i = 0; i < c1; i++)
                            aux3 = aux3->prox2;
                        aux = aux3->prox;
                        for (i = 0; i < 7 - (l1 + 1); i++)
                            aux = aux->ant;
                        aux2 = aux->ant;
                        aux5 = aux2->ant;
                        if ((aux->dado2 == '1') && (aux2->dado2 == '1') && (aux5->dado2 == '0'))
                        {
                           cont5 = 0;
                           aux->dado2 = '0';
                           aux->dado1 = '0';
                           aux2->dado1 = '0';
                           aux2->dado2 = '0';
                           aux5->dado1 = '*';
                           aux5->dado2 = '1';
                           mostra();
                           printf ("\nCar");
                           beep (440, 200);
                           printf ("re");
                           beep (880, 200);
                           printf ("gan");
                           beep (440, 200);
                           printf ("do");
                           beep (880, 200);
                           printf ("...");
                           sleep (200);
                        }
                        else
                            cont5=1;
                    }
                 }                                                                             
             }
             while (cont5 == 1);
       mostra();
       x = avalia1();
       y = avalia2();
       z = avalia3();
       w = avalia4();
       if ((x == 0) && (y == 0) && (z == 0) && (w == 0))
       {
          aux3 = inicio->prim;
          for (i = 0; i < 7; i++)
          {
              aux = aux3->ant;
              for (j = 0; j < 7; j++)
              {
                  if (aux->dado2 == '1')
                     contmaster++;
                  aux = aux->prox;
              }
              aux3=aux3->prox2;
          }
          if (contmaster == 1)
          {
             system ("cls");
             system ("color 27");
             printf ("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   PARABENS!\n\t\t\t   Voce venceu o \"Resta Um\".");
             getch();
             menu();
          }
          else
          {
              system ("cls");
              system ("color 47");
              printf ("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t  FIM DE JOGO\n\t\tInfelizmente, nao foi desta vez que voce venceu.");
              getch();
              menu();
          }                                        
       }
     }
     aux3 = (struct desc2 *) NULL;
     aux = (struct ptr *) NULL;
     aux2 = aux;
     aux5 = aux;
}

void comojogar()
{
     system ("cls");
     printf ("11111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
     printf ("\t\t\t\t  COMO JOGAR\n\n");
     printf ("11111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
     sleep (1000);
     printf (" OBJETIVO: Deixar apenas uma peca no tabuleiro, atraves de movimentos validos.");
     sleep (2000);
     printf ("\n\n - No inicio do jogo, ha' 32 pecas no tabuleiro e a posicao central encontra-se\nvazia.");
     sleep (2500);
     printf ("\n\n - Um movimento caracateriza-se em pegar uma peca e faze-la \"saltar\" sobre\noutra, apenas na horizontal ou na vertical, terminando em um espaco vazio.");
     sleep (4000);
     printf ("\n\n - A peca que foi \"saltada\" e' removida do tabuleiro.");
     sleep (2500);
     printf ("\n\n - O jogo termina quando nao for possivel realizar mais nenhum movimento.");
     sleep (2500);
     printf ("\n\n - Ao fim do jogo, o jogador vence se restar apenas uma peca no tabuleiro.");
     sleep (2500);
     printf ("\n\n\nPressione qualquer tecla para voltar ao menu principal.");
     getch();
     menu();
}

void creditos()
{
     system ("cls");
     printf ("11111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
     printf ("\t\t\t\t   CREDITOS\n\n");
     printf ("11111111111111111111111111111111111111111111111111111111111111111111111111111111\n");      
     sleep (1000);
     printf ("\t\t\t       Desenvolvido por:\n\n");
     sleep (1000);
     printf ("\t\t\t        BRENO  MARTINS\n");
     sleep (1000);
     printf ("\t\t\t        CAMILA  GUSMAO\n");
     sleep (1000);
     printf ("\t\t\t        FELIPE HOLANDA\n");
     sleep (1000);
     printf("\t\t\t        LUCAS TEIXEIRA");
     sleep (1000);
     printf ("\n\n\t\t\t        3AINFO  2012.1");
     sleep (1000);
     printf ("\n\n\nPressione qualquer tecla para voltar ao menu principal.");
     getch();
     menu();
}

void menu()
{
     system ("color F4");
     system ("cls");
     printf ("11111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
     printf ("    1111111                                             1111   1111             ");
     printf ("     1     1                        1                    1      1               ");
     printf ("     1     1   111111    111111   1111111    11111       1      1  11 11 11     ");
     printf ("     1     1  1      1  1      1    1             1      1      1 1111111111    ");
     printf ("     111111   1      1  1           1        111111      1      1  1   1  1     ");
     printf ("     1  1     1111111f   111111     1       1     1      1      1  1   1  1     ");
     printf ("     1   11   11               1    1       1     1      1      1  1   1  1     ");
     printf ("    111   111   111f    111111f      1111    11111        111111  1111 1 1111   \n");
     printf ("11111111111111111111111111111111111111111111111111111111111111111111111111111111");
     int opc;
     do
     {
       sleep (400);
       printf ("\n\n\t\t\t\t MENU ");
       beep (659, 200);
       printf ("PRINCIPAL\n\n");
       beep (659, 400);
       printf ("\t\t\t1. Jogar \"Resta Um - A Saga Comeca\"\n");
       beep (659, 400);
       printf ("\t\t\t2. Como jogar\n");
       beep (523, 200);
       printf ("\t\t\t3. Creditos\n");
       beep (659, 400);
       printf ("\t\t\t0. Sair\n\n");
       beep (783, 800);
       printf ("\t\t\t\tDigite a opcao: ");
       beep (391, 800);
       scanf ("%d", &opc);    
     }
     while ((opc > 3) || (opc < 0));
     if (opc == 1)
     {
        system ("cls");               
        criamatriz();
        inicializa();
        mostra();
        joga();
     }
     if (opc == 2)
        comojogar();
     if (opc == 3)
        creditos();
}

main()
{
      system ("title Resta Um - A Saga Comeca");
      menu();
}
