/* Faça um programa que leia nome, nota 1 e nota 2, calcule a média e imprima o 
nome do aluno, sua média e se o mesmo está aprovado, reprovado ou de prova fi-
nal, atendendo aos seguintes critérios:
    - >= 8 -> Aprovado;
    - < 5 -> Reprovado;
    - Resto -> Prova final. */

main(){
       char nome[12];
       float n1,n2,media;
       printf("Digite o nome do aluno.\n");
       scanf("%s",&nome);
       printf("\nDigite a nota 1.\n");
       scanf("%f",&n1);
       printf("\nDigite a nota 2.\n");
       scanf("%f",&n2);
       media = (n1 + n2) / 2;
       if (media >= 8)
          printf("\nO(a) aluno(a) %s foi aprovado(a) com media %.2f.",nome,media);
       else{
           if (media < 5)
              printf("\nO(a) aluno(a) %s foi reprovado(a) com media %.2f.",nome,media);
           else
               printf("\nO(a) aluno(a) %s ficou de prova final com media %.2f.",nome,media);
       }
       getch();
}
