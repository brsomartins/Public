/* Faça uma função recursiva que calcule e retorne o valor de
   s(n) = 1^1! - 2^1! - 4^2! + 7^3! - 12^5! +- ... } n parcelas
*/

// Incompleto

float soma (int n);
int a;

main(){
       printf ("Entre com um numero: ");
       scanf ("%d", &a);
       if (a <= 0)
          printf ("\nErro!");
       else
           printf ("\ns(%d) = %.2f.", a, soma(a));
       getch();
}

float difat (int n){
      float d;
      if (n == 1)
         return 1;
      else
          d = fat(n - 1) + d

float soma (int n){
      if (n == 1)
         return 1;
      else
          if (
