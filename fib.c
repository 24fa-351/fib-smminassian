#include <stdio.h>
#include <math.h>

int fibbonaciRecurs(int num)
{
   if (num == 0 || num == 1)
   {
      return num;
   }
   else
   {
      return fibbonaci(num - 1) + fibbonaci(num - 2);
   }
}

int fibbonachiItera(int n){
   int num1 = 0;
   int num2 = 1;
   int num3;
   for(int i = 2; i <= n; i++){
      if(n != 0){
         num3 = num1+num2;
         num1 = num2;
         num2 = num3;
      }
      else{
         return num1;
      }
   }
   return num3;
   
}

int FileLogic(char* TextFile[100]){
   FILE *fpointer;
   int fileNum;

   char temp = TextFile[100];
   
   fpointer = fopen(&temp, 100, "w");
   scanf("%d", fileNum);
   fprintf(fpointer, fileNum);
   fclose(fpointer);

   fpointer = fopen("test.txt", "r");
   char FileNumHolder[100];
   fgets(FileNumHolder, 100, fpointer);
   fclose(fpointer);

   fileNum = atoi(FileNumHolder);

   return fileNum;
}

int main()
{
   int num1;
   char nameOfTextFile[100];
   char recursiveOrIterative;

   scanf("%d", "%c", "%c", &num1, &recursiveOrIterative, &nameOfTextFile[100]);

   int theFileNumber = FileLogic(&nameOfTextFile);
   int nthNum = num1 + theFileNumber;
   int FibbonachiNum;
  
   if(recursiveOrIterative == "i"){
     FibbonachiNum = fibbonaciItera(nthNum);
   } 
   else{
     FibbonachiNum = fibbonaciRecurs(nthNum);
   }

   printf("The %dth of the fibbonachi series is %d", &nthNum, &FibbonachiNum);

   return 0;

}