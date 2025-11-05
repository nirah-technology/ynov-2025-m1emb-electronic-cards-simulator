#include "ElectronicCard.h"

#include <string>

struct ElectronicCard
{
    std::string manufacturer;
    std::string model;

    unsigned short int ram;
    unsigned short int cpu_core_count;
    float cpu_frequency;
    unsigned int storage_capacity;
};
