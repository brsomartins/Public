/* Uma empresa dará um aumento de salário aos seus funcionários de acordo com a 
categoria de cada empregado. O aumento seguirá a seguinte regra:
          
    - Funcionários das categorias A, C, F, G e H ganharão 10% de aumento  sobre
    o salário.
    - Funcionários das categorias B, D, E, I, J, e T ganharão 15% de aumento so-
    bre o salário.
    - Funcionários das categorias L, M, N, O, P, Q e S ganharão 25% de aumento
    sobre o salário.
    - Funcionários das categorias K e R ganharão 35% de aumento sobre o salário.
    - Funcionários das categorias U, V, W, X, Y e Z ganharão 50% de aumento so-
    bre o salário.
    
Usando switch-case e if-else, faça um programa que calcule e imprima o salário
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
