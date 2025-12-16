#include <iostream>

#include "Commands.cpp"

class JumpCommand : public Command {
    public:
        void execute() {
            std::cout << "Jump" << std::endl;
        }
};
