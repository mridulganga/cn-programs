#include <stdio.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>


int main(){

  int sfd,cfd,fd,n,op,i;
  char lpaddress[100]={0},contents[1024]={0};
  struct sockaddr_in address;
  char *ip_list[2]={"1.1.1.1","2.2.2.2"};
  char *mac_list[2]={"abc","def"};

  sfd = socket(AF_INET,SOCK_STREAM,0);
  address.sin_family = AF_INET;
  address.sin_port = htons(8090);
  address.sin_addr.s_addr = inet_addr("127.0.0.1");

  bind(sfd,(struct sockaddr*) & address, sizeof address);
  listen(sfd,5);

  while(cfd = accept(sfd,(struct sockaddr*) NULL,NULL)){
    // cfd = accept(sfd,(struct sockaddr*) &sstore,&addrsize);
    recv(cfd,lpaddress,100,0);
    printf("lpaddress : %s\n",lpaddress);


    for (i=0;i<2;i++){
        if (strcmp(ip_list[i],lpaddress)==0){
          send(cfd,mac_list[i],strlen(mac_list[i]),0);
        }
    }

  }
  close(sfd);
  close(cfd);

}
