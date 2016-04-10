/* Uma empresa dar� um aumento de sal�rio aos seus funcion�rios de acordo com a 
categoria de cada empregado. O aumento seguir� a seguinte regra:
          
    - Funcion�rios das categorias A, C, F, G e H ganhar�o 10% de aumento  sobre
    o sal�rio.
    - Funcion�rios das categorias B, D, E, I, J, e T ganhar�o 15% de aumento so-
    bre o sal�rio.
    - Funcion�rios das categorias L, M, N, O, P, Q e S ganhar�o 25% de aumento
    sobre o sal�rio.
    - Funcion�rios das categorias K e R ganhar�o 35% de aumento sobre o sal�rio.
    - Funcion�rios das categorias U, V, W, X, Y e Z ganhar�o 50% de aumento so-
    bre o sal�rio.
    
Usando switch-case e if-else, fa�a um programa que calcule e imprima o sal�rio
reajustado. */


// POR SWITCH-CASE

/* main(){
       char cat;
       float sal,salreaj;
       printf("Entre com a sua categoria (De A ate' Z, com letra maiuscula).\n");
       scanf("%c",&cat);
       printf("\nEntre com o valor do seu salario antes do reajuste.\n");
       scanf("%f",&sal);
       switch (cat){
              case('A'):
              case('C'):
              case('F'):
              case('G'):
              case('H'):
                        salreaj = sal + sal * 0.1;
                        printf("\nO salario reajustado e' de R$ %.2f.",salreaj);
                        break;
              case('B'):
              case('D'):
              case('E'):
              case('I'):
              case('J'):
              case('T'):
                        salreaj = sal + sal * 0.15;
                        printf("\nO salario reajustado e' de R$ %.2f.",salreaj);
                        break;
              case('L'):
              case('M'):
              case('N'):
              case('O'):
              case('P'):
              case('Q'):
              case('S'):
                        salreaj = sal + sal * 0.25;
                        printf("\nO salario reajustado e' de R$ %.2f.",salreaj);
                        break;
              case('K'):
              case('R'):
                        salreaj = sal + sal * 0.35;
                        printf("\nO salario reajustado e' de R$ %.2f.",salreaj);
                        break;
              case('U'):
              case('V'):
              case('W'):
              case('X'):
              case('Y'):
              case('Z'):
                        salreaj = sal + sal * 0.5;
                        printf("\nO salario reajustado e' de R$ %.2f.",salreaj);
                        break;
              default:
                      printf("\nA categoria digitada nao existe. (Lembre-se de inserir um valor de A ate' Z, com letra maiuscula.)");
       }
       getch();
} */


// POR IF-ELSE

main(){
       char cat;
       float sal,salreaj;
       printf("Entre com a sua categoria (De A ate' Z, com letra maiuscula).\n");
       scanf("%c",&cat);
       printf("\nEntre com o valor do seu salario antes do reajuste.\n");
       scanf("%f",&sal);
       if (cat == 'A' || cat == 'C' || cat == 'F' || cat == 'G' || cat == 'H'){
          salreaj = sal + sal * 0.1;
          printf("\nO salario reajustado e' de R$ %.2f.",salreaj);
       }
       else {
            if (cat == 'B' || cat == 'D' || cat == 'E' || cat == 'I' || cat == 'J' || cat == 'T'){
            salreaj = sal + sal * 0.15;
            printf("\nO salario reajustado e' de R$ %.2f.",salreaj);
            }
            else {
                 if (cat == 'L' || cat == 'M' || cat == 'N' || cat == 'O' || cat == 'P' || cat == 'Q' || cat == 'S'){
                 salreaj = sal + sal * 0.25;
                 printf("\nO salario reajustado e' de R$ %.2f.",salreaj);
                 }
                 else {
                      if (cat == 'K' || cat == 'R'){
                      salreaj = sal + sal * 0.35;
                      printf("\nO salario reajustado e' de R$ %.2f.",salreaj);
                      }
                      else {
                           if (cat == 'U' || cat == 'V' || cat == 'W' || cat == 'X' || cat == 'Y' || cat == 'Z'){
                           salreaj = sal + sal * 0.5;
                           printf("\nO salario reajustado e' de R$ %.2f.",salreaj);
                           }
                           else {
                                printf("\nA categoria digitada nao existe. (Lembre-se de inserir um valor de A ate' Z, com letra maiuscula.)");
                           }
                      }
                 }
            }
       }
       getch();
}
