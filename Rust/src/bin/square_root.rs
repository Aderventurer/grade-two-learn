use std::io;

fn main() {
    println!("请输入一个整数：");
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
    let number: i32 = input.trim().parse().expect("请输入整数");
    let number_f64 = number as f64;
    let sqrt_value = number_f64.sqrt();
    println!("平方根：{:.3}", sqrt_value);
}
