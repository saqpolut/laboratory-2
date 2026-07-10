use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();    let n: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    let mut meet: Vec<(i32, i32, i32)> = (0..n)
    .filter_map(|i| {
        let line = lines.next().unwrap().unwrap();
        let parts: Vec<i32> = line.split_whitespace().map(|x|x.parse().unwrap()).collect();
        let (start, end) = (parts[0], parts[1]);
        if start < end {
            Some((end, start, (i + 1) as i32))
        } else {
            None
        }
    })
    .collect();
    if meet.is_empty() {
        println!("0");
        return;
    }
    meet.sort();
    let mut result = Vec::new();
    let mut last_end = 0;
    for &(end, start, index) in &meet {
        if start >= last_end {
            result.push(index);
            last_end = end;
        }
    }
    result.sort();
    println!("{}", result.len());
    for (i, &idx) in result.iter().enumerate() {
        if i > 0 { print!(" "); 
    }
    print!("{}", idx);}
    println!();
}