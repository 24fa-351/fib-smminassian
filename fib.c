
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
   int num3;
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

   scanf("%d", &num1);
   scanf("%s", recursiveOrIterative);
   scanf("%s", nameOfTextFile);

   FILE *fpointer;
   int fileNum;

   fpointer = fopen(nameOfTextFile, "w");
   fprintf(fpointer, "1");
   fclose(fpointer);

   fpointer = fopen(nameOfTextFile, "r");
   fscanf(fpointer, "%d", &fileNum);
   fclose(fpointer);

   int nthNum = num1 + fileNum;
   int FibbonachiNum;

   if (*recursiveOrIterative == 'L')
   {
      FibbonachiNum = fibbonachiItera(nthNum);
   }
   else if (*recursiveOrIterative == 'T')
   {
      FibbonachiNum = fibbonachiRecurs(nthNum);
   }

   printf("The %dth of the fibbonachi series is %d", nthNum, FibbonachiNum);

   return 0;
}

