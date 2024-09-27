use rand::Rng;
use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write, BufReader};

fn main() -> io::Result<()> {
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
    let random_numbers: Vec<f64> = (0..n).map(|_| rng.gen_range(0.0..=1.0)).collect();

    let mut random_file = File::create("random.txt")?;
    for num in &random_numbers {
        writeln!(random_file, "{}", num)?;
    }
    println!("Random numbers saved to random.txt");

    let file = File::open("random.txt")?;
    let reader = BufReader::new(file);
    let mut loaded_numbers: Vec<f64> = Vec::new();
    for line in reader.lines() {
        let num: f64 = line?.parse().unwrap();
        loaded_numbers.push(num);
    }

    loaded_numbers.sort_by(|a, b| a.partial_cmp(b).unwrap());

    let mut sorted_file = File::create("sorted.txt")?;
    for num in &loaded_numbers {
        writeln!(sorted_file, "{}", num)?;
    }
    println!("Sorted numbers saved to sorted.txt");

    Ok(())
}
