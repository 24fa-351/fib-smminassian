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

   scanf("%d %c %c", &num1, &recursiveOrIterative, nameOfTextFile);


   FILE *fpointer;
   char fileNum[30];

   fpointer = fopen(nameOfTextFile, "r");      //my error is between line 45 to 51. I know I am getting a seg fault, its just If i get rid of the array in fileNum and i make test, my code complains by saying 
                                                //"format ‘%c’ expects argument of type ‘char *’, but argument 4 has type ‘char (*)[100]’". Other than the seg fault I dont know why it does not work. I wiill get my debugger working and debug this tomorrow.
   fscanf(fpointer, "%c", fileNum);
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

   printf("%d",FibbonachiNum);

   return 0;

}