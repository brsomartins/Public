#include <stdio.h>

// Declarando as estruturas
struct ptr{
       int dado;
       struct ptr *ant, *prox;
};
struct desc{
       int quant;
       struct ptr *prim, *ult;
};

// Declarando as variáveis
int n;
struct ptr *inicio, *fim, *aux, *pre, *pos;
struct desc *descritor;

// Função para criar uma lista na ordem inversa a em que os dados são obtidos
void criar_lsec_inv(){
     
     // Função auxiliar
     void criar_lsec_inv_aux(){
          if (n != -1){
             aux = (struct ptr *) malloc (sizeof (struct ptr));
             aux->dado = n;
             aux->ant = (struct ptr *) NULL;
             aux->prox = inicio;
             inicio = aux;
             inicio->ant = aux;
             aux = (struct ptr *) NULL;
             descritor->quant++;
             printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
             scanf ("%d", &n);
             printf ("\n");
             criar_lsec_inv_aux();
        }
     }
     
     printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
     scanf ("%d", &n);
     printf ("\n");
     if (n != -1){
        inicio = (struct ptr *) malloc (sizeof (struct ptr));
        inicio->dado = n;
        inicio->ant = inicio;
        inicio->prox = inicio;
        descritor = (struct desc *) malloc (sizeof (struct desc));
        descritor->quant = 1;
        descritor->ult = inicio;
        printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
        scanf ("%d", &n);
        printf ("\n");
        criar_lsec_inv_aux();
        descritor->prim = inicio;
     }
     else
         inicio = (struct ptr *) NULL;
         descritor = inicio;
}

// Função para criar uma lista na ordem em que os dados são obtidos
void criar_lsec(){
     
     // Função auxiliar
     void criar_lsec_aux(){
          if (n != -1){
             fim = (struct ptr *) malloc (sizeof (struct ptr));
             fim->dado = n;
             if (aux == inicio)
                aux->ant = inicio;
             aux->prox = fim;
             fim->ant = aux;
             fim->prox = (struct ptr *) NULL;
             inicio->ant = fim;
             aux = fim;
             descritor->quant++;
             printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
             scanf ("%d", &n);
             printf ("\n");
             criar_lsec_aux();
          }
     }
     
     printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
     scanf ("%d", &n);
     printf ("\n");
     if (n != -1){
        inicio = (struct ptr *) malloc (sizeof (struct ptr));
        inicio->dado = n;
        inicio->ant = (struct ptr *) NULL;
        inicio->prox = inicio->ant;
        aux = inicio;
        descritor = (struct desc *) malloc (sizeof (struct desc));
        descritor->prim = inicio;
        descritor->quant = 1;
        printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
        scanf ("%d", &n);
        printf ("\n");
        criar_lsec_aux();
        descritor->ult = fim;
        aux = (struct ptr *) NULL;
        fim = aux;
     }
     else
         inicio = (struct ptr *) NULL;
         descritor = inicio;
}

// Função para inserir um elemento em uma lista ordenada crescentemente
void inserir(){
     
     // Função auxiliar
     void inserir_aux(){
          if ((pos->prox != (struct ptr *) NULL) && (pos->dado < n)){
             pos = pos->prox;
             inserir_aux();
          }
     }
     
     printf ("Entre com um elemento. (\"-1\" finaliza a lista.) ");
     scanf ("%d", &n);
     printf ("\n");
     if (n != -1){
        aux = (struct ptr *) malloc (sizeof (struct ptr));
        aux->dado = n;
        aux->ant = (struct ptr *) NULL;
        aux->prox = (struct ptr *) NULL;
        
        // Caso de lista vazia
        if (inicio == (struct ptr *) NULL){
           inicio = aux;
           aux = (struct ptr *) NULL;
           descritor = (struct desc *) malloc (sizeof (struct desc));
           descritor->prim = inicio;
           descritor->ult = inicio;
           descritor->quant = 1;
        }
        
        else{
              
             // Caso de inserção no início da lista
             if (inicio->dado > n){
                aux->prox = inicio;
                inicio->ant = aux;
                inicio = aux;
                aux = (struct ptr *) NULL;
                descritor -> prim = inicio;
                descritor -> quant++;
             }
             
             else{
                  pos = inicio;
                  inserir_aux();
                  
                  // Caso de inserção no fim da lista
                  if (pos->dado < n){
                     inicio->ant = aux;
                     pos->prox = aux;
                     descritor -> ult = pos -> prox;
                     descritor -> quant++;
                     aux = (struct ptr *) NULL;
                     pos = aux;
                  }
                  
                  else{
                       
                       // Caso de inserção no meio da lista
                       aux->prox = pos;
                       aux->ant = pos->ant;
                       pos->ant->prox = aux;
                       pos->ant = aux;
                       aux = (struct ptr *) NULL;
                       pos = aux;
                       descritor->quant++;
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
     
     // Função auxiliar
     void excluir_aux(){
          if ((pos->prox != (struct ptr *) NULL) && (pos->dado != n)){
             pos = pos->prox;
             excluir_aux();
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
                    free (descritor);
                    descritor = (struct desc *) NULL;
                }
             }
             
             else{
                  
                  // Caso de exclusão no início da lista
                  if (inicio->dado == n){
                     aux = inicio;
                     inicio = inicio->prox;
                     aux->prox = (struct ptr *) NULL;
                     free (aux);
                     aux = (struct ptr *) NULL;
                     descritor->quant--;
                     descritor->prim = inicio;
                  }
                  
                  else{
                       pos = inicio;
                       excluir_aux();
                       if (pos->dado != n)
                          printf ("Elemento inexistente!\n");
                       else{
                            if (pos->prox == (struct ptr *) NULL){
                               pos->ant->prox = (struct ptr *) NULL;
                               descritor->ult = pos->ant;
                               free (pos);
                               pos = (struct ptr *) NULL;
                               descritor->quant--;
                            }
                            else{
                                 pos->ant->prox = pos->prox;
                                 pos->prox->ant = pos->ant;
                                 free (pos);
                                 pos = (struct lista *) NULL;
                                 descritor->quant--;
                            }
                       }
                  }
             }
        }
     }
}

// Função para limpar uma lista
void limpar(){
     
     // Função auxiliar
     void limpar_aux(){
          if (inicio->prox != (struct ptr *) NULL){
             inicio = inicio->prox;
             descritor->prim->prox->ant = (struct ptr *) NULL;
		     descritor->prim->prox = (struct ptr *) NULL;
		     free (descritor->prim);
		     descritor->quant--;
		     descritor->prim = inicio;
		     limpar_aux();
          }
     }
     
     descritor->ult->prox = (struct ptr *) NULL;
     descritor->prim->ant = (struct ptr *) NULL;
	 limpar_aux();
     free (inicio);
     inicio = (struct ptr *) NULL;
     descritor->prim = inicio;
     descritor->ult = inicio;
     free (descritor);
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
