#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){

     int bad1 = 0, bad2 = 0, bad3 = 0, unknown = 0;
     int temp1, temp2, temp3;
     FILE *fp1 = fopen("Data1", "r");
     FILE *fp2 = fopen("Data2", "r");
     FILE *fp3 = fopen("Data3", "r");

     fscanf(fp1, "%d", &temp1);
     fscanf(fp2, "%d", &temp2);
     fscanf(fp3, "%d", &temp3);

     while(!feof(fp1) && !feof(fp2) && !feof(fp3)){
          if(temp1 == temp2 && temp3 != temp1){
               bad3++;
          }
          else if(temp2 == temp3 && temp1 != temp2){
               bad1++;
          }
          else if(temp1 == temp3 && temp2 != temp1){
               bad2++;
          }
          else if(temp1 != temp2 && temp1 != temp3 && temp2 != temp3){
               unknown++;
          }
          fscanf(fp1, "%d", &temp1);
          fscanf(fp2, "%d", &temp2);
          fscanf(fp3, "%d", &temp3);
     }
     printf("Data1 has %d possible bad values\n", bad1);
     printf("Data2 has %d possible bad values\n", bad2);
     printf("Data3 has %d possible bad values\n", bad3);
     printf("There are %d unknown cases\n", unknown);


     fclose(fp1); fclose(fp2); fclose(fp3);
     return 0;
}
