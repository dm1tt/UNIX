#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd;
    char buf[100];
    fd = open("/dev/test", O_RDWR);
    read(fd, buf, 20);
    buf[20] = 0;
    printf("Input: >>> %s <<<\n", buf);
    close(fd);
}

