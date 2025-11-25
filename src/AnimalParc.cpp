#include <string>
#include <iostream>

struct GpsCoordinates {
    double longitude;
    double latitude;
    double altitude;
};

// INTERFACES - FONCTIONNALITES
class IAbleToMove {
    public:
    virtual ~IAbleToMove() = default;

    virtual void move(const double longitude, const double latitude, const double altitude) = 0;
    virtual GpsCoordinates retrieve_location() = 0;
    protected:
        IAbleToMove() = default;
};

class IAbleToCommunicate {
    public:
    virtual ~IAbleToCommunicate() = default;

    virtual void communicate() = 0;
    protected:
        IAbleToCommunicate() = default;
};

class IAbleToMeow {
    public:
    virtual ~IAbleToMeow() = default;

    virtual void meow() = 0;
    protected:
        IAbleToMeow() = default;
};

class IAbleToBark {
    public:
    virtual ~IAbleToBark() = default;

    virtual void bark() = 0;
    protected:
        IAbleToBark() = default;
};

class IAbleToLive {
    public:
    virtual ~IAbleToLive() = default;

    virtual void birth(unsigned int birth_date) = 0;
    virtual void death(unsigned int death_date) = 0;
    protected:
        IAbleToLive() = default;
};

class Animal : public IAbleToLive, public IAbleToMove, public IAbleToCommunicate {
    private:
        unsigned int birth_date;
        unsigned int death_date;
        GpsCoordinates location; 
        
    protected:
        std::string species;
        std::string breed;
        std::string name;
        
        
        
    public:
        Animal() = default;
        ~Animal() = default;

        void birth(unsigned int birth_date) override {
            this->birth_date = birth_date;
        }

        void death(unsigned int death_date) override {
            this->death_date = death_date;
        }

        void move(const double longitude, const double latitude, const double altitude) {
            this->location.altitude = altitude;
            this->location.longitude = longitude;
            this->location.latitude = latitude;
        }

        GpsCoordinates retrieve_location() {
            return this->location;
        }
};

class Cat : public Animal, public IAbleToMeow {
    public:
        Cat(std::string breed, std::string name) {
            this->species = "Cat";
            this->breed = breed;
            this->name = name;
        }

        void meow() override {
            std::cout << "Miou" << std::endl;
        }

        void communicate() override {
            this->meow();
        }
};

class Dog : public Animal, public IAbleToBark {
    public:
        Dog(std::string breed, std::string name) {
            this->species = "Dog";
            this->breed = breed;
            this->name = name;
        }

        void bark() override {
            std::cout << "Ouaf" << std::endl;
        }

        void communicate() override {
            this->bark();
        }
};
