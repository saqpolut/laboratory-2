#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::tuple<int,int, int>> meet;
    for (int i = 0; i < N; ++i) {
        int start, end;
        std::cin >> start >> end;
        if (start >= end){
            continue;
        }
        meet.push_back({end, start, i + 1});
    }
    if (meet.empty()) {
        std::cout << "0" << std::endl;
        return 0;
    }
    std::sort(meet.begin(), meet.end());
    std::vector<int> result;
    int lastEnd = 0;
    for (const auto& m : meet) {
        int end = std::get<0>(m);
        int start = std::get<1>(m);
        int index = std::get<2>(m);
        if (start >= lastEnd) {
            result.push_back(index);
            lastEnd = end;
        }
    }
    std::sort(result.begin(), result.end());
    std::cout << result.size() << std::endl;
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) std::cout << " ";
        std::cout << result[i];
    }
    std::cout << std::endl;
    return 0;
}