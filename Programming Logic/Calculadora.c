/* Faça um programa que crie uma calculadora com as operações de soma, subtra-
ção, multiplicação e divisão como no exemplo abaixo:
     
    *********************
         CALCULADORA
    *********************
     + para somar
     - para subtrair
     * para multiplicar
     / para dividir
    =====================
*/

main(){
       char op;
       float n1,n2,res;
       printf("*********************\n");
       printf("     CALCULADORA\n");
       printf("*********************\n");
       printf(" + para somar\n");
       printf(" - para subtrair\n");
       printf(" * para multiplicar\n");
       printf(" / para dividir\n");
       printf("=====================\n");
       printf("\nDigite uma das opcoes acima.\n");
       scanf("%c",&op);
       printf("\nDigite o primeiro numero da operacao.\n");
       scanf("%f",&n1);
       printf("\nDigite o segundo numero da operacao.\n");
       scanf("%f",&n2);
       switch (op){
              case ('+'):
                   res = n1 + n2;
                   printf("\n%.2f + %.2f = %.2f.",n1,n2,res);
                   break;
              case ('-'):
                   res = n1 - n2;
                   printf("\n%.2f - %.2f = %.2f.",n1,n2,res);
                   break;
              case ('*'):
                   res = n1 * n2;
                   printf("\n%.2f * %.2f = %.2f.",n1,n2,res);
                   break;
              case ('/'):
                   res = n1 / n2;
                   printf("\n%.2f / %.2f = %.2f.",n1,n2,res);
                   break;
              default:
                      printf("\nOperador invalido digitado!");
       }
       getch();
}
