#include <iostream>
#include <algorithm>
#include <Windows.h>
const int maxSize = 100;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int m;

    
    std::cout << "Введіть розмір масиву (m): ";
    std::cin >> m;

    if (m <= 0 || m > maxSize) {
        std::cerr << "Некоректний розмір масиву. m повинно бути в межах від 1 до " << maxSize << std::endl;
        return 1;
    }

    int A[maxSize];

   
    std::cout << "Введіть елементи масиву A:" << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cout << "A[" << i << "]: ";
        std::cin >> A[i];
    }

   
    std::sort(A, A + m);  
    int uniqueCount = std::unique(A, A + m) - A;

    std::cout << "Кількість різних чисел в масиві: " << uniqueCount << std::endl;

    std::partition(A, A + m, [](int x) { return x > 0; });

    
    std::cout << "Масив після перетворення:" << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cout << "A[" << i << "]: " << A[i] << std::endl;
    }

    return 0;
}
