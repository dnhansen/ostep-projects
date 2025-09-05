#include <stdio.h>

int main(int argc, char *argv[]) {
    char buffer[BUFSIZ];

    for (int n = 1; n < argc; n++) {
        FILE *fp = fopen(argv[n], "r");
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            return 1;
        }

        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }

        fclose(fp);
    }

    return 0;
}