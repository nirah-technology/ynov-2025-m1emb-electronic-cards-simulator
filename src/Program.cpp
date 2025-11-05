#include <iostream>

#include "ElectronicCardManufacturer.h"
#include "Rack.h"
#include "ElectronicCard.h"




int main() {

    Rack* rack = new Rack();
    ElectronicCard* arduinoUno = new ElectronicCard();
    arduinoUno->manufacturer = "Arduino";
    arduinoUno->model = "Uno";
    arduinoUno->ram = 1024;
    arduinoUno->cpu_core_count = 1;
    arduinoUno->cpu_frequency = 1.2;


    rack->cards.push_back(*arduinoUno);

    return 0;
}

