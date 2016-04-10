/* Faça um programa que leia um número e diga se ele é divisível por 3 e por 7.
Não utilize operadores lógicos. */

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
