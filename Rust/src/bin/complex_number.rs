use std::f64::consts::PI;

#[derive(Debug, Copy, Clone)]
struct Complex {
    real: f64,
    imag: f64,
}

impl Complex {
    fn add(self, other: Complex) -> Complex {
        Complex {
            real: self.real + other.real,
            imag: self.imag + other.imag,
        }
    }

    fn subtract(self, other: Complex) -> Complex {
        Complex {
            real: self.real - other.real,
            imag: self.imag - other.imag,
        }
    }

    fn multiply(self, other: Complex) -> Complex {
        Complex {
            real: self.real * other.real - self.imag * other.imag,
            imag: self.real * other.imag + self.imag * other.real,
        }
    }

    fn divide(self, other: Complex) -> Complex {
        let denominator = other.real * other.real + other.imag * other.imag;
        Complex {
            real: (self.real * other.real + self.imag * other.imag) / denominator,
            imag: (self.imag * other.real - self.real * other.imag) / denominator,
        }
    }

    fn modulus(self) -> f64 {
        (self.real * self.real + self.imag * self.imag).sqrt()
    }

    fn argument(self) -> f64 {
        self.imag.atan2(self.real)
    }

    fn conjugate(self) -> Complex {
        Complex {
            real: self.real,
            imag: -self.imag,
        }
    }

    fn from_modulus_and_argument(modulus: f64, argument: f64) -> Complex {
        Complex {
            real: modulus * argument.cos(),
            imag: modulus * argument.sin(),
        }
    }
}

fn main() {
    let a = Complex {
        real: 3.0,
        imag: 4.0,
    };
    let b = Complex {
        real: 1.0,
        imag: 2.0,
    };

    let sum = a.add(b);
    println!("Sum: {:.2} + {:.2}i", sum.real, sum.imag);

    let difference = a.subtract(b);
    println!(
        "Difference: {:.2} + {:.2}i",
        difference.real, difference.imag
    );

    let product = a.multiply(b);
    println!("Product: {:.2} + {:.2}i", product.real, product.imag);

    let quotient = a.divide(b);
    println!("Quotient: {:.2} + {:.2}i", quotient.real, quotient.imag);

    let modulus = a.modulus();
    let argument = a.argument();
    println!("Modulus: {:.2}, Argument: {:.2} radians", modulus, argument);

    let conj = a.conjugate();
    println!("Conjugate: {:.2} + {:.2}i", conj.real, conj.imag);

    let from_mod_arg = Complex::from_modulus_and_argument(modulus, argument);
    println!(
        "From Modulus and Argument: {:.2} + {:.2}i",
        from_mod_arg.real, from_mod_arg.imag
    );
}
