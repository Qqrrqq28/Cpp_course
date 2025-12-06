#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"



template<typename T>
class Queue {
private:
    Stack<T> input;     // Для добавления элементов
    Stack<T> output;    // Для извлечения (переворачиваем input)

public:
    Queue(std::int64_t maxSize) : input(maxSize), output(maxSize) {}

    void enqueue(const T& value) {
        input.push(value);
    }

    T dequeue() {
        if (output.isEmpty()) {
            // Перекладываем из input в output (меняем порядок)
            while (!input.isEmpty()) {
                output.push(input.pop());
            }
        }
        if (output.isEmpty())
            throw std::invalid_argument("Queue is empty");
        return output.pop();
    }

    bool isEmpty() const {
        return input.isEmpty() && output.isEmpty();
    }

    std::int64_t size() const {
        return input.getActualSize() + output.getActualSize();
    }
};

#endif
