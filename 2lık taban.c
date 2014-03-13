#include <stdio.h>
#include <conio.h>
  
/*
    Bilal Baraz
    http://www.bilalbaraz.com
*/
  
main(){
       int x, k[30],i=0;
       printf("Bir sayi giriniz: ");
       scanf("%d",&x);
         
       while(x >= 1){
               i++;
               k[i] = x%2;
               x = x / 2;
       }
         
       printf("ikilik tabana cevrilmis hali: ");
       while(i > 0){
               printf("%d",k[i]);
               i--;
       }
  
getch();
} 
