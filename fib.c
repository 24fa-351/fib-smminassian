// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int fibbonachiRecurs(int num, long long int *fibArray)
// {
//    long long int fibValue = 0;
//    if (num == 0 || num == 1)
//    {
//       return num;
//    }
//    else if (fibArray[num] == 0)
//    {
//       fibValue = fibbonachiRecurs(num - 1, fibArray) + fibbonachiRecurs(num - 2, fibArray);
//       fibArray[num] = fibValue;
//    }

//    return fibArray[num];
// }

// int fibbonachiItera(int n)
// {
//    int num1 = 0;
//    int num2 = 1;
//    int num3 = 0;
//    for (int i = 2; i <= n; i++)
//    {
//       num3 = num1 + num2;
//       num1 = num2;
//       num2 = num3;
//    }
//    return num3;
// }

// int main(int __argc, char *__argv[])
// {

//    if (__argc == 4)
//    {
//       int i = 0;
//       FILE *filePointer;
//       int fileNum = 0;
//       int nthNum = 0;
//       long long int fibbonachiNum = 0;
//       int num1 = 0;

//       filePointer = fopen(__argv[3], "r");
//       fscanf(filePointer, "%d", &fileNum);
//       fclose(filePointer);

//       num1 = atoi(__argv[1]);
//       nthNum = num1 + fileNum;

//       long long int *fibArray = calloc(nthNum, sizeof(long long int));

//       fibArray[0] = 0;
//       fibArray[1] = 1;

//       if (*__argv[2] == 'i')
//       {
//          fibbonachiNum = fibbonachiItera(nthNum - 1);
//       }
//       else if (*__argv[2] == 'r')
//       {
//          fibbonachiNum = fibbonachiRecurs(nthNum - 1, fibArray);
//       }

//       free(fibArray);
//       printf("%lld", fibbonachiNum);
//    }

//    return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fibbonachiRecurs(unsigned long long num)
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

unsigned long long fibbonachiItera(unsigned long long n)
{
   unsigned long long num1 = 0;
   unsigned long long num2 = 1;
   unsigned long long num3 = 0;
   for (int i = 2; i <= n; i++)
   {
     
         num3 = num1 + num2;
         num1 = num2;
         num2 = num3;
      
      
   }
   return num3;
}

int main(int __argc, char *__argv[])
{
   FILE *filePointer;
   unsigned long long fileNum = 0;
   unsigned long long nthNum = 0;
   unsigned long long fibbonachiNum = 0;
   unsigned long long num1 = 0;

   if (__argc == 4)
   {

      filePointer = fopen(__argv[3], "r");
      fscanf(filePointer, "%llu", &fileNum);
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

        printf("%llu", fibbonachiNum);
   }

 

   return 0;
}
