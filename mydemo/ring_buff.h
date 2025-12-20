#pragma once
#include <array>
#include <iostream>

class RingBuffer {
public:
    RingBuffer() : start(0), size(0) {}

    // 添加数据
    void add(int value) {
        buffer[(start + size) % capacity] = value;
        if (size < capacity) {
            ++size; // 如果缓冲区未满，增加当前大小
        }
        else {
            start = (start + 1) % capacity; // 缓冲区满时，移动起始位置
        }
    }

    // 打印所有数据
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << buffer[(start + i) % capacity] << " ";
        }
        std::cout << std::endl;
    }

private:
    static constexpr size_t capacity = 100; // 固定容量
    std::array<int, capacity> buffer;       // 底层数组
    size_t start;                           // 环形缓冲区的起始位置
    size_t size;                            // 当前数据量
};

void test_ring() {
    RingBuffer cb;

    // 模拟添加数据
    for (int i = 1; i <= 105; ++i) {
        cb.add(i);
    }

    // 打印结果，应该是从 6 到 105
    cb.print();
}
