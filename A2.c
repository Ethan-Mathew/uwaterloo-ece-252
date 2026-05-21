#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int print_from_fd(int fd) {
    char* buffer = (char*)malloc(256);
    memset(buffer, 0, 256);

    ssize_t read_count = read(fd, buffer, 256);

    if (read_count == 0) {
        free(buffer);
        return 0;
    }

    write(1, buffer, 256);

    free(buffer);

    return 1;
}

int main(int argc, char** argv) {
    if (argc == 1) {
        while (print_from_fd(0)) {
        }
    }

    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);

        if (fd > 0) {
            while(print_from_fd(fd)) {

            }
        } else {
            perror("Error");
        }
        write(1, "\n", 1);

        close(fd);
    }


    return 0;
}