#include <stdio.h>
#include <stdlib.h>
#include <signal.h>  // For the kill function
#include <sys/types.h>  // For pid_t

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <signal> <pid>\n", argv[0]);
        return 1;
    }

    int sig = atoi(argv[1]);
    pid_t pid = (pid_t)atoi(argv[2]);

    if (kill(pid, sig) == -1)
    {
        perror("kill error");
        return 1;
    }

    printf("Signal %d sent to PID %d\n", sig, pid);
    return 0;
}
