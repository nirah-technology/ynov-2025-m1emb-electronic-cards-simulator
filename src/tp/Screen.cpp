#include <iostream>

class PortVGA {
    public:
        virtual void display_using_vga() {
            std::cout << "Je suis un HDMI" << std::endl;
        }
};

class HDMI {
    public:
        void display_using_hdmi() {
            std::cout << "Je suis un VGA" << std::endl;
        }
};


class Screen {
    private:
        HDMI* hdmi;
    public:
        Screen() {
            this->hdmi = new HDMI();
        }

        void display() {
            this->hdmi->display_using_hdmi();
        }
};

class PC {
    public:
        PortVGA* vga;
        PC(PortVGA* vga) {
            this->vga = vga;
        }

        void display() {
            this->vga->display_using_vga();
        }
};

class HDMIToVGADisplayAdapter : public PortVGA {
    private:
        Screen* screen;
    public:
        HDMI* displayPort;
        HDMIToVGADisplayAdapter(Screen* screen) {
            this->screen = screen;
        }
        void display_using_vga() override {
            this->screen->display();
        }
        
};