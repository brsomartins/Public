/*
  Faça uma função recursiva que, dado um número n no intervalo fechado 1-9, es-
  creva a sequência abaixo:
         
  5 4 3 2 1 2 3 4 5  (caso o número inserido seja "5")
  4 3 2 1 2 3 4
  3 2 1 2 3
  2 1 2
  1
  2 1 2
  3 2 1 2 3
  4 3 2 1 2 3 4
  5 4 3 2 1 2 3 4 5 
*/

int num;
void mostra2 (int num), mostra (int num);

main(){
       printf ("Entre com um numero: ");
       scanf ("%d", &num);
       printf ("\n");
       mostra2 (num);
       getch();
}

void mostra2 (int num){ 
     void mostra (int num){
          if (num == 1)
             printf ("%d ", num);
          else{
               printf ("%d ", num);
               mostra (num - 1);
               printf ("%d ", num);
          }
     }
     if (num == 1)
        printf ("1\n");
     else{
          mostra (num);
          printf ("\n");
          mostra2 (num - 1);
          mostra (num);
          printf ("\n");
     }
}
