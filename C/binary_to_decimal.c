#include <stdio.h>
#include <string.h>

int binary_to_decimal(const char *binary_string)
{
    int decimal_value = 0;
    int length = strlen(binary_string);
    for (int i = 0; i < length; i++)
    {
        if (binary_string[length - 1 - i] == '1')
        {
            decimal_value += (1 << i);
        }
    }
    return decimal_value;
}
int main()
{
    const char *binary_string = "1101";
    int result = binary_to_decimal(binary_string);
    printf("十进制数是: %d\n", result);
    return 0;
}