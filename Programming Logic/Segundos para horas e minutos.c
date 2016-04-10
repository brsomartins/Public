main(){
       int tot,h,min,s;
       printf("Entre com o total de segundos.\n");
       scanf("%d",&tot);
       h = tot / 3600;
       min = tot % 3600 / 60;
       s = tot % 3600 % 60;
       printf("\n%d s sao equivalente a %02d:%02d:%02d.",tot,h,min,s);
       getch();
}
