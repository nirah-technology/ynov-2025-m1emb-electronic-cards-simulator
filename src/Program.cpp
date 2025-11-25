#include <iostream>
#include <string>

#include "AnimalParc.cpp"

int main() {
    // Animal* pet = new Dog("Yorkshire", "Yuma");
    // pet->communicate();

    // Dog* pet = new Dog("Yorkshire", "Yuma");
    // pet->communicate();
    // pet->

    // IAbleToBark* pet = new Dog("Yorkshire", "Yuma");
    // pet->;

    // IAbleToMeow* pet = new Dog("Yorkshire", "Yuma");
    // pet->communicate();


    IAbleToCommunicate* pet = new Dog("Yorkshire", "Yuma");
    pet->communicate();

    return 0;
}

