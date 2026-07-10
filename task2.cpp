#include <iostream>     
#include <vector>      
#include <tuple> 
#include <algorithm>    

int main() {
    //Ввод данных
    int N;
    std::cin >> N;  // Читаем количество встреч
    
    // Вектор пар: (время_окончания, время_начала)
    // Храним окончание первым, чтобы сортировка по умолчанию работала по окончанию
    std::vector<std::tuple<int,int, int>> meet;
    
    // Заполняем векторы
    for (int i = 0; i < N; ++i) {
        int start, end;
        std::cin >> start >> end;           // Читаем начало и конец

        if (start >= end){
            continue;
        }

        meet.push_back({end, start, i + 1});
    }
     // Если нет корректных заявок
    if (meet.empty()) {
        std::cout << "0" << std::endl;
        return 0;
    }

    // Сортируем встречи по времени окончания (по первому элементу tuple)
    std::sort(meet.begin(), meet.end());
    
    std::vector<int> result;    // Вектор для хранения номеров выбранных встреч
    int lastEnd = 0;            // Время окончания последней выбранной встречи
    
    // Проходим по всем встречам в порядке увеличения времени окончания
    for (const auto& m : meet) {
        int end = std::get<0>(m);
        int start = std::get<1>(m);
        int index = std::get<2>(m);
       
        if (start >= lastEnd) {  // Если не пересекается
            result.push_back(index);      // Добавляем номер встречи
            lastEnd = end;       // Обновляем время окончания
        }
    }
    
    // Сортируем номера выбранных встреч по возрастанию
    std::sort(result.begin(), result.end());
    
    //вывод
    std::cout << result.size() << std::endl;    // Выводим количество встреч
    
    // Выводим номера встреч через пробел 
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) std::cout << " ";
        std::cout << result[i];
    }
    std::cout << std::endl;  // Переход на новую строку
    
    return 0;
}