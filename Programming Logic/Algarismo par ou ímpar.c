/* Fa�a um programa que leia um n�mero inteiro de tr�s d�gitos e informe se o
algarismo da centena � par ou � �mpar. */

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
