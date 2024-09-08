#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void create_process(const char *process_name) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork method failed");
        exit(1);
    } else if (pid == 0) {
        printf("Child process created by %s: PID = %d, Parent PID = %d\n", process_name, getpid(), getppid());
    } else {
        printf("Parent process after %s: PID = %d, Created Child PID = %d\n", process_name, getpid(), pid);
    }
}

int main() {
    create_process("First fork - Initial child creation");
    create_process("Second fork - Adding another process");
    create_process("Third fork - Final process addition");

    sleep(1);

    return 0;
}
