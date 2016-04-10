main()
{
    float total;
    printf ("Insira o valor total da conta.\n");
    scanf ("%f", &total);
    total = total + total * 0.1;
    printf ("\nO valor que devera' ser pago e' de R$ %.2f.", total);
    getch();
}
