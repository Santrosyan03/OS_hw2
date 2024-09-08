#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void run_command(const char *command, const char *arg) {
    execl(command, arg, NULL);
    perror("execl method failed");
    exit(1);
}

int main() {
    pid_t pid1 = fork();

    if (pid1 == -1) {
        perror("Fork method failed");
        exit(1);
    } else if (pid1 == 0) {
        run_command("/bin/ls", "ls");
    } else {
        pid_t pid2 = fork();

        if (pid2 == -1) {
            perror("Second fork method failed");
            exit(1);
        } else if (pid2 == 0) {
            run_command("/bin/date", "date");
        } else {
            wait(NULL);
            wait(NULL);
            printf("Parent process done\n");
        }
    }

    return 0;
}
