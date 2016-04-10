main(){
       float a,b,aux;
       printf("Entre com o valor 'a'.\n");
       scanf("%f",&a);
       printf("Entre com o valor 'b'.\n");
       scanf("%f",&b);
       aux = a;
       a = b;
       b = aux;
       printf("\na = %0.f\nb = %0.f.",a,b);
       getch();
}
