#include <iostream>
#include <string>
#include <fstream>

#include "AnimalParc.cpp"
#include "Logistic.cpp"
#include "VehiculeFactory.cpp"
#include "InteriorDesigner.cpp"
#include "ITParc.cpp"
#include "HouseArchitect.cpp"
#include "Car.cpp"
#include "Screen.cpp"

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


    Logistics* logistic = new SeaLogistics();
    Transport* transport = logistic->planDelivery();
    transport->deliver();

    Factory* factory = new MotorbikeFactory();

    Vehicle* vehicule = factory->create();
    vehicule->startEngine();
    vehicule->accelerate();
    vehicule->brake();
    vehicule->stopEngine();

    // Ouvrir un fichier
    std::ifstream file("interior-design.conf");
    // Lire le fichier
    std::string line;
    std::getline(file, line);
    file.close();

    size_t equal_position = line.find('=');
    std::string key = line.substr(0, equal_position);
    std::string value = line.substr(equal_position + 1);
    std::cout << "Key: " << key << std::endl;
    std::cout << "Value: " << value << std::endl;

    FurnitureFactory* furnitureFactory = FurnitureStore::useDesign(value);
    Chair* chair = furnitureFactory->createChair();
    chair->hasLegs();
    chair->sitOn();

    Table* table = furnitureFactory->createTable();
    table->hasLegs();
    table->putOn();

    Sofa* sofa = furnitureFactory->createSofa();
    sofa->sitOn();
    sofa->layedDown();

    Chair* chair1 = VictorianChair::create();
    Chair* chair2 = new VictorianChair();


    ITParcFactory* it_parc_factory = ITParcStore::useMac();
    Computer* server = it_parc_factory->createServer();
    server->powerOn();
    server->powerOff();

    Computer* workstation = it_parc_factory->createWorkStation();
    workstation->powerOn();
    workstation->powerOff();

    Computer* laptop = it_parc_factory->createLaptop();
    laptop->powerOn();
    laptop->powerOff();

    HouseBuilder* builder = new HouseBuilder();
    House* house = builder->withDoorsCount(4)
        ->withWindowsCount(7)
        ->withGarage(true)
        ->withGarden(true)
        ->build();

    std::cout << "Doors count: " << house->doorsCount << std::endl;
    std::cout << "Windows count: " << house->windowsCount << std::endl;
    std::cout << "Has garden: " << house->hasGarden << std::endl;
    std::cout << "Has garage: " << house->hasGarage << std::endl;

    CarCalculator* calculator = new CarCalculator();
    Connector* connector = new USBConnectorFacade(calculator);
    connector->connect();
    connector->readData();
    connector->disconnect();

    Screen* hdmiScreen = new Screen();
    HDMIToVGADisplayAdapter* adapter = new HDMIToVGADisplayAdapter(hdmiScreen);
    PC* pc = new PC(adapter);
    pc->display();
    

    return 0;
}

