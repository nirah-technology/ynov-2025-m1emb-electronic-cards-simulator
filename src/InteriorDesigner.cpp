#include <iostream>

class Chair {
    public:
        virtual int hasLegs() = 0;
        virtual void sitOn() = 0;  
};

class VictorianChair : public Chair {
    public:
        int hasLegs() override {
            return 4;
        }

        void sitOn() override {
            std::cout << "Je m'assoie confortablement. \n";
        }

        static Chair* create() {
            return new VictorianChair();
        }
};

class ModernChair : public Chair {
    public:
        int hasLegs() override {
            return 1;
        }

        void sitOn() override {
            std::cout << "Je m'assoie mais je suis instable \n";
        }
};

class Table {
    public:
        virtual int hasLegs() = 0;
        virtual void putOn() = 0;

};

class VictorianTable : public Table {
    public:
        int hasLegs() override {
            return 4;
        }
        void putOn() override {
            std::cout << "Je dépose un objet, et c'est stable. \n";
        }
};

class ModernTable : public Table {
    public:
        int hasLegs() override {
            return 1;
        }
        void putOn() override {
            std::cout << "Je dépose un objet, et c'est instable. \n";
        }
};


class Sofa {
    public:
        virtual void sitOn() = 0;
        virtual void layedDown() = 0;
};

class VictorianSofa : public Sofa {
    public:
        void sitOn() override {
            std::cout << "Je m'assoie confortablement. \n";
        }
        void layedDown() override {
            std::cout << "Je me couche confortablement \n";
        }
};

class ModernSofa : public Sofa {
    public:
        void sitOn() override {
            std::cout << "Je m'assoie mais je suis instable. \n";
        }
        void layedDown() override {
            std::cout << "Je ne peux pas me coucher. \n";
        }
};

class FurnitureFactory {
    public:
        virtual Chair* createChair() = 0;
        virtual Table* createTable() = 0;
        virtual Sofa* createSofa() = 0;
};

class VictorianFurnitureFactory : public FurnitureFactory {
    public:
        Chair* createChair() override {
            return VictorianChair::create();
        }
        Table* createTable() override {
            return new VictorianTable();
        }

        Sofa* createSofa() override {
            return new VictorianSofa();
        }
};

class ModernFurnitureFactory : public FurnitureFactory {
    public:
        Chair* createChair() override {
            return new ModernChair();
        }
        Table* createTable() override {
            return new ModernTable();
        }

        Sofa* createSofa() override {
            return new ModernSofa();
        }
};

class FurnitureStore {
    public:
    static FurnitureFactory* useVictorianDesign() {
        return new VictorianFurnitureFactory();
    }
    static FurnitureFactory* useModernDesign() {
        return new ModernFurnitureFactory();
    }

    static FurnitureFactory* useDesign(std::string design) {
        if (design == "victorian") {
            return useVictorianDesign();
        } else if (design == "modern") {
            return useModernDesign();
        }
        return NULL;
    }
};