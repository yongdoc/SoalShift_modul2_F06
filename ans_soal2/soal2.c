#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

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
        struct stat filestat;
        char elen[] = "/home/yong/modul2/hatiku/elen.ku";
        while(stat(elen,&filestat)!=0){
            sleep(3);
            continue;
        }
        chmod(elen,S_IWUSR|S_IWGRP|S_IWOTH);
        struct passwd *usrname;
        struct group *grpname;
        usrname = getpwuid(filestat.st_uid);
        grpname = getgrgid(filestat.st_gid);
        if(!strcmp("www-data",usrname->pw_name)&&!strcmp("www-data",grpname->gr_name)){
            remove(elen);
        }
        sleep(3);
    }

    exit(EXIT_SUCCESS);
}
