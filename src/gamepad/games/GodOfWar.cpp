#include <iostream>

#include "gamepad/Commands.cpp"


class JumpCommand : public Command {
    public:
    void execute() override {
        std::cout << "Jump" << std::endl;
    }
};