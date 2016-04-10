/* Um comerciante comprou um produto e quer vendê-lo com lucro de 40% se o valor
da compra for menor que R$ 20. Caso o contrário, o lucro será de 30%. Faça um
programa que leia o valor do produto e imprima seu valor de venda. */

main(){
       float vl,vlvenda;
       printf("Entre com o valor do produto.\n");
       scanf("%f",&vl);
       if (vl < 20)
          vlvenda = vl + vl * 0.4;
       else
           vlvenda = vl + vl * 0.3;
       printf("\nO valor de venda e' R$ %.2f.",vlvenda);
       getch();
}
