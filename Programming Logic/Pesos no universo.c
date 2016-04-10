/*
  Faça um programa que leia um peso na Terra e o número de um planeta e imprima
  o valor de seu peso nesse planeta. A relação dos planetas é dada a seguir,
  juntamente com o valor das gravidades relativas. Faça obrigatoriamente por
  switch-case.

  #      GRAVIDADE       PLANETA
  1      0,37            Mercúrio
  2      0,88            Vênus
  3      0,38            Marte
  4      2,64            Júpiter
  5      1,15            Saturno
  6      1,17            Urano
*/

main(){
       int op;
       float p,pr;
       printf("Entre com um peso (em kg).\n");
       scanf("%f",&p);
       printf("\nAgora digite uma das opcoes de planetas a seguir.\n");
       printf("\n====================");
       printf("\n| 1    Mercurio    |");
       printf("\n| 2    Venus       |");
       printf("\n| 3    Marte       |");
       printf("\n| 4    Jupiter     |");
       printf("\n| 5    Saturno     |");
       printf("\n| 6    Urano       |");
       printf("\n====================\n\n");
       scanf("%d",&op);
       switch (op){
              case (1):
                   pr = p * 0.37;
                   printf("\nO peso %.2f kg na Terra e' igual a %.2f kg em Mercurio.",p,pr);
                   break;
              case (2):
                   pr = p * 0.88;
                   printf("\nO peso %.2f kg na Terra e' igual a %.2f kg em Venus.",p,pr);
                   break;
              case (3):
                   pr = p * 0.38;
                   printf("\nO peso %.2f kg na Terra e' igual a %.2f kg em Marte.",p,pr);
                   break;
              case (4):
                   pr = p * 2.64;
                   printf("\nO peso %.2f kg na Terra e' igual a %.2f kg em Jupiter.",p,pr);
                   break;
              case (5):
                   pr = p * 1.15;
                   printf("\nO peso %.2f kg na Terra e' igual a %.2f kg em Saturno.",p,pr);
                   break;
              case (6):
                   pr = p * 1.17;
                   printf("\nO peso %.2f kg na Terra e' igual a %.2f kg em Urano.",p,pr);
                   break;
              default:
                      printf("\nO numero digitado nao corresponde a nenhuma das opcoes.");
                      break;
       }
       getch();
}
