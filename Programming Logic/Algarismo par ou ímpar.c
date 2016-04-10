/* Faça um programa que leia um número inteiro de três dígitos e informe se o
algarismo da centena é par ou é ímpar. */

main(){
       int n,cent;
       printf("Digite um numero inteiro de tres digitos.\n");
       scanf("%d",&n);
       cent = n / 100;
       if (cent % 2 == 0)
          printf("\nO algarismo da centena, %d, e' par.",cent);
       else
           printf("\nO algarismo da centena, %d, e' impar.",cent);
       getch();
}
