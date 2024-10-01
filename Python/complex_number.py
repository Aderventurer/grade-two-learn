import math

import math

class Complex:
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

    def __str__(self):
        return f"{self.real} + {self.imag}i"

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

