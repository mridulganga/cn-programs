#include <stdio.h>
#include <string.h>
#include <unistd.h>

int crc(char input[],char output[],char gp[],int mode){
  int i,j;
  strcpy(output,input);

  if (mode==0){
    for(i=1;i<strlen(gp);i++)
      strcat(output,"0");
  }

  for (i=0;i<strlen(input);i++){
    if (output[i]=='1'){
      for (j=0;j<strlen(gp);j++){
        if ((output[i+j]=='0') && (gp[j]=='0') || (output[i+j]=='1') && (gp[j]=='1'))
          output[i+j]='0';
        else
          output[i+j]='1';
      }
    }
  }
  for (i=0;i<strlen(output);i++){
    if (output[i]=='1') return 1;
  }
  return 0;
}

int main(){
  char input[50],output[50],r[50],gp[18]="10001000000100001";

  printf("Enter code: ");
  scanf("%s",input);
  crc(input,output,gp,0);

  printf("%s%s\n",input,output+strlen(input));

  printf("Enter the encoded crc: ");
  scanf("%s",r);
  if (crc(r,output,gp,1))
    printf("Error\n");
  else
    printf("NO Error\n");



}
