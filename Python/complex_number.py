import math
import unittest
class Complex:
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

    def __str__(self):
        return f"{self.real:.2f} + {self.imag:.2f}i"

    def add(self, other):
        return Complex(self.real + other.real, self.imag + other.imag)

    def subtract(self, other):
        return Complex(self.real - other.real, self.imag - other.imag)

    def multiply(self, other):
        return Complex(self.real * other.real - self.imag * other.imag,
                       self.real * other.imag + self.imag * other.real)

    def divide(self, other):
        denominator = other.real ** 2 + other.imag ** 2
        return Complex((self.real * other.real + self.imag * other.imag) / denominator,
                       (self.imag * other.real - self.real * other.imag) / denominator)

    def modulus(self):
        return math.sqrt(self.real ** 2 + self.imag ** 2)

    def argument(self):
        return math.atan2(self.imag, self.real)

    def conjugate(self):
        return Complex(self.real, -self.imag)

    @classmethod
    def from_modulus_and_argument(cls, modulus, argument):
        return cls(modulus * math.cos(argument), modulus * math.sin(argument))

class TestComplexOperations(unittest.TestCase):
    def test_add(self):
        a = Complex(3, 4)
        b = Complex(1, 2)
        result = a.add(b)
        self.assertEqual(result.real, 4)
        self.assertEqual(result.imag, 6)

    def test_subtract(self):
        a = Complex(3, 4)
        b = Complex(1, 2)
        result = a.subtract(b)
        self.assertEqual(result.real, 2)
        self.assertEqual(result.imag, 2)

    def test_multiply(self):
        a = Complex(3, 4)
        b = Complex(1, 2)
        result = a.multiply(b)
        self.assertEqual(result.real, -5)
        self.assertEqual(result.imag, 10)

    def test_divide(self):
        a = Complex(3, 4)
        b = Complex(1, 2)
        result = a.divide(b)
        self.assertAlmostEqual(result.real, 2.2)
        self.assertAlmostEqual(result.imag, -0.4)


    def test_modulus(self):
        a = Complex(3, 4)
        self.assertEqual(a.modulus(), 5)

    def test_argument(self):
        a = Complex(3, 4)
        result = a.argument()
        self.assertAlmostEqual(result, 0.9272952180016122)

    def test_conjugate(self):
        a = Complex(3, 4)
        result = a.conjugate()
        self.assertEqual(result.real, 3)
        self.assertEqual(result.imag, -4)

    def test_from_modulus_and_argument(self):
        modulus = 5
        argument = 0.9272952180016122
        result = Complex.from_modulus_and_argument(modulus, argument)
        self.assertAlmostEqual(result.real, 3, places=5)
        self.assertAlmostEqual(result.imag, 4, places=5)

if __name__ == '__main__':

    unittest.main()

    a = Complex(3, 4) 
    b = Complex(1, 2) 

    sum_res = a.add(b)
    print(f"Sum: {sum_res}")

    quotient = a.divide(b)
    print(f"Quotient: {quotient}")

    mod = a.modulus()
    arg = a.argument()
    print(f"Modulus: {mod}, Argument: {arg} radians")

    conj = a.conjugate()
    print(f"Conjugate: {conj}")

    from_mod_arg = Complex.from_modulus_and_argument(mod, arg)
    print(f"From Modulus and Argument: {from_mod_arg}")

