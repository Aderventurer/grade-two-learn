#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100

int compare(const void *a, const void *b)
{
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

void generate_random_numbers(int n)
{
    FILE *random_file = fopen("random.txt", "w");
    if (!random_file)
    {
        perror("无法打开文件 random.txt");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        double num = (double)rand() / RAND_MAX;

        fprintf(random_file, "%f\n", num);
    }
    fclose(random_file);
}

double *read_numbers_from_file(int *size)
{
    FILE *input_file = fopen("random.txt", "r");
    if (!input_file)
    {
        perror("无法打开文件 random.txt");
        return NULL;
    }

    double *numbers = malloc(MAX_NUMBERS * sizeof(double));
    *size = 0;

    while (fscanf(input_file, "%lf", &numbers[*size]) == 1)
    {
        (*size)++;
        if (*size >= MAX_NUMBERS)
            break;
    }

    fclose(input_file);
    return numbers;
}

void write_numbers_to_file(const char *filename, double *numbers, int size)
{
    FILE *output_file = fopen(filename, "w");
    if (!output_file)
    {
        perror("无法打开文件 sorted.txt");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(output_file, "%f\n", numbers[i]);
    }

    fclose(output_file);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    if (n < 1 || n > MAX_NUMBERS)
    {
        fprintf(stderr, "Error: n must be a positive integer between 1 and 100.\n");
        return 1;
    }

    generate_random_numbers(n);

    int size;
    double *numbers = read_numbers_from_file(&size);
    if (numbers == NULL)
    {
        return 1;
    }

    qsort(numbers, size, sizeof(double), compare);

    write_numbers_to_file("sorted.txt", numbers, size);

    free(numbers);

    return 0;
}
