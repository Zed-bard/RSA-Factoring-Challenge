#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/**
 * read_textfile - read and send to stdout a number of chars.
 *
 * @filename: name of file
 * @letters: number of letters
 * Return: Number of printed chars.
 */
int main(int ac, char **av)
{
    int i, j, flag, fd, h;
    int leido = 0;
    long int number, number2, k;
    char *buf, *buf2;
    int letters = 100;

    leido = leido;
    ac = ac;

    if (ac != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", av[0]);
        return EXIT_FAILURE;
    }

    fd = open(av[1], O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    buf = malloc(1000 * sizeof(char));
    buf2 = malloc(120 * sizeof(char));

    if (buf == NULL || buf2 == NULL)
    {
        perror("Error allocating memory");
        close(fd);
        return EXIT_FAILURE;
    }

    leido = read(fd, buf, letters);
    i = 0;
    while (buf[i] != 0)
    {
        j = 0;
        for (h = 0; h <= 100; h++)
            buf2[h] = 0;

        while (buf[i] != 10)
        {
            buf2[j] = buf[i];
            i++;
            j++;
        }
        number = atol(buf2);
        flag = 0;

        for (k = 2; k <= sqrt(number); k++)
        {
            if (number % k == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            /* The number is prime */
            printf("%li is a prime number\n", number);
        }
        else
        {
            /* The number is not prime, find the prime factors */
            number2 = number / k;
            printf("%li=%li*%li\n", number, k, number2);
        }
        i++;
    }

    free(buf);
    free(buf2);
    close(fd);
    return (0);
}
