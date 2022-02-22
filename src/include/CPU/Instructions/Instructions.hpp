#pragma once

#include <map>
#include <string>
#include <cstdint>
#include <utility>

enum class Instructions : std::uint8_t
{
    NOP,
    LDI, LDA, LDS, LDR,
    STA, STR, STS,
    ADD, ADA, ADS,
    SUB, SUA, SUS,
    MUL, MUA, MUS,
    DIV, DIA, DIS,
    MOD, MOA, MOS,
    INC, DEC,
    SHL, SHR, AND,
    BOR, XOR, NOT,
    PSA, PSI, PSR,
    POA, POR,
    CMP, CMA, CMS,
    JMP, JMZ, JNZ,
    CAL, RET,
    OUT,
    HLT
};

