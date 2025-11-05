#ifndef ELECTRONIC_CARD_MANUFACTURER_H
#define ELECTRONIC_CARD_MANUFACTURER_H

enum class ElectronicCardManufacturer {
    Arduino = '1',
    Raspberry = '@',
    Adafruit,
    EspressifSystem
};

bool is_arduino(const ElectronicCardManufacturer manufacturer);
char* generate_manufacturer_name(int min_length, int max_length);

#endif