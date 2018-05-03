#include <stdio.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>


int main(){

  int sfd,cfd,fd,n;
  char filename[100]={0},contents[1024]={0};
  struct sockaddr_in address;
  struct sockaddr_storage sstore;
  socklen_t addrsize;

  sfd = socket(AF_INET,SOCK_STREAM,0);
  address.sin_family = AF_INET;
  address.sin_port = htons(8090);
  address.sin_addr.s_addr = inet_addr("127.0.0.1");

  bind(sfd,(struct sockaddr*) & address, sizeof address);
  listen(sfd,5);

  addrsize = sizeof sstore;
  while(cfd = accept(sfd,(struct sockaddr*) &sstore,&addrsize)){
    // cfd = accept(sfd,(struct sockaddr*) &sstore,&addrsize);
    recv(cfd,filename,100,0);
    printf("Filename : %s\n",filename);

    fd = open(filename,O_RDONLY);
    while(n=read(fd,contents,1024)){
      send(cfd,contents,strlen(contents),0);
    }
  }
  close(sfd);
  close(cfd);
  close(fd);

}
