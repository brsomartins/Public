main(){
       int h,min,s,tot;
       printf("Entre com as horas.\n");
       scanf("%d",&h);
       printf("Entre com os minutos.\n");
       scanf("%d",&min);
       printf("Entre com os segundos.\n");
       scanf("%d",&s);
       tot = h * 3600 + min * 60 + s;
       printf("\n%02d:%02d:%02d e' equivalente a %d s.",h,min,s,tot);
       getch();
}
