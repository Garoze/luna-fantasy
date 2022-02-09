#include <iostream>

#include "include/Bus/Bus.hpp"

int main()
{
    Bus bus;
    bus.writeDataBus(0x0010, 0xFF);
    bus.writeDataBus(0x0011, 0xFB);

    auto value1 = bus.readDataBus(0x10);
    auto value2 = bus.readDataBus(0x11);

    printf("Value from Bus: %04X\n", value1 << 8 | value2);

    return EXIT_SUCCESS;
}
