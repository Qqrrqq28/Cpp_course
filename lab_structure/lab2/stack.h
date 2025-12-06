#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>



template<typename T>
class Stack {
private:
    DynamicArray<T> arr;                    
    std::int64_t max_size;                  // Максимальный размер стека

public:
    // Конструктор — задаём максимальный размер
    Stack(std::int64_t size) : max_size(size), arr(size, true) {}

    // Добавление элемента
    void push(const T& value) {
        if (arr.getActualSize() >= max_size)
            throw std::overflow_error("Stack overflow");
        arr.push_back(value);
    }

    // Просмотр вершины (без удаления)
    T top() const {
        if (arr.isEmpty())
            throw std::invalid_argument("Stack is empty");
        return arr.back();
    }

    // Извлечение вершины
    T pop() {
        if (arr.isEmpty())
            throw std::invalid_argument("Stack is empty");
        T value = arr.back();
        arr.setSize(arr.getActualSize() - 2);  // Уменьшаем количество элементов
        return value;
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return arr.isEmpty();
    }
};

#endif
