#ifndef _CAOL_INCLUDE_DEQUE_ARRAY_H
#define _CAOL_INCLUDE_DEQUE_ARRAY_H
#include <iostream>
#include <deque>

class DequeArray {
private:
    std::deque<int> data; // 使用deque来存储数据
    const int capacity;   // deque的最大容量

public:
    DequeArray(int size) : capacity(size) {}

    void add(int value) {
        if (data.size() == capacity) {
            data.pop_front(); // 如果达到容量，移除最旧的元素
        }
        data.push_back(value); // 在队列末尾添加新元素
    }

    // 打印最后N条数据
    void print() {
        for (int value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};
#endif //_CAOL_INCLUDE_DEQUE_ARRAY_H

void test_dequearrar() {
    DequeArray lastN(1000); // 创建一个容量为1000的容器

    // 添加一些数据
    for (int i = 0; i < 1050; ++i) {
        lastN.add(i);
    }

    // 打印最后1000条数据
    lastN.print();
}

