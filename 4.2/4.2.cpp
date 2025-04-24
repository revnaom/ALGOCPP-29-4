#include <iostream>
#include <string>


void print_pyramid(const int* arr, int size) {
    std::cout << "Пирамида:" << std::endl;
    for (int i = 0; i < size; ++i) {
        int level = 0;
        int temp = i + 1;
        while (temp >>= 1) ++level;
        
        if (i == 0) {
            std::cout << level << " root " << arr[i] << std::endl;
        } else {
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

bool get_parent(int current, int& parent, int size) {
    if (current == 0) return false;
    parent = (current - 1) / 2;
    return true;
}

bool get_left_child(int current, int& child, int size) {
    child = 2 * current + 1;
    return child < size;
}

bool get_right_child(int current, int& child, int size) {
    child = 2 * current + 2;
    return child < size;
}

void print_current_position(const int* arr, int index) {
    if (index == 0) {
        std::cout << "Вы находитесь здесь: 0 root " << arr[index] << std::endl;
        return;
    }
    
    int parent_index = (index - 1) / 2;
    std::string child_type = (index % 2 == 1) ? "left" : "right";
    int level = 0;
    int temp = index + 1;
    while (temp >>= 1) ++level;
    
    std::cout << "Вы находитесь здесь: " << level << " " << child_type << "(" << arr[parent_index] << ") " << arr[index] << std::endl;
}

int main() {
    int arr1[] = {1, 3, 6, 5, 9, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int arr3[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    
    const int* current_arr = arr1;
    int current_size = size1;
    
    print_array(current_arr, current_size);
    print_pyramid(current_arr, current_size);
    
    int current_index = 0;
    print_current_position(current_arr, current_index);
    
    std::string command;
    do {
        std::cout << "Введите команду: ";
        std::cin >> command;
        
        if (command == "up") {
            int parent;
            if (get_parent(current_index, parent, current_size)) {
                current_index = parent;
                std::cout << "Ок" << std::endl;
            } else {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
            }
        }
        else if (command == "left") {
            int child;
            if (get_left_child(current_index, child, current_size)) {
                current_index = child;
                std::cout << "Ок" << std::endl;
            } else {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
            }
        }
        else if (command == "right") {
            int child;
            if (get_right_child(current_index, child, current_size)) {
                current_index = child;
                std::cout << "Ок" << std::endl;
            } else {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
            }
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "Неизвестная команда" << std::endl;
        }
        
        print_current_position(current_arr, current_index);
        
    } while (true);
    
    return 0;
}