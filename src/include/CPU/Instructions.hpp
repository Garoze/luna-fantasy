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
    ADD,
    ADA,
    ADS,
    SUB,
    SUA,
    SUS,
    DIV,
    DIA,
    DIS,
    INC,
    DEC,
    SHL,
    SHR,
    AND,
    BOR,
    XOR,
    NOT,
    PSH,
    POP,
    RET,
    HLT
};
