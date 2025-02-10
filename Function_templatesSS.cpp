#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <Windows.h> 
using namespace std; 

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_between_dates(int y1, int m1, int d1, int y2, int m2, int d2) {
    std::tm date1 = {};
    date1.tm_year = y1 - 1900;
    date1.tm_mon = m1 - 1;
    date1.tm_mday = d1;

    std::tm date2 = {};
    date2.tm_year = y2 - 1900;
    date2.tm_mon = m2 - 1;
    date2.tm_mday = d2;

    std::time_t time1 = std::mktime(&date1);
    std::time_t time2 = std::mktime(&date2);

    if (time1 == -1 || time2 == -1) {
        return -1;
    }
    
    return std::difftime(time2, time1) / (60 * 60 * 24);
}

int main() { 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    int y1 = 2023, m1 = 2, d1 = 10;
    int y2 = 2024, m2 = 3, d2 = 5;
    
    std::cout << "Різниця в днях: " << days_between_dates(y1, m1, d1, y2, m2, d2) << " днів" << std::endl;
    
    int year = 2024;
    std::cout << "Чи є " << year << " рік високосним? " << (is_leap_year(year) ? "Так" : "Ні") << std::endl;
    
    return 0; 
}