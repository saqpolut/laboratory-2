#include <iostream>
#include <string>

int main() {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::string result = "Не найдено";
    
    for (int start = 0; start < s.length(); ++start) {
        for (int end = start; end < s.length(); ++end) {
            std::string current = "";
            for (int i = start; i <= end; ++i) {
                current += s[i];
            }
            std::string tempT = t;
            for (int i = 0; i < current.length(); ++i) {
                for (int j = 0; j < tempT.length(); ++j) {
                    if (current[i] == tempT[j]) {
                        tempT.erase(j, 1);
                        break;
                    }
                }
            }
            if (tempT.length() == 0) {
                if (result == "Не найдено" || current.length() < result.length()) {
                    result = current;
                }
            }
        }
    }
    std::cout << s << " " << t << std::endl;std::cout << result << std::endl;
    return 0;
}