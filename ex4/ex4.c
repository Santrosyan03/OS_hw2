#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork method failed");
        exit(1);
    } else if (pid == 0) {
        execl("/bin/grep", "grep", "main", "test.txt", NULL);
        perror("execl method failed");
        exit(1);
    } else {
        wait(NULL);
        printf("Parent process done\n");
    }

    return 0;
}
