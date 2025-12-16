#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

class Observer {
    public:
    virtual void update(bool is_walking) = 0;

};

class Mouse {
    private:
        std::vector<Observer*> vilains = std::vector<Observer*>(0);
        
    public:
        bool is_walking = false;
        std::string name;
        Mouse(std::string name) : name(name) {
        }

        void observed_by(Observer* vilain) {
            this->vilains.push_back(vilain);
        }

        void stop_observation(Observer* vilain) {
            this->vilains.erase(std::remove(this->vilains.begin(), this->vilains.end(), vilain), this->vilains.end());
        }

        void notify_all_vilains() {
            for (Observer* vilain : this->vilains) {
                vilain->update(this->is_walking);
            }
        }

        void move() {
            this->is_walking = true;
            this->notify_all_vilains();
        }

        void rest_in_place() {
            this->is_walking = false;
            this->notify_all_vilains();
        }
};



class Kitten : public Observer {
    public:
        std::string name;
        Kitten(std::string name) : name(name) {
        }

    void update(bool is_walking) override {
        if (is_walking) {
            std::cout << this->name << " la pourchasse" << std::endl;
        } else {
            std::cout << this->name << " reste sur place et la regarde" << std::endl;
        }
    }
};