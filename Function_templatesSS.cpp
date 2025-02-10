#include <iostream>
#include <Windows.h> 
using namespace std;

void insertionSortDescending(int arr[], int start, int end) {
    for (int i = start + 1; i < end; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void insertionSortAscending(int arr[], int start, int end) {
    for (int i = start + 1; i < end; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void sortHalfArray(int arr[], int size) {
    int mid = size / 2;
    insertionSortDescending(arr, 0, mid);
    insertionSortAscending(arr, mid, size);
}

int main() { 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    int arr[10] = {5, 2, 9, 1, 5, 6, 10, 3, 7, 8};
    int size = 10;
    
    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
    
    sortHalfArray(arr, size);
    std::cout << "Half sorted array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
    
    return 0; 
}