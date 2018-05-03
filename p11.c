#include <stdio.h>

int main(){

  int a[7],b[7];
  int n1,n2,n3,n,i;

  printf("Enter 4 bit input: ");
  scanf("%d",&a[0]);scanf("%d",&a[1]);scanf("%d",&a[2]);scanf("%d",&a[4]);
  a[3]=a[0]^a[1]^a[2];
  a[5]=a[0]^a[1]^a[4];
  a[6]=a[0]^a[2]^a[4];
  printf("\nGenerated code:\n");
  for (i=0;i<7;i++)
    printf("%d",a[i]);
  printf("\n");

  printf("Enter received code : ");
  for (i=0;i<7;i++)
    scanf("%d",&b[i]);

  n1 = b[6]^b[4]^b[2]^b[0];
  n2 = b[5]^b[4]^b[1]^b[0];
  n3 = b[3]^b[2]^b[1]^b[0];
  n = n3*4+n2*2+n1;
  if (n>0)
    b[7-n]=b[7-n]?0:1;

  printf("\nCorrect Code is : \n");
  for (i=0;i<7;i++)
    printf("%d",b[i]);
  printf("\n");
}
