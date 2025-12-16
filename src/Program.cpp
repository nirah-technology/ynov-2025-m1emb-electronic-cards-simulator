#include <iostream>
#include <string>
#include <fstream>

// #include "tp/AnimalParc.cpp"
// #include "tp/Logistic.cpp"
// #include "tp/VehiculeFactory.cpp"
// #include "tp/InteriorDesigner.cpp"
// #include "tp/ITParc.cpp"
// #include "tp/HouseArchitect.cpp"
// #include "tp/Car.cpp"
// #include "tp/Screen.cpp"
// #include "tp/TreeGame.cpp"
// #include "tp/GitChain.cpp"
// #include "tp/TAJ.cpp"
// #include "tp/SmartFlower.cpp"
// #include "tp/TVController.cpp"

#include "gamepad/Buttons.cpp"
#include "gamepad/JoySticks.cpp"
#include "gamepad/games/GodOfWar.cpp"
#include "gamepad/PlayStationGamePad.cpp"


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


    // Logistics* logistic = new SeaLogistics();
    // Transport* transport = logistic->planDelivery();
    // transport->deliver();

    // Factory* factory = new MotorbikeFactory();

    // Vehicle* vehicule = factory->create();
    // vehicule->startEngine();
    // vehicule->accelerate();
    // vehicule->brake();
    // vehicule->stopEngine();

    // // Ouvrir un fichier
    // std::ifstream file("interior-design.conf");
    // // Lire le fichier
    // std::string line;
    // std::getline(file, line);
    // file.close();

    // size_t equal_position = line.find('=');
    // std::string key = line.substr(0, equal_position);
    // std::string value = line.substr(equal_position + 1);
    // std::cout << "Key: " << key << std::endl;
    // std::cout << "Value: " << value << std::endl;

    // FurnitureFactory* furnitureFactory = FurnitureStore::useDesign(value);
    // Chair* chair = furnitureFactory->createChair();
    // chair->hasLegs();
    // chair->sitOn();

    // Table* table = furnitureFactory->createTable();
    // table->hasLegs();
    // table->putOn();

    // Sofa* sofa = furnitureFactory->createSofa();
    // sofa->sitOn();
    // sofa->layedDown();

    // Chair* chair1 = VictorianChair::create();
    // Chair* chair2 = new VictorianChair();


    // ITParcFactory* it_parc_factory = ITParcStore::useMac();
    // Computer* server = it_parc_factory->createServer();
    // server->powerOn();
    // server->powerOff();

    // Computer* workstation = it_parc_factory->createWorkStation();
    // workstation->powerOn();
    // workstation->powerOff();

    // Computer* laptop = it_parc_factory->createLaptop();
    // laptop->powerOn();
    // laptop->powerOff();

    // HouseBuilder* builder = new HouseBuilder();
    // House* house = builder->withDoorsCount(4)
    //     ->withWindowsCount(7)
    //     ->withGarage(true)
    //     ->withGarden(true)
    //     ->build();

    // std::cout << "Doors count: " << house->doorsCount << std::endl;
    // std::cout << "Windows count: " << house->windowsCount << std::endl;
    // std::cout << "Has garden: " << house->hasGarden << std::endl;
    // std::cout << "Has garage: " << house->hasGarage << std::endl;

    // CarCalculator* calculator = new CarCalculator();
    // Connector* connector = new USBConnectorFacade(calculator);
    // connector->connect();
    // connector->readData();
    // connector->disconnect();

    // Screen* hdmiScreen = new Screen();
    // HDMIToVGADisplayAdapter* adapter = new HDMIToVGADisplayAdapter(hdmiScreen);
    // PC* pc = new PC(adapter);
    // pc->display();

    // Tree*  super_tree = new Tree(10, 4, "Sapin Noel");
    // Forest* forest = new Forest();
    // forest->addTree(super_tree, 0, 0);
    // forest->addTree(super_tree, 10, 10);
    // forest->addTree(super_tree, 10, 20);
    // forest->addTree(super_tree, 12, 15);
    // forest->addTree(super_tree, 20, 20);
    // forest->render();

    // Step* utStep = new LaunchUnitTestsStep();
    // Step* qualityStep = new LaunchQualityTestsStep();
    // Step* securityStep = new LaunchSecurityTestsStep();
    // Step* compilationStep = new CompileStep();
    // Step* deployStep = new DeployBinarayStep();

    // utStep->set_next(qualityStep);
    // qualityStep->set_next(securityStep);
    // securityStep->set_next(compilationStep);
    // compilationStep->set_next(deployStep);

    // GitPipeline* pipeline = new GitPipeline(utStep);
    // pipeline->run();

    // Kitten* tom = new Kitten("Tom");
    // Kitten* nitro = new Kitten("Nitro");
    // Kitten* taka = new Kitten("Taka");
    // Kitten* nala = new Kitten("Nala");
    // Mouse* jerry = new Mouse("Jerry");

    // jerry->observed_by(tom);
    // // jerry->observed_by(nitro);
    // // jerry->observed_by(taka);
    // // jerry->observed_by(nala);

    // jerry->move();
    // jerry->rest_in_place();

    // SmartFlower* flower = new SmartFlower();
    // flower->power_on();
    // flower->stand_by();
    // flower->activate();
    // flower->open();
    // flower->track();
    // flower->untrack();
    // flower->close();
    // flower->power_off();

    // TeleCommand tvCommand = TeleCommand();
    // tvCommand.powerOn();
    // tvCommand.powerOff();
    // tvCommand.channel1();
    
    PlayStationGamePad* gamePad = new PlayStationGamePad();
    gamePad->attach_commond_to_x(new JumpCommand());

    gamePad->press_c_button();

    return 0;
}

