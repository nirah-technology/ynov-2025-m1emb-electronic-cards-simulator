#include <iostream>
#include <string>

#include "Commands.cpp"

enum ButtonState {
    PRESSED,
    RELEASED
};

class Button {
    protected:
        std::string name;
        ButtonState state;
        
        public:
        Command* onPressedCommand;
        Command* onReleasedCommand;
        Button(std::string name, Command* onPressedCommand, Command* onReleasedCommand) :
            name(name),
            state(ButtonState::RELEASED),
            onPressedCommand(onPressedCommand),
            onReleasedCommand(onReleasedCommand) {
        }

        std::string getName() {
            return this->name;
        }

        virtual void press() {
            if (this->state != ButtonState::PRESSED && this->onPressedCommand) {
                this->state = ButtonState::PRESSED;
                this->onPressedCommand->execute();
            }
        }

        virtual void release() {
            if (this->state != ButtonState::RELEASED && this->onReleasedCommand) {
                this->state = ButtonState::RELEASED;
                this->onReleasedCommand->execute();
            }
        }
};

/* This part was moved to the .cpp file to hide implementation details */
Button::Button(std::string name, Command* onPressedCommand, Command* onReleasedCommand) :
            name(name),
            state(ButtonState::RELEASED),
            onPressedCommand(onPressedCommand) {
        }

std::string Button::getName() { return this->name; }

void Button::press() {
    if (this->state != ButtonState::PRESSED && this->onPressedCommand) {
        this->state = ButtonState::PRESSED;
        this->onPressedCommand->execute();
    }
}

void Button::release() {
    if (this->state != ButtonState::RELEASED && this->onReleasedCommand) {
        this->state = ButtonState::RELEASED;
        this->onReleasedCommand->execute();
    }
}

class CrossButton {
    private:
        Button* top_button;
        Button* bottom_button;
        Button* left_button;
        Button* right_button;
    public:
        CrossButton(
            Command* onToButtonPressedCommand,
            Command* onTopButtonReleasedCommand,
            Command* onBottomButtonPressedCommand,
            Command* onBottomButtonReleasedCommand,
            Command* onLeftButtonPressedCommand,
            Command* onLeftButtonReleasedCommand,
            Command* onRightButtonPressedCommand,
            Command* onRightButtonReleasedCommand
        ) :
            top_button(new Button("Top", onToButtonPressedCommand, onTopButtonReleasedCommand)),
            bottom_button(new Button("Bottom", onBottomButtonPressedCommand, onBottomButtonReleasedCommand)),
            left_button(new Button("Left", onLeftButtonPressedCommand, onLeftButtonReleasedCommand)),
            right_button(new Button("Right", onRightButtonPressedCommand, onRightButtonReleasedCommand)) {

        }

        ~CrossButton() {
            delete top_button;
            delete bottom_button;
            delete left_button;
            delete right_button;
        }

        Button* getTopButton() {
            return this->top_button;
        }

        Button* getBottomButton() {
            return this->bottom_button;
        }

        Button* getLeftButton() {
            return this->left_button;
        }

        Button* getRightButton() {
            return this->right_button;
        }

};
