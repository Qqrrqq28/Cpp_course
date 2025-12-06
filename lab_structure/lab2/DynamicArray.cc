#include "DynamicArray.h"


template<typename T>
void DynamicArray<T>::resizeIfNeeded() {
    if (size + 1 < capacity) return;
    if (fixed_size) 
        throw std::overflow_error("DynamicArray overflow - fixed size");
    
    std::int64_t newCap = capacity == 0 ? 8 : capacity * 2;
    T* temp = new T[newCap];
    std::int64_t count = size == -1 ? 0 : size + 1;
    for (std::int64_t i = 0; i < count; ++i)
        temp[i] = data[i];
    
    delete[] data;
    data = temp;
    capacity = newCap;
}


template<typename T>
DynamicArray<T>::DynamicArray() {
    resizeIfNeeded();
}

template<typename T>
DynamicArray<T>::DynamicArray(std::int64_t cap) {
    if (cap < 1) throw std::invalid_argument("Capacity must be > 0");
    capacity = cap;
    data = new T[capacity];
}

template<typename T>
DynamicArray<T>::DynamicArray(std::int64_t cap, bool fixed) : fixed_size(fixed) {
    if (cap < 1) throw std::invalid_argument("Capacity must be > 0");
    capacity = cap;
    data = new T[capacity];
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) {
    capacity = other.capacity;
    size = other.size;
    fixed_size = other.fixed_size;
    data = new T[capacity];
    std::int64_t count = size == -1 ? 0 : size + 1;
    for (std::int64_t i = 0; i < count; ++i)
        data[i] = other.data[i];
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {
    if (this == &other) return *this;
    delete[] data;
    capacity = other.capacity;
    size = other.size;
    fixed_size = other.fixed_size;
    data = new T[capacity];
    std::int64_t count = size == -1 ? 0 : size + 1;
    for (std::int64_t i = 0; i < count; ++i)
        data[i] = other.data[i];
    return *this;
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}


template<typename T>
void DynamicArray<T>::push_back(const T& x) {
    resizeIfNeeded();
    data[++size] = x;
}

template<typename T>
void DynamicArray<T>::push_front(const T& x) {
    resizeIfNeeded();
    for (std::int64_t i = size; i >= 0; --i)
        data[i + 1] = data[i];
    data[0] = x;
    ++size;
}

template<typename T>
void DynamicArray<T>::insert(std::int64_t idx, const T& x) {
    if (idx < 0 || idx > size + 1) throw std::invalid_argument("Index out of range");
    resizeIfNeeded();
    for (std::int64_t i = size; i >= idx; --i)
        data[i + 1] = data[i];
    data[idx] = x;
    ++size;
}

template<typename T>
void DynamicArray<T>::remove(std::int64_t idx) {
    if (isEmpty() || idx < 0 || idx > size) throw std::invalid_argument("Index out of range");
    for (std::int64_t i = idx; i < size; ++i)
        data[i] = data[i + 1];
    --size;
}

template<typename T>
void DynamicArray<T>::erase_after(std::int64_t idx) {
    if (idx < 0 || idx > size) throw std::invalid_argument("Index out of range");
    size = idx - 1;
}

template<typename T>
void DynamicArray<T>::clear() {
    delete[] data;
    data = nullptr;
    size = -1;
    capacity = 0;
}

template<typename T>
void DynamicArray<T>::printData() const {
    if (isEmpty()) return;
    for (std::int64_t i = 0; i <= size; ++i)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

template<typename T>
T& DynamicArray<T>::operator[](std::int64_t idx) {
    if (idx < 0 || idx > size) throw std::out_of_range("Index out of range");
    return data[size - idx];
}

template<typename T>
const T& DynamicArray<T>::operator[](std::int64_t idx) const {
    if (idx < 0 || idx > size) throw std::out_of_range("Index out of range");
    return data[size - idx];
}

template<typename T>
T DynamicArray<T>::front() const {
    if (isEmpty()) throw std::out_of_range("Array is empty");
    return data[0];
}

template<typename T>
T DynamicArray<T>::back() const {
    if (isEmpty()) throw std::out_of_range("Array is empty");
    return data[size];
}


void DynamicArray<float>::resizeIfNeeded() {
    if (size + 1 < capacity) return;
    if (fixed_size) throw std::overflow_error("DynamicArray overflow - fixed size");
    std::int64_t newCap = capacity == 0 ? 8 : capacity * 2;
    float* temp = new float[newCap];
    std::int64_t count = size == -1 ? 0 : size + 1;
    for (std::int64_t i = 0; i < count; ++i) temp[i] = data[i];
    delete[] data;
    data = temp;
    capacity = newCap;
}

DynamicArray<float>::DynamicArray() { resizeIfNeeded(); }

DynamicArray<float>::DynamicArray(std::int64_t cap) {
    if (cap < 1) throw std::invalid_argument("Capacity must be > 0");
    capacity = cap;
    data = new float[capacity];
}

DynamicArray<float>::DynamicArray(std::int64_t cap, bool fixed) : fixed_size(fixed) {
    if (cap < 1) throw std::invalid_argument("Capacity must be > 0");
    capacity = cap;
    data = new float[capacity];
}

DynamicArray<float>::~DynamicArray() { delete[] data; }

void DynamicArray<float>::push_back(float x) {
    resizeIfNeeded();
    data[++size] = x;
}

void DynamicArray<float>::push_front(float x) {
    resizeIfNeeded();
    for (std::int64_t i = size; i >= 0; --i) data[i + 1] = data[i];
    data[0] = x;
    ++size;
}

void DynamicArray<float>::insert(std::int64_t idx, float x) {
    if (idx < 0 || idx > size + 1) throw std::invalid_argument("Index out of range");
    resizeIfNeeded();
    for (std::int64_t i = size; i >= idx; --i) data[i + 1] = data[i];
    data[idx] = x;
    ++size;
}

void DynamicArray<float>::remove(std::int64_t idx) {
    if (isEmpty() || idx < 0 || idx > size) throw std::invalid_argument("Index out of range");
    for (std::int64_t i = idx; i < size; ++i) data[i] = data[i + 1];
    --size;
}

void DynamicArray<float>::erase_after(std::int64_t idx) {
    if (idx < 0 || idx > size) throw std::invalid_argument("Index out of range");
    size = idx - 1;
}

void DynamicArray<float>::clear() {
    delete[] data;
    data = nullptr;
    size = -1;
    capacity = 0;
}

void DynamicArray<float>::reinitialize() {
    clear();
    resizeIfNeeded();
}

void DynamicArray<float>::printData() const {
    if (isEmpty()) return;
    for (std::int64_t i = 0; i <= size; ++i)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

float DynamicArray<float>::operator[](std::int64_t idx) const {
    if (idx < 0 || idx > size) throw std::out_of_range("Index out of range");
    return data[size - idx]; 
}

float DynamicArray<float>::operator()() const {
    if (isEmpty()) return 0.0f;
    float sum = 0;
    for (std::int64_t i = 0; i <= size; ++i) sum += data[i];
    return sum;
}

float DynamicArray<float>::add(std::int64_t i, std::int64_t j) const {
    return (*this)[i] + (*this)[j];
}

float DynamicArray<float>::max() const {
    if (isEmpty()) throw std::invalid_argument("Array is empty");
    float m = data[0];
    for (std::int64_t i = 1; i <= size; ++i)
        if (data[i] > m) m = data[i];
    return m;
}

float DynamicArray<float>::min() const {
    if (isEmpty()) throw std::invalid_argument("Array is empty");
    float m = data[0];
    for (std::int64_t i = 1; i <= size; ++i)
        if (data[i] < m) m = data[i];
    return m;
}

void DynamicArray<float>::increase_capacity(std::int64_t newCap) {
    if (newCap <= capacity) throw std::invalid_argument("New capacity must be larger");
    float* temp = new float[newCap];
    for (std::int64_t i = 0; i <= size; ++i) temp[i] = data[i];
    delete[] data;
    data = temp;
    capacity = newCap;
}

void DynamicArray<float>::decrease_capacity(std::int64_t newCap) {
    if (newCap >= capacity || newCap < 1) throw std::invalid_argument("Invalid new capacity");
    float* temp = new float[newCap];
    std::int64_t maxCopy = newCap - 1;
    if (size > maxCopy) size = maxCopy;
    for (std::int64_t i = 0; i <= size; ++i) temp[i] = data[i];
    delete[] data;
    data = temp;
    capacity = newCap;
}


template class DynamicArray<int>;
template class DynamicArray<std::string>;
