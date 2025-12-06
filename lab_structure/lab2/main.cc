#include "DynamicArray.h"
#include "stack.h"
#include "queue.h"
#include <iostream>

int main() {
    std::cout << "test old hw\n";
    DynamicArray<float> arr;
    arr.push_back(5.5f); arr.push_back(1.1f); arr.push_back(9.9f);
    arr.printData();
    std::cout << "min: " << arr.min() << "\n";
    std::cout << "sum: " << arr() << "\n\n";

    std::cout << "check stack\n";
    Stack<int> st(3);
    st.push(10); st.push(20); st.push(30);
    std::cout << "top: " << st.top() << "\n";
    std::cout << "pop: " << st.pop() << "\n";

    std::cout << "\nqueue test\n";
    Queue<int> q(10);
    q.enqueue(100); q.enqueue(200); q.enqueue(300);
    std::cout << "deq: " << q.dequeue() << "\n";
    std::cout << "deq: " << q.dequeue() << "\n";

    
    return 0;
}
