//Fa�a um programa que leia um n�mero bin�rio de quatro d�gitos e diga quantos d�gitos zero existem nesse n�mero.

main(){
       int bin,a1,a2,a3,a4,zer;
       printf("Digite um numero binario de quatro digitos.\n");
       scanf("%d",&bin);
       a1 = bin / 1000;
       a2 = bin % 1000 / 100;
       a3 = bin % 1000 % 100 / 10;
       a4 = bin % 1000 % 100 % 10;
       zer = 4 - (a1 + a2 + a3 + a4);
       printf("\nNo numero binario %04d existe(m) %d algarismo(s) zero.",bin,zer);
       getch();
}
