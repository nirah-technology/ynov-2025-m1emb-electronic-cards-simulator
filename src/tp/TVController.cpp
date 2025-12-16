#include <iostream>

class Command {
    public:
    virtual void execute() = 0;
};

class TVController {
    private:
        Command* command;
    public:
        void set_command(Command* command) {
            this->command = command;
        }

        void executeCommand() {
            if (this->command != nullptr) {
                this->command->execute();
            }
        }
};

// Turn On, Turn Off, Channel 1, Channel 2

class TurnOnCommand : public Command {
    private:
        TVController* tv;
    public:
        TurnOnCommand(TVController* tv) {
            this->tv = tv;
        }
        void execute() override {
            std::cout << "TV turned on" << std::endl;
        }
};

class TurnOffCommand : public Command {
    private:
        TVController* tv;
    public:
        TurnOffCommand(TVController* tv) {
            this->tv = tv;
        }
        void execute() override {
            std::cout << "TV turned off" << std::endl;
        }
};

class Channel1Command : public Command {
    private:
        TVController* tv;
    public:
        Channel1Command(TVController* tv) {
            this->tv = tv;
        }
        void execute() override {
            std::cout << "Channel 1" << std::endl;
        }
};

class Channel2Command : public Command {
    private:
        TVController* tv;
    public:
        Channel2Command(TVController* tv) {
            this->tv = tv;
        }
        void execute() override {
            std::cout << "Channel 2" << std::endl;
        }
};

class TeleCommand {
    private:
        TVController tv;
    public:
        TeleCommand() : tv() {
            
        }
        void powerOn() {
            this->tv.set_command(new TurnOnCommand(&this->tv));
            this->tv.executeCommand();
        }
        void powerOff() {
            this->tv.set_command(new TurnOffCommand(&this->tv));
            this->tv.executeCommand();
        }
        void channel1() {
            this->tv.set_command(new Channel1Command(&this->tv));
            this->tv.executeCommand();
        }
        void channel2() {
            this->tv.set_command(new Channel2Command(&this->tv));
            this->tv.executeCommand();
        }
};