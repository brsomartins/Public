/*
    Fa�a um programa que leia a temperatura em �C e converta para �F. A f�rmula
    de convers�o �: f = 9c + 160 / 5.
*/

main()
{
    float tc, tf;
    printf ("Entre com a temperatura em graus C.\n");
    scanf ("%f", &tc);
    tf = (9 * tc + 160) / 5;
    printf ("\nA temperatura %.2f graus C e' igual a %.2f graus F.", tc, tf);
    getch();
}
