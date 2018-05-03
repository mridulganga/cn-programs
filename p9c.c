#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
  int fd1,fd2,fd;
  char filename[100],buffer[1024];


  fd1=open("/tmp/filename.fifo",O_WRONLY);
  fd2=open("/tmp/filedata.fifo",O_RDONLY);

  scanf("%s",filename);
  write(fd1,filename,1+strlen(filename));
  read(fd2,buffer,1024);
  printf("%s",buffer);

  close(fd2);
  close(fd1);

}
