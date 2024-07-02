#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass Constructor\n"; }
    ~MyClass() { std::cout << "MyClass Destructor\n"; }
    void sayHello() { std::cout << "Hello, World!\n"; }
};

int main() {
    // Creating a shared pointer
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    {
        // Creating another shared pointer to the same object
        std::shared_ptr<MyClass> ptr2 = ptr1;

        // Accessing the object through the shared pointer
        ptr2->sayHello();

        // ptr2 goes out of scope and is destroyed, but the object is not deleted
        // because ptr1 is still pointing to it
    }

    // The object is deleted when the last shared pointer (ptr1) is destroyed
    return 0;
}

/*

A shared pointer is a smart pointer in C++ that helps manage the memory of dynamically allocated objects. 
It is part of the C++11 standard library and can be found in the <memory> header.
Shared pointers ensure that an object is automatically deleted when no shared pointers are pointing to it. 

 Advantages of Shared Pointer:
 1. Automatic Memory Management
 2.Shared Ownership
 3.Thread Safety

 Note: To avoid circular reference we use 'std::weak_ptr'
*/