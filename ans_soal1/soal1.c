#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <dirent.h>

int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
//  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
    int status;
    pid_t c_id;
    c_id = fork();
    if(c_id==0){
      char *ar[]={"mkdir","/home/yong/modul2/Gambar",NULL};
      execv("/bin/mkdir",ar);
    }
    else{
      while((wait(&status))>0);
      int i;
      struct dirent *de;
      char fo[101]="/home/yong/Pictures/";
      char fn[101]="/home/yong/modul2/Gambar/";
      char temp[10]="_grey.png";
      DIR *dr = opendir(fo);
      while((de=readdir(dr))!=NULL)
      {
        char old[101];strcpy(old,de->d_name);
        if(strstr(old,".png")==NULL) continue;
        char c[101];strcpy(c,old);
        for(i=100;i>=0;i--){
            if(c[i]=='.') {c[i]='\0';break;}
            c[i]='\0';
        }
        char oldfile[999],newfile[999];
        strcpy(oldfile,fo);
        strcat(oldfile,old);
        strcpy(newfile,fn);
        strcat(newfile,c);
        strcat(newfile,temp);
        rename(oldfile,newfile);
      }
    }
    sleep(30);
  }
  
  exit(EXIT_SUCCESS);
}
