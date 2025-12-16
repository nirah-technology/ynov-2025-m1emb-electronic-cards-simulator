#include <iostream>
#include <string>

// Forward declaration to let the compiler know that CarCalculator is a class.

class CarCalculator {
    public:
        int readSignal() {
            return 1;
        }
};

class ConnectorFacade {
    public:
        virtual void connect() = 0;
        virtual void disconnect() = 0;
        virtual int readData() = 0;
};

class Connector : public ConnectorFacade {
    public:
        Connector(CarCalculator* calculator) {
            this->calculator = calculator;
        }
    protected:
        CarCalculator* calculator;
};

class OBDConnectorFacade : public Connector {
    public:
        OBDConnectorFacade(CarCalculator* calculator): Connector(calculator) {
        }

        void connect() override {
            std::cout << "Connection established with OBD link..." << std::endl;
        }
        void disconnect() override {
            std::cout << "Connection lost from OBD link..." << std::endl;
        };
        int readData() override {
            int data = this->calculator->readSignal();
            std::cout << "Reading data from OBD link..." << data
            << std::endl;
            return data;
        }
};

class USBConnectorFacade : public Connector {

    public:
        USBConnectorFacade(CarCalculator* calculator): Connector(calculator) {}
        
        void connect() override {
            std::cout << "Connection established with USB link..." << std::endl;
        }
        void disconnect() override {
            std::cout << "Connection lost from USB link..." << std::endl;
        };
        int readData() override {
            std::cout << "Reading data from USB link..." << this->calculator->readSignal()
            << std::endl;
            return 0;
        }
};

class WifiConnectorFacade : public Connector {

    public:
        WifiConnectorFacade(CarCalculator* calculator): Connector(calculator) {}
        void connect() override {
            std::cout << "Connection established with WIFI network..." << std::endl;
        }
        void disconnect() override {
            std::cout << "Connection lost from WIFI network..." << std::endl;
        };
        int readData() override {
            std::cout << "Reading data from WIFI network..." << this->calculator->readSignal()
            << std::endl;
            return 0;
        }
};

