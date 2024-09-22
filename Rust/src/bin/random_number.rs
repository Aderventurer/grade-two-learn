use rand::Rng;
use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() != 2 {
        eprintln!("Usage: {} <n>", args[0]);
        std::process::exit(1);
    }

    let n: usize = match args[1].parse() {
        Ok(num) if num >= 1 && num <= 100 => num,
        _ => {
            eprintln!("Please provide a valid number between 1 and 100.");
            std::process::exit(1);
        }
    };

    let mut rng = rand::thread_rng();
    let mut random_numbers: Vec<f64> = (0..n).map(|_| rng.gen_range(0.0..=1.0)).collect();

    println!("Random numbers: {:?}", random_numbers);

    random_numbers.sort_by(|a, b| a.partial_cmp(b).unwrap());

    println!("Sorted numbers: {:?}", random_numbers);
}
