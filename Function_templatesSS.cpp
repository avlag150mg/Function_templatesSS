#include <iostream>
#include <algorithm>
#include <Windows.h> 
using namespace std; 

void sortArray(int arr[], int size, bool descending = false) {
    if (descending) {
        std::sort(arr, arr + size, std::greater<int>());
    } else {
        std::sort(arr, arr + size);
    }
}

int main() { 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    int arr[10] = {5, 2, 9, 1, 5, 6, 10, 3, 7, 8};
    int size = 10;
    
    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
    
    sortArray(arr, size);
    std::cout << "Sorted ascending: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
    
    sortArray(arr, size, true);
    std::cout << "Sorted descending: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
    
    return 0; 
}