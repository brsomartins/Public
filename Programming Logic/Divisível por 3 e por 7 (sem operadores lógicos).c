/* Fa�a um programa que leia um n�mero e diga se ele � divis�vel por 3 e por 7.
N�o utilize operadores l�gicos. */

main(){
       int n;
       printf("Digite um numero.\n");
       scanf("%d",&n);
       if (n % 3 == 0){
          if (n % 7 == 0)
             printf("\nO numero %d e' divisivel por 3 e por 7.",n);
          else
              printf("\nO numero %d nao e' divisivel por 3 e por 7.",n);
       }
       else
           printf("\nO numero %d nao e' divisivel por 3 e por 7.",n);
       getch();
}
