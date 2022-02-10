#pragma once

#include <cstdint>

enum class Instructions : std::uint8_t
{
    NOP,
    LDI,
    LDA,
    LDS,
    STA,
    STS,
    INC,
    DEC,
    PSH,
    POP,
    RET,
    HLT
};
