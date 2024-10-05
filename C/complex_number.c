#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
    double denominator = (pow(a.real, 2) + pow(b.real, 2));
    Complex result =
        {
            (a.real * b.real + a.imag * b.imag) / denominator,
            (a.imag * b.real - a.real * b.imag) / denominator};
    return result;
}
double modulus(Complex a)
{
    return sqrt(a.real * a.real + a.imag * a.imag);
}

double argument(Complex a)
{
    return atan2(a.imag, a.real);
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

int main()
{
    test_complex_add();

    Complex a = {3, 4};
    Complex b = {1, 2};

    Complex sum = add(a, b);
    printf("Sum: %.2f + %.2fi\n", sum.real, sum.imag);

    Complex quotient = divide(a, b);
    printf("Quotient: %.2f + %.2fi\n", quotient.real, quotient.imag);

    double mod = modulus(a);
    double arg = argument(a);
    printf("Modulus: %.2f, Argument: %.2f radians\n", mod, arg);

    Complex conj = conjugate(a);
    printf("Conjugate: %.2f + %.2fi\n", conj.real, conj.imag);

    Complex from_mod_arg = from_modulus_and_argument(mod, arg);
    printf("From Modulus and Argument: %.2f + %.2fi\n", from_mod_arg.real, from_mod_arg.imag);

    return 0;
}
