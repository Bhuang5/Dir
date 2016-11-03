#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

int main(){
  DIR *stream = opendir(".");
  struct dirent *cur;
  printf("\n===Directories=== \n");
  while((cur = readdir(stream))){ //Assignment returns the value of the variable that was assigned to
    if(cur->d_type == DT_DIR)
      printf("\t%s\n",cur->d_name);
  }
  closedir(stream); //Close and reopen to "reset" could also rewind


  printf("===Files=== \n"); 
  
  struct stat file;
  int total = 0;
  stream = opendir(".");
  while((cur=readdir(stream))){
    if(cur->d_type == DT_REG){
      printf("\t %s",cur->d_name);
      stat(cur->d_name,&file); //stat takes a path and buffer
      total += file.st_size;
      printf("\t %lld Bytes\n",file.st_size);
    }
  }
  closedir(stream);
  printf("Total Size of CWD: %d Bytes\n\n",total);
  return 0;

}
