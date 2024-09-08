#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibbonachiRecurs(int num)
{
   if (num == 0 || num == 1)
   {
      return num;
   }
   else
   {
      return fibbonachiRecurs(num - 1) + fibbonachiRecurs(num - 2);
   }
}

int fibbonachiItera(int n){
   int num1 = 0;
   int num2 = 1;
   int num3;
   for(int i = 2; i <= n; i++){
      if(n != 0){
         num3 = num1 + num2;
         num1 = num2;
         num2 = num3;
      }
      else{
         return num1;
      }
   }
   return num3;
   
}

int main()
{
   int num1;
   char nameOfTextFile[100];
   char recursiveOrIterative;

   scanf("%d %c %c", &num1, &recursiveOrIterative, &nameOfTextFile[100]);


   FILE *fpointer;
   char fileNum = '3';

   fpointer = fopen(nameOfTextFile, "w");
   fputs(fileNum, fpointer);
   fclose(fpointer);

   fpointer = fopen(nameOfTextFile, "r");
   fgets(fileNum, 50, fpointer);

   scanf(fileNum, 100, fpointer);
   fclose(fpointer);

   int integerFileNum = atoi(fileNum);

   int nthNum = num1 + integerFileNum;
   int FibbonachiNum;
  
   if(recursiveOrIterative == 'i'){
     FibbonachiNum = fibbonachiItera(nthNum);
   } 
   else if(recursiveOrIterative == 'r'){
     FibbonachiNum = fibbonachiRecurs(nthNum);
   }

   printf("The %dth of the fibbonachi series is %d", nthNum, FibbonachiNum);

   return 0;

}