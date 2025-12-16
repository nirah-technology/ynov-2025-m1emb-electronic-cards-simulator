#include "gamepad/Buttons.cpp"



struct Axis {
    float x = 0.0;
    float y = 0.0;
};

class JoyStick : public Button {
    private:
        Axis* axis;
    public:
        JoyStick(Axis* axis, Command* onPressedButtonCommand, Command* onReleasedButtonCommand) : Button("JoyStick", onPressedButtonCommand, onReleasedButtonCommand), axis(axis) { }

        void down() {
            this->axis->y -= 0.001;
        }

        void up() {
            this->axis->y += 0.001;
        
        }

        void left() {
            this->axis->x -= 0.001;
        }

        void right() {
            this->axis->x += 0.001;
        }

        void press() override {
            if (this->state != ButtonState::PRESSED) {
                this->state = ButtonState::PRESSED;
                this->onPressedCommand->execute();
            }
        }

        void release() override {
            if (this->state != ButtonState::RELEASED) {
                this->state = ButtonState::RELEASED;
                this->onReleasedCommand->execute();
            }
        }

};