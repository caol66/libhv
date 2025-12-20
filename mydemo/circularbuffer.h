#ifndef _CAOL_INCLUDE_CIRCULAR_H
#define _CAOL_INCLUDE_CIRCULAR_H
#include <iostream>
#include <array>

template <typename T, size_t Capacity> class CircularBuffer {
public:
    CircularBuffer() : head_(0), size_(0) {}

    // 插入数据
    void push(const T& value) {
        buffer_[head_] = value;
        head_ = (head_ + 1) % Capacity; // 循环写入
        if (size_ < Capacity) {
            ++size_; // 增加有效数据的数量
        }
    }

    // 获取指定位置的数据
    T get(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        size_t actualIndex = (head_ + Capacity - size_ + index) % Capacity;
        return buffer_[actualIndex];
    }

    // 获取当前数据数量
    size_t size() const { return size_; }

    // 打印所有有效数据
    void print() const {
        for (size_t i = 0; i < size_; ++i) {
            std::cout << get(i) << " ";
        }
        std::cout << std::endl;
    }

private:
    std::array<T, Capacity> buffer_; // 固定大小的缓冲区
    size_t head_;                    // 下一个写入位置
    size_t size_;                    // 当前有效数据的数量
};

#endif //_CAOL_INCLUDE_CIRCULAR_H

void test_fixedarray() {
    CircularBuffer<int, 1000> buffer;

    // 模拟插入数据
    for (int i = 1; i <= 1010; ++i) {
        buffer.push(i);
    }

    // 打印所有有效数据（最近的1000条）
    std::cout << "Buffer contains: ";
    buffer.print();

    // 获取指定位置的数据
    std::cout << "Element at index 0: " << buffer.get(0) << std::endl;     // 最老的数据
    std::cout << "Element at index 999: " << buffer.get(999) << std::endl; // 最新的数据
}