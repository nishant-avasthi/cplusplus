#include<bits/stdc++.h>
using namespace std;
#include <iostream>
 
class String
{
private:
    char* ptr_;
    int size_;
public:
    String(const char* data, int size){
        std::cout << "Normal" << std::endl;
        ptr_ = new char[size];
        size_ = size;
        for (int i=0;i<size;i++)
        {
            ptr_[i] = data[i];
        }
    }
    String(const String& other)
    {
        std::cout << "Copy" << std::endl;
        ptr_ = new char[other.size_];
        size_ = other.size_;
        for (int i=0;i<size_;i++)
        {
            ptr_[i] = other.ptr_[i];
        }
    }
    String& operator=(const String& other)
    {
        std::cout << "Copy assignment" << std::endl;
        if (this == &other) return *this;
 
        ptr_ = new char[other.size_];
        size_ = other.size_;
        for (int i=0;i<size_;i++)
        {
            ptr_[i] = other.ptr_[i];
        }
        return *this;
    }
    String(String&& other): ptr_(std::move(other.ptr_)), size_(other.size_)
    {
        std::cout << "Move" << std::endl;
        other.ptr_ = nullptr;
        other.size_ = 0;
    }
    String &operator=(String&& other)
    {
        std::cout << "Move assignment" << std::endl;
        if (this == &other) return *this;
 
        ptr_ = std::move(other.ptr_);
        size_ = other.size_;
        other.ptr_ = nullptr;
        other.size_ = 0;
        return *this;
    }
    void print(void) const noexcept
    {
        for (int i=0;i<size_;i++)
        {
            std::cout << ptr_[i];
        }
        std::cout << std::endl;
    }
    ~String()
    {
        if (nullptr != ptr_)
        {
            delete[] ptr_;
            ptr_ = nullptr;
        }
    }
};
 
int main()
{
    const char* data = "Hello Anil";
    const char* data1 = "Hello Nish";
    String temp(data1, 11);
    String str(data, 11);
    str.print();
    String str1(str);
    str1.print();
    str1 = temp;
    str1.print();
    String str2(std::move(str1));
    str2.print();
    str1.print();
    str2 = std::move(str);
    str2.print();
    str.print();
    return 0;
}