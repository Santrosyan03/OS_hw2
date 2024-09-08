#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void run_ls_command() {
    execl("/bin/ls", "ls", NULL);
    perror("execl method failed");
    exit(1);
}

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork method failed");
        exit(1);
    } else if (pid == 0) {
        run_ls_command();
    } else {
        wait(NULL);
        printf("Parent process done\n");
    }

    return 0;
}
