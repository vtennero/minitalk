#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void handle_signal(int signal) {
    printf("Received signal %d\n", signal);
    // Handle the signal, e.g., terminate or perform an action
}

int main() {
    printf("Server PID: %d\n", getpid());

    // Set up the signal handler
    if (signal(SIGUSR1, handle_signal) == SIG_ERR) {
        perror("signal error");
        return 1;
    }

    // Keep the process running to receive signals
    while (1) {
        sleep(1);
    }

    return 0;
}
