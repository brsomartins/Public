#include <stdio.h>

// Declarando as estruturas
struct ptr{
       int dado;
       struct ptr *prox;
};

// Declarando as vari�veis
int n;
struct ptr *inicio, *fim, *aux, *pre, *pos;

// Fun��o para criar uma lista na ordem inversa a em que os dados s�o obtidos
void criar_lsec_inv(){
     printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
     scanf ("%d", &n);
     printf ("\n");
     if (n != -1){
        inicio = (struct ptr *) malloc (sizeof (struct ptr));
        inicio->dado = n;
        inicio->prox = inicio;
        fim = inicio;
        printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
        scanf ("%d", &n);
        printf ("\n");
        while (n != -1){
              aux = (struct ptr *) malloc (sizeof (struct ptr));
              aux->dado = n;
              aux->prox = inicio;
              inicio = aux;
              fim->prox = inicio;
              aux = (struct ptr *) NULL;
              printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
              scanf ("%d", &n);
              printf ("\n");
        }
        aux = (struct ptr *) NULL;
        fim = aux;
     }
     else
         inicio = (struct ptr *) NULL;
}

// Fun��o para criar uma lista na ordem em que os dados s�o obtidos
void criar_lsec(){
     printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
     scanf ("%d", &n);
     printf ("\n");
     if (n != -1){
        inicio = (struct ptr *) malloc (sizeof (struct ptr));
        inicio->dado = n;
        inicio->prox = inicio;
        aux = inicio;
        printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
        scanf ("%d", &n);
        printf ("\n");
        while (n != -1){
              fim = (struct ptr *) malloc (sizeof (struct ptr));
              fim->dado = n;
              aux->prox = fim;
              fim->prox = inicio;
              aux = fim;
              printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
              scanf ("%d", &n);
              printf ("\n");
        }
        aux = (struct ptr *) NULL;
        fim = aux;
     }
     else
         inicio = (struct ptr *) NULL;
}

// Fun��o para inserir um elemento em uma lista ordenada crescentemente
void inserir(){
     printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
     scanf ("%d", &n);
     printf ("\n");
     if (n != -1){
        aux = (struct ptr *) malloc (sizeof (struct ptr));
        aux->dado = n;
        aux->prox = (struct ptr *) NULL;
        
        // Caso de lista vazia
        if (inicio == (struct ptr *) NULL){
           inicio = aux;
           aux = (struct ptr *) NULL;
           inicio->prox = inicio;
        }
        
        else{
              
             // Caso de inser��o no in�cio da lista
             if (inicio->dado > n){
                fim = inicio;
                while (fim->prox != inicio)
                      fim = fim->prox;
                aux->prox = inicio;
                inicio = aux;
                fim->prox = inicio;
                aux = (struct ptr *) NULL;
                fim = aux;
             }
             
             else{
                  pos = inicio;
                  while ((pos->prox != inicio) && (pos->dado < n)){
                        pre = pos;
                        pos = pos->prox;
                  }
                  
                  // Caso de inser��o no fim da lista
                  if (pos->dado < n){
                     pos->prox = aux;
                     aux->prox = inicio;
                     aux = (struct ptr *) NULL;
                     pre = aux;
                     pos = aux;
                  }
                  
                  else{
                       
                       // Caso de inser��o no meio da lista
                       pre->prox = aux;
                       aux->prox = pos;
                       aux = (struct ptr *) NULL;
                       pre = aux;
                       pos = aux;
                  }
             }
        }
     }
}

// Fun��o para criar uma lista ordenando-a crescentemente
void criar_lsec_ord(){
     inicio = (struct ptr *) NULL;
     inserir();
     while (n != -1)
           inserir();
}

// Fun��o para excluir um elemento de uma lista
void excluir(){
     printf ("Entre com o elemento que devera' ser excluido da lista. ");
     scanf ("%d", &n);
     printf ("\n");
     if (n != -1){
        
        // Caso de lista vazia
        if (inicio == (struct ptr *) NULL)
           printf ("Lista vazia!\n");
           
        else{
             
             // Caso de exist�ncia de apenas um elemento na lista
             if (inicio->prox == (struct ptr *) NULL){
                if (inicio->dado != n)
                   printf ("Elemento inexistente!\n");
                else{
                    free (inicio);
                    inicio = (struct ptr *) NULL;
                }
             }
             
             else{
                  
                  // Caso de exclus�o no in�cio da lista
                  if (inicio->dado == n){
                     fim = inicio;
                     while (fim->prox != inicio)
                           fim = fim->prox;
                     aux = inicio;
                     inicio = inicio->prox;
                     fim->prox = inicio;
                     aux->prox = (struct ptr *) NULL;
                     free (aux);
                     aux = (struct ptr *) NULL;
                     fim = aux;
                  }
                  
                  else{
                       fim = inicio;
                       while (fim->prox != inicio)
                             fim = fim->prox;
                       pos = inicio;
                       while ((pos->prox != inicio) && (pos->dado != n)){
                             pre = pos;
                             pos = pos->prox;
                       }
                       if (pos->dado != n)
                          printf ("Elemento inexistente!\n");
                       else{
                            pre->prox = pos->prox;
                            pos->prox = (struct ptr *) NULL;
                            free (pos);
                            pos = (struct ptr *) NULL;
                            pre = pos;
                            fim = pos;
                       }
                  }
             }
        }
     }
}

// Fun��o para limpar uma lista
void limpar(){
     aux = inicio;
     while (aux->prox != inicio)
           aux = aux->prox;
     aux->prox = (struct ptr *) NULL;
     aux = inicio;
	 while (inicio->prox != (struct ptr *) NULL){
           inicio = inicio->prox;
		   aux->prox = (struct ptr *) NULL;
		   free (aux);
		   aux = inicio;
     }
     free (aux);
     aux = (struct ptr *) NULL;
     inicio = aux;
     printf ("Lista esvaziada!\n\n");
}

// Fun��o para mostrar a lista na tela
void imprimir_lsec(){
     if (inicio == (struct ptr *) NULL)
        printf ("Lista vazia!\n\n");
     else{
          aux = inicio->prox;
          printf ("Lista: ");
          printf ("%d ", inicio->dado);
          while (aux != inicio){
                printf ("%d ", aux->dado);
                aux = aux->prox;
          }
          printf ("\n\n");
          aux = (struct ptr *) NULL;
     }
}

// Fun��o para exibir um menu de op��es
void menu(){
     int opcao;
     printf ("================================================================================");
     printf ("\nDigite:\n  1 para criar uma lista na ordem inversa.\n  2 para criar uma lista na ordem normal.\n  3 para inserir um elemento na lista (se ela estiver ordenada crescentemente).\n  4 para criar uma lista ordenando-a crescentemente.\n  5 para excluir um elemento da lista criada.\n  6 para limpar a lista criada.\n  7 para mostrar a lista criada na tela.\n  0 para sair.\n> ");
     scanf ("%d", &opcao);
     if ((opcao < 0) || (opcao > 7)){
        while ((opcao < 0) || (opcao > 7)){
              printf ("\nOpcao invalida! Digite outra. ");
              scanf ("%d", &opcao);
        }
     }
     else{
         if (opcao == 1){
            printf ("\n");
            criar_lsec_inv();
            menu();
         }
         if (opcao == 2){
            printf ("\n");
            criar_lsec();
            menu();
         }
         if (opcao == 3){
            printf ("\n");
            inserir();
            menu();
         }
         if (opcao == 4){
            printf ("\n");
            criar_lsec_ord();
            menu();
         }
         if (opcao == 5){
            printf ("\n");
            excluir();
            menu();
         }
         if (opcao == 6){
            printf ("\n");
            limpar();
            menu();
         }
         if (opcao == 7){
            printf ("\n");
            imprimir_lsec();
            menu();
         }
         if (opcao == 0){
            printf ("\nPressione qualquer tecla para sair.");
            getch();
         }
     }
}

// Fun��o principal
main(){
       menu();
}
