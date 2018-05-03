#include <stdio.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <netdb.h>


int main(){

  int sfd,cfd,fd,n;
  char hostname[100]={0},contents[1024]={0};
  struct sockaddr_in address;
  // struct sockaddr_storage sstore;
  // socklen_t addrsize;
  struct hostent *lh;

  sfd = socket(AF_INET,SOCK_STREAM,0);
  address.sin_family = AF_INET;
  address.sin_port = htons(8090);
  address.sin_addr.s_addr = inet_addr("127.0.0.1");

  bind(sfd,(struct sockaddr*) & address, sizeof address);
  listen(sfd,5);

  // addrsize = sizeof sstore;
  while(cfd = accept(sfd,(struct sockaddr*)NULL,NULL)){
    // cfd = accept(sfd,(struct sockaddr*) &sstore,&addrsize);
    memset(hostname,0,strlen(hostname));
    recv(cfd,hostname,100,0);
    printf("Hostname : %s\n",hostname);

    lh = gethostbyname(hostname);
    // address.sin_addr.S_addr=(u_long)lh->h_addr;
    send(cfd,inet_ntoa(*(struct in_addr *)lh->h_addr_list[0]),strlen(inet_ntoa(*(struct in_addr *)lh->h_addr_list[0])),0);

  }
  close(sfd);
  close(cfd);

}
