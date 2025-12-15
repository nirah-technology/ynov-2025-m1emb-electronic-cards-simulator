#include <iostream>

class Transport {
    public:
    virtual void deliver() = 0;
};

class Truck : public Transport {
    public:
    void deliver() override {
        std::cout << "Je vais sur la route" << std::endl;
    }
};

class Ship : public Transport {
    public:
    void deliver() override {
        std::cout << "Je vais sur l'eau" << std::endl;
    }
};

class Logistics {
    public:
    Transport* planDelivery() {
        Transport* t = createTransport();
        return t;
    }
    virtual Transport* createTransport() = 0;
};

class RoadLogistics : public Logistics {
    public:
    Transport* createTransport() override {
        return new Truck();
    }
};

class SeaLogistics : public Logistics {
    public:
    Transport* createTransport() override {
        return new Ship();
    }
};


