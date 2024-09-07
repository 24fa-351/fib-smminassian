#include <stdio.h>
#include <stdlib.h>

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
   int* fileNumPtr = fileNum;

   char *temp = TextFile[100];
   
   fpointer = fopen(temp, "w");
   scanf("%d", fileNumPtr);
   fprintf(fpointer, fileNumPtr);
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
   char nameOfTextFile[1000];
   char recursiveOrIterative;

   scanf("%d", "%c", "%c", &num1, &recursiveOrIterative, &nameOfTextFile[100]);

   int theFileNumber = FileLogic(&nameOfTextFile);
   int nthNum = num1 + theFileNumber;
   int FibbonachiNum;
  
   if(recursiveOrIterative == "i"){
     FibbonachiNum = fibbonachiItera(nthNum);
   } 
   else{
     FibbonachiNum = fibbonachiRecurs(nthNum);
   }

   printf("The %dth of the fibbonachi series is %d", &nthNum, &FibbonachiNum);

   return 0;

}