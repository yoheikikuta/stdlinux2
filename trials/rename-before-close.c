#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/stat.h>
#include <fcntl.h>

int main (int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "%s: wrong arguments\n", argv[0]);
        exit(1);
    }
    
    char *path = argv[1];
    char buf[] = "test\n";

    int fd = open(path, O_RDWR);
    rename(argv[1],argv[2]);
    write(fd, buf, sizeof(buf));
    close(fd);

    exit(0);
}