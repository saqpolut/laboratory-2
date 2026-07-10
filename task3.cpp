#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    int count = 0;
    int pred, curr;
    
    std::cin >> pred; // считываем первое число
    
    for (int i = 1; i < n; i++) {
        std::cin >> curr;
        if (curr == pred) {
            count++;
        }
        pred = curr;
    }
    
    std::cout << count << std::endl;
    
    return 0;
}