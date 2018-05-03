#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
  int fd1,fd2,fd;
  char filename[100]={0},buffer[1024]={0};

  mkfifo("/tmp/filename.fifo",0666);
  mkfifo("/tmp/filedata.fifo",0666);

  fd1=open("/tmp/filename.fifo",O_RDONLY);
  fd2=open("/tmp/filedata.fifo",O_WRONLY);

  read(fd1,filename,100);
  fd = open(filename,O_RDONLY);
  read(fd,buffer,1024);
  close(fd);
  write(fd2,buffer,strlen(buffer));


  close(fd2);
  close(fd1);

}
