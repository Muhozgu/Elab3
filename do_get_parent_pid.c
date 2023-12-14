#include <stdio.h>
#include <unistd.h>
#include <lib.h>

#define PM_GETPARENTPID 20  // we use the same number as in kernel/system.h

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child process (PID=%d) - Parent PID from syscall: %d\n", getpid(), syscall(PM_GETPARENTPID));
    } else {
        // Parent process
        printf("Parent process (PID=%d)\n", getpid());
    }

    return 0;
}