#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t ascount = 0;

void findascount(unsigned char* template) {
    for(unsigned i = 0; i < strlen(template); ++i) {
        if (template[i] == 'a') {
            ++ascount;
        }
    }
}


void replace(unsigned char* line, unsigned char *template) {
    size_t templatelentgh = strlen(template);
    size_t linelength = strlen(line);
    if (templatelentgh > linelength) {
        printf("%s\n", line);
        return;
    }
    size_t left = 0;
    for (left = 0; left <= linelength - templatelentgh; ++left) {
        int needreplace = 1;
        for (size_t i = left; i < left + templatelentgh; ++i) {
            if (line[i] != template[i - left]) {
                needreplace = 0;
                break;
            }
        }
        if (needreplace == 1) {
            for (size_t j = 0; j < ascount; ++j) {
                printf("%c", '#');
            }
            left += templatelentgh - 1;
        } else {
            printf("%c", line[left]);
        }
    }
    for (; left < linelength; ++left) {
        printf("%c", line[left]);
    }
    printf("%c", '\n');
}

void scanfile(int file, unsigned char *template) {
    unsigned char *buffer = (unsigned char *) malloc(1 * sizeof(char)); // Сюда будет класть считываемую строчку.
    if (buffer == NULL) {
        perror("Не удалось выделить память");
        exit(1);
    }
    ssize_t r = 0;;
    size_t len = 0;
    size_t bufsize = 2;
    while ((r = read(file, buffer + len, 1)) > 0) {
        if (buffer[len] == '\n') {
            // Считали конец строки => можно начать обрабатывать.
            buffer[len] = '\0';
            replace(buffer, template);
            free(buffer); // Обновляем буфер.
            buffer = (unsigned char *) malloc(2 * sizeof(char));
            if (buffer == NULL) {
                perror("Не удалось выделить память");
                exit(1);
            }
            bufsize = 2;
            len = -1; // Потом прибавим 1
        } else if (len + 1 == bufsize) {
            // Пора удлинять буфер
            unsigned char *temp;
            if (temp = (unsigned char *) realloc(buffer, 2 * bufsize * sizeof(char))) {
                buffer = temp;
                bufsize *= 2;
            } else {
                perror("Не удалось перераспределить память");
                exit(1);
            }
        }
        ++len;
    }
    if (r < 0) {
        perror(NULL);
        exit(1);
    }
    free(buffer);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        perror("Задано меньше двух аргументов");
        exit(1);
    }
    if (argv[1] == "") {
        perror("Не задан файл");
        exit(1);
    }
    if (argv[2] == "") {
        perror("Не задан шаблон");
        exit(1);
    }
    findascount(argv[2]);
    int fd = open(argv[1], O_RDONLY);
    scanfile(fd, argv[2]);
}
