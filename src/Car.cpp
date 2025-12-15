#include <iostream>
#include <string>

class ConnectorFacade {
    public:
        virtual void connect() = 0;
        virtual void disconnect() = 0;
        virtual int readData() = 0;
};

class Connector : public ConnectorFacade {
    public:
        CarCalculator* calculator;
        Connector(CarCalculator* calculator) {
            this->calculator = calculator;
        }
};

class OBDConnectorFacade : public Connector {
    public:
        OBDConnectorFacade(CarCalculator* calculator): Connector(calculator) {
        }

        void connect() {
            std::cout << "Connection established with OBD link..." << std::endl;
        }
        void disconnect() {
            std::cout << "Connection lost from OBD link..." << std::endl;
        };
        int readData() {
            std::cout << "Reading data from OBD link..." << this->calculator->readSignal()
            << std::endl;
            return 0;
        }
};

class USBConnectorFacade : public Connector {

    public:
        USBConnectorFacade(CarCalculator* calculator): Connector(calculator) {
            this->calculator = calculator;
        }
        
        void connect() {
            std::cout << "Connection established with USB link..." << std::endl;
        }
        void disconnect() {
            std::cout << "Connection lost from USB link..." << std::endl;
        };
        int readData() {
            std::cout << "Reading data from USB link..." << this->calculator->readSignal()
            << std::endl;
            return 0;
        }
};

class WifiConnectorFacade : public Connector {

    public:
        WifiConnectorFacade(CarCalculator* calculator): Connector(calculator) {
            // Call parent constructor
            this->calculator = calculator;
        }
        void connect() {
            std::cout << "Connection established with WIFI network..." << std::endl;
        }
        void disconnect() {
            std::cout << "Connection lost from WIFI network..." << std::endl;
        };
        int readData() {
            std::cout << "Reading data from WIFI network..." << this->calculator->readSignal()
            << std::endl;
            return 0;
        }
};

class CarCalculator {
    public:
        int readSignal() {
            return 1;
        }
};
