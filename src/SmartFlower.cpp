#include <iostream>

enum FlowerStates {
    POWER_OFF,
    POWER_ON,
    STAND_BY,
    ACTIVATE,
    OPEN,
    TRACK,
    UNTRACK,
    CLOSE
};

class SmartFlower {
    private:
        // FlowerState* state;
        FlowerStates current_state;
    public:
        SmartFlower() {
            this->current_state = FlowerStates::POWER_OFF;
        }
        void power_off() {
            switch (this->current_state)
            {
            case FlowerStates::POWER_OFF:
                std::cout << "Déja POWER_OFF" << std::endl;
                break;
            
            default:
                this->current_state = FlowerStates::POWER_OFF;
                std::cout << "Elle a été SHUT_DOWN" << std::endl;
                break;
            }
        }
        void power_on() {
            switch (this->current_state)
            {
            case FlowerStates::POWER_OFF:
                this->current_state = FlowerStates::POWER_ON;
                std::cout << "Fleur allumée" << std::endl;
                break;
            case FlowerStates::POWER_ON:
                std::cout << "Déja POWER_ON" << std::endl;
                break;
            default:
                std::cout << "On ne peux pas la mettre en POWER_ON." << std::endl;
                break;
            }
        }
        void stand_by() {
            switch (this->current_state)
            {
            case FlowerStates::POWER_ON || FlowerStates::UNTRACK || FlowerStates::CLOSE:
                this->current_state = FlowerStates::STAND_BY;
                std::cout << "Fleu en attente du soleil" << std::endl;
                break;
            default:
                std::cout << "On ne peux pas la mettre en STAND_BY." << std::endl;
                break;
            }
        }
        void activate() {
            switch (this->current_state)
            {
            case FlowerStates::STAND_BY:
                this->current_state = FlowerStates::ACTIVATE;
                std::cout << "Fleur activée" << std::endl;
                break;
            default:
                std::cout << "On ne peux pas la mettre en ACTIVATE." << std::endl;
                break;
            }
        }
        void open() {
            switch (this->current_state)
            {
            case FlowerStates::ACTIVATE:
                this->current_state = FlowerStates::OPEN;
                std::cout << "Fleur ouverte" << std::endl;
                break;
            default:
                std::cout << "On ne peux pas la mettre en OPEN." << std::endl;
                break;
            }
        }
        void track() {
            switch (this->current_state)
            {
            case FlowerStates::OPEN || FlowerStates::STAND_BY:
                this->current_state = FlowerStates::TRACK;
                std::cout << "Fleur suit le soleil" << std::endl;
                break;
            default:
                std::cout << "On ne peux pas la mettre en UNTRACK." << std::endl;
                break;
            }
        }
        void untrack() {
            
            switch (this->current_state)
            {
            case FlowerStates::TRACK:
                this->current_state = FlowerStates::UNTRACK;
                std::cout << "Fleur a perdu le soleil" << std::endl;
                break;
            default:
                std::cout << "On ne peux pas la mettre en TRACK." << std::endl;
                break;
            }
        }
        void close() {
            switch (this->current_state)
            {
            case FlowerStates::UNTRACK:
                this->current_state = FlowerStates::CLOSE;
                std::cout << "Fleur se ferme" << std::endl;
                break;
            default:
                std::cout << "On ne peux pas la mettre en CLOSE." << std::endl;
                break;
            }
        }

        FlowerStates getState() {
            return this->current_state;
        }

};
/**
 * 
        virtual void power_off() = 0; // power_on
        virtual void power_on() = 0; // power_off, stand_by
        virtual void stand_by() = 0; // power_off, activate
        virtual void activate() = 0; // power_off, open
        virtual void open() = 0; // power_off, track
        virtual void track() = 0; // power_off, untrack
        virtual void untrack() = 0; // power_off, track, close
        virtual void close() = 0; // power_off, stand_by
 */