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

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_add() {
        let a = Complex {
            real: 3.0,
            imag: 4.0,
        };
        let b = Complex {
            real: 1.0,
            imag: 2.0,
        };
        let result = a.add(b);
        assert_eq!(result.real, 4.0);
        assert_eq!(result.imag, 6.0);
    }

    #[test]
    fn test_subtract() {
        let a = Complex {
            real: 3.0,
            imag: 4.0,
        };
        let b = Complex {
            real: 1.0,
            imag: 2.0,
        };
        let diff = a.subtract(b);
        assert_eq!(diff.real, 2.0);
        assert_eq!(diff.imag, 2.0);
    }

    #[test]
    fn test_multiply() {
        let a = Complex {
            real: 3.0,
            imag: 4.0,
        };
        let b = Complex {
            real: 1.0,
            imag: 2.0,
        };
        let product = a.multiply(b);
        assert_eq!(product.real, -5.0);
        assert_eq!(product.imag, 10.0);
    }

    #[test]
    fn test_divide() {
        let a = Complex {
            real: 3.0,
            imag: 4.0,
        };
        let b = Complex {
            real: 1.0,
            imag: 2.0,
        };
        let quotient = a.divide(b);
        assert_eq!(quotient.real, 2.2);
        assert_eq!(quotient.imag, -0.4);
    }

    #[test]
    fn test_modulus() {
        let a = Complex {
            real: 3.0,
            imag: 4.0,
        };
        let result = a.modulus();
        assert_eq!(result, 5.0);
    }

    #[test]
    fn test_argument() {
        let a = Complex {
            real: 3.0,
            imag: 4.0,
        };
        let arg_a = a.argument();
        assert_eq!(arg_a, 0.9272952180016122);
    }

    #[test]
    fn test_conjugate() {
        let a = Complex {
            real: 3.0,
            imag: 4.0,
        };
        let conj = a.conjugate();
        assert_eq!(conj.real, 3.0);
        assert_eq!(conj.imag, -4.0);
    }

    #[test]
    fn test_from_modulus_and_argument() {
        let mod_a = 5.0;
        let arg_a = 0.9272952180016122;
        let complex = Complex::from_modulus_and_argument(mod_a, arg_a);
        assert!((complex.real - 3.0).abs() < 1e-10);
        assert!((complex.imag - 4.0).abs() < 1e-10);
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
