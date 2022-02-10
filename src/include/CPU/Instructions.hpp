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
    SHL,
    SHR,
    PSH,
    POP,
    RET,
    HLT
};
