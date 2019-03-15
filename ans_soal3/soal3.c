#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <syslog.h>
#include <string.h>

int main() {
    int pip[3],stat;
    char *unzip[] = {"unzip","campur2.zip",NULL};
    char *mkfile[] = {"touch","daftar.txt",NULL};
    char *viewlist[] = {"ls","campur2",NULL};
    char *awkgrep[] = {"grep",".txt$",NULL};
    pid_t child_id = fork();
    if(!child_id){
        execv("/usr/bin/unzip",unzip);
    }else {
        child_id=fork();
        if(!child_id){
            execv("/usr/bin/touch",mkfile);
        }else {
            while((wait(&stat))>0);
            pipe(pip);
            child_id=fork();
            if(!child_id){
                dup2(pip[1],1);
                close(pip[0]);
                execv("/bin/ls",viewlist);
            }else {
                pip[2]= open("daftar.txt",O_WRONLY);
                dup2(pip[0],0);
                dup2(pip[2],1);
                close(pip[1]);
                execv("/bin/grep",awkgrep);
            }
            close(pip[0]);
        }
    }
    return 0;
}
