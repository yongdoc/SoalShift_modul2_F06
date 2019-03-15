#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(){
    char pid[10];
    char getpid[]="pidof /home/yong/modul2/soal5a";
    FILE *process=popen(getpid,"r");
    fgets(pid,10,process);
    pid_t p_id=strtol(pid,NULL,10);
    pclose(process);
    kill(p_id,SIGKILL);
    return 0;
}
