//Faça um programa que leia um número binário de quatro dígitos e diga qual é o seu decimal correspondente.

main(){
       int bin,a1,a2,a3,a4,dec;
       printf("Digite um numero binario de quatro digitos.\n");
       scanf("%d",&bin);
       a1 = bin / 1000;
       a2 = bin % 1000 / 100;
       a3 = bin % 1000 % 100 / 10;
       a4 = bin % 1000 % 100 % 10;
       dec = a1 * 8 + a2 * 4 + a3 * 2 + a4;
       printf("\nO numero binario %04d corresponde ao numero decimal %d.",bin,dec);
       getch();
}
