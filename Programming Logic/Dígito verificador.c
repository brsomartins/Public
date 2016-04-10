main(){
       int conta,a1,a2,a3,inv,somainv,si1,si2,si3,somaordpos,ver;
       printf("Digite o numero da conta (tres digitos).\n");
       scanf("%d",&conta);
       a1 = conta / 100;
       a2 = conta % 100 / 10;
       a3 = conta % 100 % 10;
       inv = a3 * 100 + a2 * 10 + a1;
       somainv = conta + inv;
       si1 = somainv / 100;
       si2 = somainv % 100 / 10;
       si3 = somainv % 100 % 10;
       somaordpos = si1 * 1 + si2 * 2 + si3 * 3;
       ver = somaordpos % 10;
       printf("\nO digito verificador da conta %03d sera: %d\nConta: %03d-%d",conta,ver,conta,ver);
       getch();
}

/* Só está funcionando com números cuja soma com o seu inverso resulta em um número de três dígitos. 267, por exemplo, não funciona, já que a soma de 267 e 762 é igual a 1029, número de quatro algarismos. */
