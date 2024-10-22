#include "Serializer.hpp"

int main() 
{
    Data myData;
    myData.value = 42;

    uintptr_t raw = Serializer::serialize(&myData);

    Data* ptr = Serializer::deserialize(raw);

    if (ptr == &myData) {
        std::cout << "Good! pointers are equal" << std::endl;
        std::cout << "value: " << ptr->value << std::endl;
    }
    else 
    {
        std::cout << "Error! Pointers have a discrepancy." << std::endl;
    }

    return 0;
}