#include <stdio.h>

// Declarando as estruturas
struct ptr{
       int dado;
       struct ptr *prox;
};

// Declarando as variáveis
int n;
struct ptr *inicio, *fim, *aux, *pre, *pos;

// Função para criar uma lista na ordem inversa a em que os dados são obtidos
void criar_lsec_inv(){
     
     // Função auxiliar
     void criar_lsec_inv_aux(){
          printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
          scanf ("%d", &n);
          printf ("\n");
          
          if (n != -1){
             aux = (struct ptr *) malloc (sizeof (struct ptr));
             aux->dado = n;
             aux->prox = inicio;
             inicio = aux;
             fim->prox = inicio;
             aux = (struct ptr *) NULL;
             criar_lsec_inv_aux();
          }
          else{
               aux = (struct ptr *) NULL;
               fim = aux;
          }
     }
     
     printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
     scanf ("%d", &n);
     printf ("\n");
     if (n != -1){
        inicio = (struct ptr *) malloc (sizeof (struct ptr));
        inicio->dado = n;
        inicio->prox = inicio;
        fim = inicio;
        criar_lsec_inv_aux();
     }
     else
         inicio = (struct ptr *) NULL;
}

// Função para criar uma lista na ordem em que os dados são obtidos
void criar_lsec(){
     
     // Função auxiliar
     void criar_lsec_aux(){
          printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
          scanf ("%d", &n);
          printf ("\n");
          if (n != -1){
             fim = (struct ptr *) malloc (sizeof (struct ptr));
             fim->dado = n;
             aux->prox = fim;
             fim->prox = inicio;
             aux = fim;
             criar_lsec_aux();
          }
          else{
               aux = (struct ptr *) NULL;
               fim = aux;
          }
     }
     
     printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
     scanf ("%d", &n);
     printf ("\n");
     if (n != -1){
        inicio = (struct ptr *) malloc (sizeof (struct ptr));
        inicio->dado = n;
        inicio->prox = inicio;
        aux = inicio;
        criar_lsec_aux();
     }
     else
         inicio = (struct ptr *) NULL;
}

// Função para inserir um elemento em uma lista ordenada crescentemente
void inserir(){
     
     // Funções auxiliares
     void inserir_aux(){
          if (fim->prox != inicio){
             fim = fim->prox;
             inserir_aux();
          }
     }
     void inserir_aux2(){
          if ((pos->prox != inicio) && (pos->dado < n)){
             pre = pos;
             pos = pos->prox;
             inserir_aux2();
          }
     }
     
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
              
             // Caso de inserção no início da lista
             if (inicio->dado > n){
                fim = inicio;
                inserir_aux();
                aux->prox = inicio;
                inicio = aux;
                fim->prox = inicio;
                aux = (struct ptr *) NULL;
                fim = aux;
             }
             
             else{
                  pos = inicio;
                  inserir_aux2();
                  
                  // Caso de inserção no fim da lista
                  if (pos->dado < n){
                     pos->prox = aux;
                     aux->prox = inicio;
                     aux = (struct ptr *) NULL;
                     pre = aux;
                     pos = aux;
                  }
                  
                  else{
                       
                       // Caso de inserção no meio da lista
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

// Função para criar uma lista ordenando-a crescentemente
void criar_lsec_ord(){
     
     // Função auxiliar
     void criar_lsec_ord_aux(){
          if (n != -1){
             inserir();
             criar_lsec_ord_aux();
          }
     }
          
     inicio = (struct ptr *) NULL;
     inserir();
}

// Função para excluir um elemento de uma lista
void excluir(){
     
     // Funções auxiliares
     void excluir_aux(){
          if (fim->prox != inicio){
             fim = fim->prox;
             excluir_aux();
          }
     }
     void excluir_aux2(){
          if (fim->prox != inicio){
             fim = fim->prox;
             excluir_aux2();
          }
     }
     void excluir_aux3(){
          if ((pos->prox != inicio) && (pos->dado != n)){
             pre = pos;
             pos = pos->prox;
             excluir_aux3();
          }
     }
     
     printf ("Entre com o elemento que devera' ser excluido da lista. ");
     scanf ("%d", &n);
     printf ("\n");
     if (n != -1){
        
        // Caso de lista vazia
        if (inicio == (struct ptr *) NULL)
           printf ("Lista vazia!\n");
           
        else{
             
             // Caso de existência de apenas um elemento na lista
             if (inicio->prox == (struct ptr *) NULL){
                if (inicio->dado != n)
                   printf ("Elemento inexistente!\n");
                else{
                    free (inicio);
                    inicio = (struct ptr *) NULL;
                }
             }
             
             else{
                  
                  // Caso de exclusão no início da lista
                  if (inicio->dado == n){
                     fim = inicio;
                     excluir_aux();
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
                       excluir_aux2();
                       pos = inicio;
                       excluir_aux3();
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

// Função para limpar uma lista
void limpar(){
     
     // Funções auxiliares
     void limpar_aux(){
          if (aux->prox != inicio){
             aux = aux->prox;
             limpar_aux();
          }
     }
     void limpar_aux2(){
          if (inicio->prox != (struct ptr *) NULL){
             inicio = inicio->prox;
		     aux->prox = (struct ptr *) NULL;
		     free (aux);
		     aux = inicio;
		     limpar_aux2();
          }
     }
     
     aux = inicio;
     limpar_aux();
     aux->prox = (struct ptr *) NULL;
     aux = inicio;
	 limpar_aux2();
     free (aux);
     aux = (struct ptr *) NULL;
     inicio = aux;
     printf ("Lista esvaziada!\n\n");
}

// Função para mostrar a lista na tela
void imprimir_lsec(){
     
     // Função auxiliar
     void imprimir_lsec_aux(){
          if (aux != inicio){
             printf ("%d ", aux->dado);
             aux = aux->prox;
             imprimir_lsec_aux();
          }
     }
     
     if (inicio == (struct ptr *) NULL)
        printf ("Lista vazia!\n\n");
     else{
          aux = inicio->prox;
          printf ("Lista: ");
          printf ("%d ", inicio->dado);
          imprimir_lsec_aux();
          printf ("\n\n");
          aux = (struct ptr *) NULL;
     }
}

// Função para exibir um menu de opções
void menu(){
     
     int opcao;
     
     // Função auxiliar
     void menu_aux(){
          if ((opcao < 0) || (opcao > 7)){
             printf ("\nOpcao invalida! Digite outra. ");
             scanf ("%d", &opcao);
             menu_aux();
          }
     }

     printf ("================================================================================");
     printf ("\nDigite:\n  1 para criar uma lista na ordem inversa.\n  2 para criar uma lista na ordem normal.\n  3 para inserir um elemento na lista (se ela estiver ordenada crescentemente).\n  4 para criar uma lista ordenando-a crescentemente.\n  5 para excluir um elemento da lista criada.\n  6 para limpar a lista criada.\n  7 para mostrar a lista criada na tela.\n  0 para sair.\n> ");
     scanf ("%d", &opcao);
     if ((opcao < 0) || (opcao > 7)){
        menu_aux();
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

// Função principal
main(){
       menu();
}
