#include <iostream>
#include <string>

#include "AnimalParc.cpp"
#include "GameLoader.cpp"

class ElectronicCard {

private:
    std::string manufacturer;
    std::string model;
    unsigned int memory_in_megabits;
    unsigned short cpu_cores_count;
    double cpu_frequency;

public:

    ElectronicCard() {
        std::cout << "Instanciation d'une carte électronique." << std::endl;
    }
    
    ~ElectronicCard() {
        std::cout << "Destruction d'une carte électronique." << std::endl;

    }

    std::string get_manufacturer() {
        return this->manufacturer;
    }
    std::string get_model() {
        return this->model;
    }
    unsigned int get_memory_in_megabits() {
        return this->memory_in_megabits;
    }
    unsigned int get_cpu_cores_count() {
        return this->cpu_cores_count;
    }
    void set_cpu_cores_count(unsigned int new_cpu_cores_count) {
        this->cpu_cores_count = new_cpu_cores_count;
    }

};

Animal* generate_animal() {
    return new Dog();
};

int main() {

    Animal* pet = generate_animal();
    std::cout << Animal::total_animals_created;

    
    GameLoader::backup();

    return 0;
}

