#include <stdio.h>
#include <string.h>

int sameWhenShifted(char* s1, char* s2){
     int shiftCount = 0;
     int a, b;
     char temp2[100];
     strcpy(temp2, s1);
     int len1 = strlen(s1);
     int len2 = strlen(s2);

     if(len1 != len2){
          return -1;
     }

     for(a = 0; a < len1; a++){
          if(strcmp(temp2,s2) == 0){
               return shiftCount;
          }
          else{
               char temp = temp2[0];
               for(b = 0; b < len1-1; b++){
                    temp2[b] = temp2[b + 1];
               }
               temp2[len1-1] = temp;
               shiftCount++;
          }
     }
     return -1;
}

int main(int argc, char *argv[]){

     char s1[100], s2[100];
     printf("Enter string 1 : ");
     scanf("%s", s1);
     printf("Enter string 2 : ");
     scanf("%s", s2);
     int ans = sameWhenShifted(s1, s2);
     if(ans != -1){
          printf("%s shifts %d to get %s\n", s1, ans, s2);
     }
     else{
          printf("Cannot build %s from %s\n", s2, s1);
     }

     return 0;
}
