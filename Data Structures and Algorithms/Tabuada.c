/*
  Faça uma função recursiva para mostrar a tabuada de 1 a 10 de um número intei-
  ro positivo qualquer.
*/

int n;
void tab (int n, int i);

main(){
       printf ("Entre com um numero: ");
       scanf ("%d", &n);
       tab (n, 1);
       getch();
}

void tab (int n, int i){
     if (i == 10)
        printf ("%d x %d = %d", i, n, n * i);
     else{
          printf (" %d x %d = %d\n", i, n, n * i);
          tab (n, i + 1);
     }
}
