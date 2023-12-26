#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc != 2) {
        printf("Usage: factors <file>\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((read = getline(&line, &len, file)) != -1) {
        long int number = atol(line);
        printf("%li=", number);

        int factor = 2;
        while (factor <= sqrt(number)) {
            if (number % factor == 0) {
                printf("%i*", factor);
                number = number / factor;
            } else {
                factor++;
            }
        }
        
        printf("%li\n", number);
    }

    fclose(file);
    if (line) {
        free(line);
    }

    return 0;
}
