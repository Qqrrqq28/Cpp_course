#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <cstdint>
#include <iostream>
#include <stdexcept>

template<typename T>
class DynamicArray {
private:
    T* data = nullptr;
    std::int64_t size = -1;         // -1 = пустой, иначе индекс последнего элемента
    std::int64_t capacity = 0;
    bool fixed_size = false;

    void resizeIfNeeded();          // Вспомогательный метод — в .cc

public:
    DynamicArray();
    explicit DynamicArray(std::int64_t cap);
    DynamicArray(std::int64_t cap, bool fixed);
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    ~DynamicArray();

    void push_back(const T& x);
    void push_front(const T& x);
    void insert(std::int64_t idx, const T& x);
    void remove(std::int64_t idx);
    void erase_after(std::int64_t idx);

    T front() const;
    T back() const;

    void clear();
    void printData() const;

    T& operator[](std::int64_t idx);
    const T& operator[](std::int64_t idx) const;

    bool isEmpty() const { return size == -1; }
    std::int64_t getActualSize() const { return size == -1 ? 0 : size + 1; }
    std::int64_t getCapacity() const { return capacity; }
    void setFixedSize(bool f) { fixed_size = f; }
    std::int64_t getSize() const { return size; }
    void setSize(std::int64_t s) { size = s; }  // Для pop в стеке
};


template<>
class DynamicArray<float> {
private:
    float* data = nullptr;
    std::int64_t size = -1;
    std::int64_t capacity = 0;
    bool fixed_size = false;

    void resizeIfNeeded();

public:
    DynamicArray();
    explicit DynamicArray(std::int64_t cap);
    DynamicArray(std::int64_t cap, bool fixed);
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    ~DynamicArray();

    void push_back(float x);
    void push_front(float x);
    void insert(std::int64_t idx, float x);
    void remove(std::int64_t idx);
    void erase_after(std::int64_t idx);

    float front() const;
    float back() const;

    void clear();
    void reinitialize();
    void printData() const;

    float operator[](std::int64_t idx) const;
    float operator()() const;

    float add(std::int64_t i, std::int64_t j) const;
    float max() const;
    float min() const;

    void increase_capacity(std::int64_t newCap);
    void decrease_capacity(std::int64_t newCap);

    bool isEmpty() const { return size == -1; }
    std::int64_t getActualSize() const { return size == -1 ? 0 : size + 1; }
    void setFixedSize(bool f) { fixed_size = f; }
    std::int64_t getSize() const { return size; }
    void setSize(std::int64_t s) { size = s; }
};

#endif
