#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100

// 比较函数，用于 qsort
int compare(const void *a, const void *b)
{
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    // 检查 n 的有效性
    if (n < 1 || n > MAX_NUMBERS)
    {
        fprintf(stderr, "Error: n must be a positive integer between 1 and 100.\n");
        return 1;
    }

    // 生成 n 个随机数
    double numbers[MAX_NUMBERS];
    srand(time(NULL)); // 设置随机种子

    for (int i = 0; i < n; i++)
    {
        numbers[i] = (double)rand() / RAND_MAX; // 生成 0 到 1 之间的随机数
    }

    // 打印随机数
    printf("Generated random numbers:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f\n", numbers[i]);
    }

    // 排序
    qsort(numbers, n, sizeof(double), compare);

    // 打印排序后的随机数
    printf("Sorted random numbers:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f\n", numbers[i]);
    }

    return 0;
}
