#include <iostream>

class Vehicle {
    public:
        virtual void startEngine() = 0;
        virtual void stopEngine() = 0;
        virtual void accelerate() = 0;
        virtual void brake() = 0;
};

class Car : public Vehicle {
    public:
        void startEngine() {
            std::cout << "Démarrage du moteur thermique de la voiture..." << std::endl;
        }
        void stopEngine() {
            std::cout << "Arret du moteur thermique de la voiture..." << std::endl;
        }
        void accelerate() {
            std::cout << "C'est un diesel, ca rame..." << std::endl;
        }
        void brake() {
            std::cout << "C'est lourd, mais ca ralenti..." << std::endl;
        }

};

class Motorbike : public Vehicle {
    public:
        void startEngine() {
            std::cout << "Démarrage du moteur thermique de la moto..." << std::endl;
        }
        void stopEngine() {
            std::cout << "Arret du moteur thermique de la moto..." << std::endl;
        }
        void accelerate() {
            std::cout << "C'est super rapide..." << std::endl;
        }
        void brake() {
            std::cout << "Ca freine fort..." << std::endl;
        }

};

class Factory {
    public:
        virtual Vehicle* create() = 0;
};

class CarFactory : public Factory {
    public:
        Vehicle* create() override {
            return new Car();
        }
};

class MotorbikeFactory : public Factory {
    public:
        Vehicle* create() override {
            return new Motorbike();
        }
};