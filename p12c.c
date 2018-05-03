#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>


int main(){
  int sfd,n;
  char lpaddress[100],contents[1024]={0};
  struct sockaddr_in server_addr;

  sfd = socket(AF_INET,SOCK_STREAM,0);
  server_addr.sin_port = htons(8090);
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  connect(sfd,(struct sockaddr*) &server_addr, sizeof server_addr);
  printf("Enter lpaddress: ");
  scanf("%s",lpaddress);
  send(sfd,lpaddress,strlen(lpaddress),0);

  n=recv(sfd,contents,1024,0);
  write(1,contents,n);

  close(sfd);
}
