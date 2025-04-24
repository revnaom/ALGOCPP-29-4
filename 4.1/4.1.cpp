#include <iostream>

void print_pyramid(const int* arr, int size) {
    std::cout << "Пирамида:" << std::endl;

    for (int i = 0; i < size; ++i) {
        int level = 0;
        int temp = i + 1;
        while (temp >>= 1) ++level;

        if (i == 0) {
            std::cout << level << " root " << arr[i] << std::endl;
        }
        else {
            int parent_index = (i - 1) / 2;
            std::string child_type = (i % 2 == 1) ? "left" : "right";
            std::cout << level << " " << child_type << "(" << arr[parent_index] << ") " << arr[i] << std::endl;
        }
    }
}

void print_array(const int* arr, int size) {
    std::cout << "Исходный массив:";
    for (int i = 0; i < size; ++i) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
}

int main() {
    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    print_array(arr1, size1);
    print_pyramid(arr1, size1);
    std::cout << std::endl;

    print_array(arr2, size2);
    print_pyramid(arr2, size2);
    std::cout << std::endl;

    print_array(arr3, size3);
    print_pyramid(arr3, size3);

    return 0;
}