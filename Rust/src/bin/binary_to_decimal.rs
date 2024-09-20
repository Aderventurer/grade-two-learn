fn binary_to_decimal(binary_string: &str) -> i32 {
    let mut decimal_number = 0;
    let _length = binary_string.len();

    for (i, c) in binary_string.chars().rev().enumerate() {
        if c == '1' {
            decimal_number += 1 << i;
        }
    }

    decimal_number
}

fn main() {
    let binary_string = "1011";
    let result = binary_to_decimal(binary_string);
    println!("十进制数是: {}", result);
}
