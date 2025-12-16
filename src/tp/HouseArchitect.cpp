class House {
    private:
    public:
        int windowsCount;
        int doorsCount;
        bool hasGarden;
        bool hasGarage;
        House(int windowsCount, int doorsCount, bool hasGarden, bool hasGarage) {
            this->windowsCount = windowsCount;
            this->doorsCount = doorsCount;
            this->hasGarden = hasGarden;
            this->hasGarage = hasGarage;
        }
};

class HouseBuilder {
    private:
        int windowsCount = 0;
        int doorsCount = 0;
        bool hasGarden = false;
        bool hasGarage = false;
    public:
        HouseBuilder* withWindowsCount(int count) {
            this->windowsCount = count;
            return this;
        }

        HouseBuilder* withDoorsCount(int count) {
            this->doorsCount = count;
            return this;
        }

        HouseBuilder* withGarden(bool hasGarden) {
            this->hasGarden = hasGarden;
            return this;
        }

        HouseBuilder* withGarage(bool hasGarage) {
            this->hasGarage = hasGarage;
            return this;
        }

        House* build() {
            return new House(this->windowsCount, this->doorsCount, this->hasGarden, this->hasGarage);
        }
};
