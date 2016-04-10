main(){
       #define PI 3.1415
       float vol,r,h;
       printf("Entre com o raio da lata (em cm).\n");
       scanf("%f",&r);
       printf("Entre com a altura da lata (em cm).\n");
       scanf("%f",&h);
       vol = PI * pow(r,2) * h;
       printf("\nO volume da lata e' %.2f cm cu'bicos.",vol);
       getch();
}
