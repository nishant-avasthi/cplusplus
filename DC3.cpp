#include<bits/stdc++.h>
using namespace std;

template<typename T, int Size>
class Array {
private:
    T data[Size];

public:
    // Member function fill
    void fill(const T& value) {
        std::fill(data, data + Size, value);
    }
    Array(){
        fill(T());
    }
    // Constructor with initializer list
    explicit  Array(std::initializer_list<T> initList) {
        std::copy(initList.begin(), initList.end(), data);
        if (initList.size() < Size)
            std::fill(data + initList.size(), data + Size, T()); // Fill remaining with default value
    }

    // Move constructor
    Array(Array&& other) noexcept {
        std::copy(std::make_move_iterator(other.data), std::make_move_iterator(other.data + Size), data);
    }

    // Copy constructor
    Array(const Array& other) {
        std::copy(other.data, other.data + Size, data);
    }

    // Move assignment operator
    Array& operator=(Array&& other) noexcept {
        std::copy(std::make_move_iterator(other.data), std::make_move_iterator(other.data + Size), data);
        return *this;
    }

    // Copy assignment operator
    Array& operator=(const Array& other) {
        std::copy(other.data, other.data + Size, data);
        return *this;
    }

    // Destructor
    ~Array() {}

    // Subscripting operator
    T& operator[](int index) {
        return data[index];
    }

    // Member function size
    constexpr int size() const {
        return Size;
    }

    

    // Stream inserter
    friend std::ostream& operator<<(std::ostream& os, const Array<T, Size>& arr) {
        os << '[';
        for (int i = 0; i < Size; ++i) {
            os << arr.data[i];
            if (i != Size - 1)
                os << ", ";
        }
        os << ']';
        return os;
    }

    // Member type Value alias
    using Value = T;
};

int main() {
    // Example usage
    Array<int, 5> arr{1, '2', 3}; // Remaining elements initialized to 0
    std::cout << "Initial Array: " << arr << std::endl;

    arr.fill(5); // Fill array with 5
    std::cout << "After filling with 5: " << arr << std::endl;

    std::cout << "Size of array: " << arr.size() << std::endl;

    Array<int, 5> arr2 = std::move(arr); // Move constructor
    std::cout << "Array after move construction: " << arr2 << std::endl;

    Array<int, 5> arr3;
    arr3 = arr2; // Copy assignment
    std::cout << "Array after copy assignment: " << arr3 << std::endl;

    return 0;
}
