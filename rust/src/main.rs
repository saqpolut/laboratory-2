fn main() {
    let s = "aaaaaaaabb";
    let t = "ab";
    let mut result = None;
    for start in 0..s.len(){
        for end in start..s.len(){
            let current = &s[start..=end];
            let mut temp_t = t.to_string();
            for ch in current.chars(){
                if let Some(pos) = temp_t.find(ch){
                    temp_t.remove(pos);
                }
            }
            if temp_t.is_empty(){
                match result {
                    None => result = Some(current),
                    Some(prev) if current.len() < prev.len() => result =
                    Some(current),
                    _ => {}
                }
            }
        }
    }
    println!("{} {}", s, t);
    match result {
        Some(res) => println!("{}", res),
        None => println!("Не найдено"),
    }
}