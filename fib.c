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

int fibbonachiItera(int n)
{
   int num1 = 0;
   int num2 = 1;
   int num3 = 0;
   for (int i = 2; i <= n; i++)
   {
      if (n != 0)
      {
         num3 = num1 + num2;
         num1 = num2;
         num2 = num3;
      }
      else
      {
         return num1;
      }
   }
   return num3;
}

int main()
{
   int num1;
   char nameOfTextFile[20];
   char recursiveOrIterative[2];

   scanf("%d %s %s", &num1, recursiveOrIterative, nameOfTextFile);

   FILE *fpointer;
   int fileNum;

   fpointer = fopen(nameOfTextFile, "r");
   fscanf(fpointer, "%d", &fileNum);
   fclose(fpointer);

   int nthNum = num1 + fileNum;
   int FibbonachiNum;

   if (*recursiveOrIterative == 'i')
   {
      FibbonachiNum = fibbonachiItera(nthNum-1);
   }
   else if (*recursiveOrIterative == 'r')
   {
      FibbonachiNum = fibbonachiRecurs(nthNum-1);
   }

   printf("%d", FibbonachiNum);

   return 0;
}

