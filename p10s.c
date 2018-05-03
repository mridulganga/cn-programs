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
  struct hostent *lh;
  socklen_t addrsize;

  sfd = socket(AF_INET,SOCK_DGRAM,0);
  address.sin_family = AF_INET;
  address.sin_port = htons(8090);
  address.sin_addr.s_addr = inet_addr("127.0.0.1");

  bind(sfd,(struct sockaddr*) & address, sizeof address);
  listen(sfd,5);

  // addrsize = sizeof sstore;
  addrsize = (sizeof address);
  while(recvfrom(sfd,hostname,100,0,(struct sockaddr*)&address,(socklen_t*)&addrsize)){
    // cfd = accept(sfd,(struct sockaddr*) &sstore,&addrsize);
    printf("Hostname : %s\n",hostname);

    lh = gethostbyname(hostname);
    // address.sin_addr.S_addr=(u_long)lh->h_addr;
    sendto(sfd,inet_ntoa(*(struct in_addr *)lh->h_addr_list[0]),
                strlen(inet_ntoa(*(struct in_addr *)lh->h_addr_list[0])),
                0,(struct sockaddr*)&address,(socklen_t)addrsize);
    memset(hostname,0,strlen(hostname));

  }
  close(sfd);
  close(cfd);

}
