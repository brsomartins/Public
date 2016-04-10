/*
    Faça um programa que leia o ano atual e quantos anos uma pessoa fez ou fará
    neste ano. Em seguida, calcule o ano em que a pessoa nasceu.
*/

main()
{
    int anoat, idade, anonasc;
    printf ("Digite o ano em que estamos.\n");
    scanf ("%d", &anoat);
    printf ("\nDigite quantos anos voce tem ou fara' neste ano.\n");
    scanf ("%d", &idade);
    anonasc = anoat - idade;
    printf ("\nVoce nasceu em %d.", anonasc);
    getch();
}
