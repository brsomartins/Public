/*
  Fa�a uma fun��o recursiva que, dado um n�mero n no intervalo fechado 1-9, es-
  creva a sequ�ncia abaixo:
         
  5 4 3 2 1 2 3 4 5  (caso o n�mero inserido seja "5")
*/

int num;
void mostra (int num);

main(){
       printf ("Entre com um numero: ");
       scanf ("%d", &num);
       mostra (num);
       getch();
}

void mostra (int num){
     if (num == 1)
        printf ("%d ", num);
     else{
          printf ("%d ", num);
          mostra (num - 1);
          printf ("%d ", num);
     }
}
