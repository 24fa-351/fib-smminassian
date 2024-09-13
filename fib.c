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

int main(int __argc, char *__argv[])
{
   int i;
   FILE *filePointer;
   int fileNum = 0;
   char nameOfTextFile[20];
   int nthNum = 0;
   int fibbonachiNum = 0;
   int num1 = 0;

   if (__argc == 4)
   {
      filePointer = fopen(__argv[3], "r");
      fscanf(filePointer, "%d", &fileNum);
      fclose(filePointer);

      num1 = atoi(__argv[1]);
      nthNum = num1 + fileNum;

      if (*__argv[2] == 'i')
      {
         fibbonachiNum = fibbonachiItera(nthNum - 1);
      }
      else if (*__argv[2] == 'r')
      {
         fibbonachiNum = fibbonachiRecurs(nthNum - 1);
      }
   }

   printf(" %dth %d", nthNum, fibbonachiNum);

   return 0;
}