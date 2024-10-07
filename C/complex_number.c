#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define info(format, ...) printf("["__FILE__                      \
                                 "][Line: %d][%s]: " format "\n", \
                                 __LINE__, __func__, ##__VA_ARGS__)
typedef struct
{
    double real;
    double imag;
} Complex;

Complex add(Complex a, Complex b)
{
    Complex result = {a.real + b.real, a.imag + b.imag};
    return result;
}

Complex subtract(Complex a, Complex b)
{
    Complex result = {a.real - b.real, a.imag - b.imag};
    return result;
}

Complex multiply(Complex a, Complex b)
{
    Complex result = {a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
    return result;
}

Complex divide(Complex a, Complex b)
{
    double denominator = (pow(b.imag, 2) + pow(b.real, 2));
    Complex result =
        {
            (a.real * b.real + a.imag * b.imag) / denominator,
            (a.imag * b.real - a.real * b.imag) / denominator};
    return result;
}
double modulus(Complex a)
{
    double result = sqrt(a.real * a.real + a.imag * a.imag);
    return result;
}

double argument(Complex a)
{
    return atan2(a.real, a.imag);
}

Complex conjugate(Complex a)
{
    Complex result = {a.real, -a.imag};
    return result;
}

Complex from_modulus_and_argument(double mod, double arg)
{
    Complex result = {mod * cos(arg), mod * sin(arg)};
    return result;
}

int double_apporx_eq(double a, double b, double eps)
{
    double diff = fabs(a - b);
    if (diff < eps)
        return 1;
    else
        return 0;
}

void test_complex_add()
{
    Complex a = {3, 4};
    Complex b = {1, 2};

    Complex sum = add(a, b);

    if (double_apporx_eq(sum.real, 4.0, 1e-12) == 0)
    {
        exit(-1);
    }

    if (double_apporx_eq(sum.imag, 6.0, 1e-12) == 0)
    {
        exit(-1);
    }
}

void test_complex_subtract()
{
    Complex a = {3, 4};
    Complex b = {1, 2};

    Complex diff = subtract(a, b);

    if (double_apporx_eq(diff.real, 2.0, 1e-12) == 0)
    {
        exit(-1);
    }

    if (double_apporx_eq(diff.imag, 2.0, 1e-12) == 0)
    {
        exit(-1);
    }
}

void test_complex_multiply()
{
    Complex a = {3, 4};
    Complex b = {1, 2};

    Complex multiplication = multiply(a, b);

    if (double_apporx_eq(multiplication.real, -5.0, 1e-12) == 0)
    {
        exit(-1);
    }

    if (double_apporx_eq(multiplication.imag, 10.0, 1e-12) == 0)
    {
        exit(-1);
    }
}

void test_complex_divide()
{
    Complex a = {3, 4};
    Complex b = {1, 2};

    Complex quotient = divide(a, b);

    if (double_apporx_eq(quotient.real, 2.2, 1e-12) == 0)
    {
        exit(-1);
    }

    if (double_apporx_eq(quotient.imag, -0.4, 1e-12) == 0)
    {
        exit(-1);
    }
}

void test_complex_modulus()
{
    Complex a = {3, 4};
    Complex b = {1, 2};

    double Modulus = modulus(a);
    if (double_apporx_eq(Modulus, 5.0, 1e-12) == 0)
    {
        exit(-1);
    }
}

void test_complex_argument()
{
    Complex a = {3, 4};

    double Atan2 = argument(a);
    if (double_apporx_eq(Atan2, 0.643, 1e-3) == 0)
    {
        exit(-1);
    }
}

void test_complex_conjugate()
{
    Complex a = {3, 4};

    Complex a1 = conjugate(a);

    if (double_apporx_eq(a1.real, 3.0, 1e-12) == 0)
    {
        exit(-1);
    }
    if (double_apporx_eq(a1.imag, -4.0, 1e-12) == 0)
    {
        exit(-1);
    }
}

void test_from_modulus_and_argument()
{
    double mod = 5;
    double arg = atan2(4.0, 3.0);

    Complex a = from_modulus_and_argument(mod, arg);
    if (double_apporx_eq(a.real, 3.0, 1e-12) == 0)
    {
        exit(-1);
    }
    if (double_apporx_eq(a.imag, 4.0, 1e-12) == 0)
    {
        exit(-1);
    }
}

int main()
{
    test_complex_add();
    test_complex_subtract();
    test_complex_multiply();
    test_complex_divide();
    test_complex_modulus();
    test_complex_argument();
    test_complex_conjugate();
    test_from_modulus_and_argument();

    return 0;
}
