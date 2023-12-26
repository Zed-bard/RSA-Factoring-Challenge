#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

void findPrimeFactors(int num) {
    printf("%d=", num);
    
    for (int i = 2; i <= num; i++) {
        if (isPrime(i) && num % i == 0) {
            printf("%d", i);
            num /= i;
            
            if (num != 1) {
                printf("*");
            }
            
            i--;
        }
    }
    
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./rsa <input_file>\n");
        return 1;
    }
    
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    
    int num;
    while (fscanf(inputFile, "%d", &num) == 1) {
        findPrimeFactors(num);
    }
    
    fclose(inputFile);
    return 0;
}
