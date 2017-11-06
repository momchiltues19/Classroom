
#include <stdio.h>
#include <stdint.h>
//#include "read.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


void *read_image(char *path) {
        int fd = open(path, O_RDONLY);
        if (fd < 0) {
            return NULL;
        }
        size_t size = 1000;
        size_t offset = 0;
        size_t res;
        char *buff = malloc(size);

        while((res = read(fd, buff + offset, 100)) != 0) {
                offset += res;
                if (offset + 100 > size) {
                        size *= 2;
                        buff = realloc(buff, size);
                }
        }
        close(fd);
        return buff;
}

void bmp_info(char *);

int main(/*char* argv[]*/)
{
    bmp_info("2020.bmp");
    return 0;
}

void bmp_info(char *file_name)
{
    int32_t width, height;
    uint8_t *f;
    f = read_image(file_name);
    width = *(f+18);
    height = *(f+22);
    printf("BMP image width: %d\nBMP image height: %d\n", width, height);
}

