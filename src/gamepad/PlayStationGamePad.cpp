#include "GamePad.cpp"
#include "Buttons.cpp"
#include "JoySticks.cpp"

class PlayStationGamePad : public GamePad {
    private:
        Button* x = new Button("X", nullptr, nullptr);
        Button* o = new Button("O", nullptr, nullptr);
        Button* t = new Button("T", nullptr, nullptr);
        Button* c = new Button("C", nullptr, nullptr);

        Button* r1 = new Button("R1", nullptr, nullptr);
        Button* l1 = new Button("L1", nullptr, nullptr);
        Button* r2 = new Button("R2", nullptr, nullptr);
        Button* l2 = new Button("L2", nullptr, nullptr);

        JoyStick* l3 = new JoyStick(new Axis(), nullptr, nullptr);
        JoyStick* r3 = new JoyStick(new Axis(), nullptr, nullptr);
    public:
        Button* get_button_x() { return this->x; }
        Button* get_button_o() { return this->o; }
        Button* get_button_t() { return this->t; }
        Button* get_button_c() { return this->c; }

        Button* get_button_r1() { return this->r1; }
        Button* get_button_l1() { return this->l1; }
        Button* get_button_r2() { return this->r2; }
        Button* get_button_l2() { return this->l2; }

        JoyStick* get_joystick_l3() { return this->l3; }
        JoyStick* get_joystick_r3() { return this->r3; }

        void press_c_button() {
            this->c->press();
        }


        void attach_commond_to_x(Command* command) {
            this->x->onPressedCommand = command;
        }


};
