//Fa�a um programa que leia dois n�meros distintos e diga qual � o maior.

main(){
       float n1,n2;
       printf("Entre com dois valores:\n");
       scanf("%f%f",&n1,&n2);
       if (n1 > n2)
          printf("\n%f > %f",n1,n2);
       else
           printf("\n%f > %f",n2,n1);
       getch();
}
