#include <iostream>

class Computer {
    public:
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
};

class Server : public Computer {
};

class WindowsServer : public Server {
    public:
    void powerOn() override {
        std::cout << "Bienvenue sous Windows Server 2026 OS" << std::endl;
    }
    void powerOff() override {
        std::cout << "A bientot sous Windows Server 2026 OS" << std::endl;
    }

    static Computer* create() {
        return new WindowsServer();
    }
};

class LinuxServer : public Server {
    public:
    void powerOn() override {
        std::cout << "Booting on LinOS" << std::endl;
    }
    void powerOff() override {
        std::cout << "Shutting down on LinOS" << std::endl;
    }

    static Computer* create() {
        return new LinuxServer();
    }
};

class MacServer : public Server {

    public:
    void powerOn() override {
        std::cout << "Initializing MacOS" << std::endl;
    }
    void powerOff() override {
        std::cout << "Shutting down on MacOS" << std::endl;
    }

    static Computer* create() {
        return new MacServer();
    }
};



class WorkStation : public Computer {
};

class WindowsWorkStation : public WorkStation {

    public:
    void powerOn() override {
        std::cout << "Bienvenue sous Windows Vista OS" << std::endl;
    }
    void powerOff() override {
        std::cout << "A bientot sous Windows Vista OS" << std::endl;
    }

    static Computer* create() {
        return new WindowsWorkStation();
    }
};

class LinuxWorkStation : public WorkStation {

    public:
    void powerOn() override {
        std::cout << "Bienvenue sous Linux Fedora 43 OS" << std::endl;
    }
    void powerOff() override {
        std::cout << "A bientot sous Linux Fedora 43 OS" << std::endl;
    }

    static Computer* create() {
        return new LinuxWorkStation();
    }
};

class MacWorkStation : public WorkStation {

    public:
    void powerOn() override {
        std::cout << "Bienvenue sous Mac OS for Worskstation" << std::endl;
    }
    void powerOff() override {
        std::cout << "A bientot sous Mac OS for Worskstation" << std::endl;
    }

    static Computer* create() {
        return new MacWorkStation();
    }
};


class Laptop : public Computer {
};

class WindowsLaptop : public Laptop {

    public:
    void powerOn() override {
        std::cout << "Bienvenue sous Windows 11 N" << std::endl;
    }
    void powerOff() override {
        std::cout << "A bientot sous Windows 11 N" << std::endl;
    }

    static Computer* create() {
        return new WindowsLaptop();
    }
};

class LinuxLaptop : public Laptop {

    public:
    void powerOn() override {
        std::cout << "Bienvenue sous Linux Kali" << std::endl;
    }
    void powerOff() override {
        std::cout << "A bientot sous Linux Kali" << std::endl;
    }

    static Computer* create() {
        return new LinuxLaptop();
    }
};

class MacLaptop : public Laptop {
    public:
    void powerOn() override {
        std::cout << "Bienvenue sous MacOS M6" << std::endl;
    }
    void powerOff() override {
        std::cout << "A bientot sous MacOS M6" << std::endl;
    }

    static Computer* create() {
        return new MacLaptop();
    }
};

class ITParcFactory {
    public:
        virtual Computer* createServer() = 0;
        virtual Computer* createWorkStation() = 0;
        virtual Computer* createLaptop() = 0;
};

class WindowsITParcFactory : public ITParcFactory {
    public:
        Computer* createServer() override {
            return WindowsServer::create();
        }
        Computer* createWorkStation() override {
            return WindowsWorkStation::create();
        }
        Computer* createLaptop() override {
            return WindowsLaptop::create();
        }
};

class LinuxITParcFactory : public ITParcFactory {
    public:
        Computer* createServer() override {
            return LinuxServer::create();
        }
        Computer* createWorkStation() override {
            return LinuxWorkStation::create();
        }
        Computer* createLaptop() override {
            return LinuxLaptop::create();
        }
};

class MacITParcFactory : public ITParcFactory {
    public:
        Computer* createServer() override {
            return MacServer::create();
        }
        Computer* createWorkStation() override {
            return MacWorkStation::create();
        }
        Computer* createLaptop() override {
            return MacLaptop::create();
        }
};

class ITParcStore {
    public:
    static ITParcFactory* useWindows() {
        return new WindowsITParcFactory();
    }
    static ITParcFactory* useLinux() {
        return new LinuxITParcFactory();
    }
    static ITParcFactory* useMac() {
        return new MacITParcFactory();
    }
};