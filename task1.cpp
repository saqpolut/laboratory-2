#include <iostream>
#include <string>

int main() {
    std::string s = "aaaaaaaaabb";
    std::string t = "ab";
    
    std::string result = "Не найдено";
    
    // Перебираем все возможные подстроки
    for (int start = 0; start < s.length(); ++start) {
        for (int end = start; end < s.length(); ++end) {
            
            // Создание текущей подстроки
            std::string current = "";
            for (int i = start; i <= end; ++i) {
                current += s[i];
            }
            
            // Проверяем, есть ли все буквы из t
            std::string tempT = t;
            
            for (int i = 0; i < current.length(); ++i) {
                for (int j = 0; j < tempT.length(); ++j) {
                    if (current[i] == tempT[j]) {
                        tempT.erase(j, 1);
                        break;
                    }
                }
            }
            
            // Если нашли все буквы
            if (tempT.length() == 0) {
                // Если это первая найденная подстрока или она короче предыдущей
                if (result == "Не найдено" || current.length() < result.length()) {
                    result = current;
                }
            }
        }
    }
    std::cout << s << " " << t << std::endl;
    std::cout  << result << std::endl;

    return 0;
}
