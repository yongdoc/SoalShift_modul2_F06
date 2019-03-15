#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

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
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while(1){
        int i=30;
        char buf[100],folder[999]="/home/yong/modul2/log/";
        char locsyslog[]="/var/log/syslog";
        FILE *readfile;
        time_t current;
        current=time(NULL);
        struct tm *curtime= localtime(&current);
        strftime(buf,100,"%d:%m:%Y-%H:%M",curtime);
        strcat(folder,buf);
        mkdir(folder,S_IWUSR|S_IWGRP|S_IWOTH);
        while(i){
        char newlog[100];
        snprintf(newlog,100,"%s/log%d.log",folder,31-i);
        readfile=fopen(locsyslog,"r");
        FILE *writefile=fopen(newlog,"w");
        while(fgetc(readfile)!=EOF){
            fputc(fgetc(readfile),writefile);
        }
        fclose(readfile);fclose(writefile);
        i--;
        sleep(60);
        }
    }

    exit(EXIT_SUCCESS);
}
