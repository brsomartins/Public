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

/* S� est� funcionando com n�meros cuja soma com o seu inverso resulta em um n�mero de tr�s d�gitos. 267, por exemplo, n�o funciona, j� que a soma de 267 e 762 � igual a 1029, n�mero de quatro algarismos. */
