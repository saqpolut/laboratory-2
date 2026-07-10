use std::io;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Ошибка ввода");
    let nums: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    let n = nums[0] as usize;
    let count = nums[1..=n]
        .windows(2)
        .filter(|pair| pair[0] == pair[1])
        .count();
    println!("{}", count);
}