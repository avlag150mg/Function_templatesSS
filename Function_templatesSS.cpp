#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h> 
using namespace std; 

std::vector<int> sort_between_extreme_negatives(const std::vector<int>& arr) {
    int left_index = -1, right_index = -1;
    
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] < 0) {
            if (left_index == -1) left_index = i;
            right_index = i;
        }
    }
    
    if (left_index == -1 || right_index == -1 || left_index == right_index) {
        return arr;
    }
    
    std::vector<int> middle_part(arr.begin() + left_index + 1, arr.begin() + right_index);
    
    std::sort(middle_part.begin(), middle_part.end());
    
    std::vector<int> result = arr;
    std::copy(middle_part.begin(), middle_part.end(), result.begin() + left_index + 1);
    
    return result;
}

int main() { 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    std::vector<int> arr = {-10, 5, 3, -7, 8, -2, 1, 6};
    std::vector<int> sorted_arr = sort_between_extreme_negatives(arr);
    
    std::cout << "Оригінальний масив: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\nРезультат: ";
    for (int num : sorted_arr) std::cout << num << " ";
    
    return 0; 
}