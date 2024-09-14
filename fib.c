#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibbonachiRecurs(int num, long long int* fibArray)
{
   int fibValue = 0;
   if (num == 0 || num == 1)
   {
      return num;
   }
   else if (fibArray[num] == 0)
   {
      fibValue = fibbonachiRecurs(num - 1, fibArray) + fibbonachiRecurs(num - 2, fibArray);
      fibArray[num] = fibValue;
   }
  
   return fibArray[num];
}

int fibbonachiItera(int n)
{
   int num1 = 0;
   int num2 = 1;
   int num3 = 0;
   for (int i = 2; i <= n; i++)
   {
      num3 = num1 + num2;
      num1 = num2;
      num2 = num3;
   }
   return num3;
}

int main(int argc, char *argv[])
{
   
   int i = 0;
   FILE *filePointer;
   int fileNum = 0;
   int nthNum = 0;
   long long int fibbonachiNum = 0;
   int num1 = 0;

   if (argc == 4)
   {
      
      filePointer = fopen(argv[3], "r");
      fscanf(filePointer, "%d", &fileNum);
      fclose(filePointer);

      num1 = atoi(argv[1]);
      nthNum = num1 + fileNum;

    long long int *fibArray = calloc(nthNum,sizeof(long long int));

      

         if (*argv[2] == 'i')
         {
            fibbonachiNum = fibbonachiItera(nthNum - 1);
         }
         else if (*argv[2] == 'r')
         {
            fibbonachiNum = fibbonachiRecurs(nthNum - 1, fibArray);
         }
      
      free(fibArray);
   }
   
   printf("%lld", fibbonachiNum);

   return 0;
}
