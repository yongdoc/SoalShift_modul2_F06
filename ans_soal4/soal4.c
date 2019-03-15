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
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    int countmakan=1;
    while(1){
        struct stat fmakanenak={0};
        if(stat("/home/yong/Documents/makanan/makan_enak.txt",&fmakanenak)!=0){
            sleep(5);
            continue;
        }
        time_t curtime;
        time(&curtime);
        double lastacc = difftime(curtime,fmakanenak.st_atime);
        char newfile[100] = "/home/yong/Documents/makanan/makan_sehat";
        char typefile[25];
        if(lastacc<=30){
            snprintf(typefile,25,"%d.txt",countmakan);
            strcat(newfile,typefile);
            FILE *fnew = fopen(newfile,"w");
            fputs("ayo diet\n",fnew);
            fclose(fnew);
            countmakan++;
        }
        sleep(5);
    }

    exit(EXIT_SUCCESS);
}
