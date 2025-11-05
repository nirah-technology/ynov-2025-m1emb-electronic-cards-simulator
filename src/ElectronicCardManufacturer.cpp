#include <random>
#include <iostream>

#include "ElectronicCardManufacturer.h"

bool is_arduino(const ElectronicCardManufacturer manufacturer) {
    return manufacturer == ElectronicCardManufacturer::Arduino;
}

char* generate_manufacturer_name(int min_length=3, int max_length=10) {
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<int> distribution(min_length, max_length);
    const unsigned int length = distribution(generator);
    char* name = new char[length + 1];
    for (unsigned int i = 0; i < length; i++) {
        std::uniform_int_distribution<int> distribution(65, 90);
        name[i] = distribution(generator);
    }
    name[length] = '\0';
    return name;
}