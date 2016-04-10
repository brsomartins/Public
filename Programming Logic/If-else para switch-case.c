//Transforme o algoritmo em if-else abaixo para switch-case.

/*
main(){
       int l;
       printf("Entre com uma letra.\n");
       scanf("%c",&l);
       if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')
          printf("\nVogal.");
       else
           printf("\nConsoante.");
       getch();
}
*/

main(){
       int l;
       printf("Entre com uma letra.\n");
       scanf("%c",&l);
       switch (l){
              case ('a'):
              case ('e'):
              case ('i'):
              case ('o'):
              case ('u'):
              case ('A'):
              case ('E'):
              case ('I'):
              case ('O'):
              case ('U'):
                   printf("\nVogal.");
                   break;
              default:
                      printf("\nConsoante.");
                      break;
       }
       getch();
}
