#pragma once

#include <map>
#include <string>
#include <cstdint>
#include <utility>

enum class Instructions : std::uint8_t
{
    NOP,
    LDI, LDA, LDS,
    STA, STS,
    ADD, ADA, ADS,
    SUB, SUA, SUS,
    MUL, MUA, MUS,
    DIV, DIA, DIS,
    MOD, MOA, MOS,
    INC, DEC,
    SHL, SHR, AND,
    BOR, XOR, NOT,
    PSH, POP,
    CMP, CMA, CMS,
    JMP, CAL, RET,
    OUT,
    HLT
};

static const std::map<Instructions, std::string> Instruction_t = {
    std::make_pair(Instructions::NOP, "NOP"),
    std::make_pair(Instructions::LDI, "LDI"),
    std::make_pair(Instructions::LDA, "LDA"),
    std::make_pair(Instructions::LDS, "LDS"),
    std::make_pair(Instructions::STA, "STA"),
    std::make_pair(Instructions::STS, "STS"),
    std::make_pair(Instructions::ADD, "ADD"),
    std::make_pair(Instructions::ADA, "ADA"),
    std::make_pair(Instructions::ADS, "ADS"),
    std::make_pair(Instructions::SUB, "SUB"),
    std::make_pair(Instructions::SUA, "SUA"),
    std::make_pair(Instructions::SUS, "SUS"),
    std::make_pair(Instructions::MUL, "MUL"),
    std::make_pair(Instructions::MUA, "MUA"),
    std::make_pair(Instructions::MUS, "MUS"),
    std::make_pair(Instructions::DIV, "DIV"),
    std::make_pair(Instructions::DIA, "DIA"),
    std::make_pair(Instructions::DIS, "DIS"),
    std::make_pair(Instructions::MOD, "MOD"),
    std::make_pair(Instructions::MOA, "MOA"),
    std::make_pair(Instructions::MOS, "MOS"),
    std::make_pair(Instructions::INC, "INC"),
    std::make_pair(Instructions::DEC, "DEC"),
    std::make_pair(Instructions::SHL, "SHL"),
    std::make_pair(Instructions::SHR, "SHR"),
    std::make_pair(Instructions::AND, "AND"),
    std::make_pair(Instructions::BOR, "BOR"),
    std::make_pair(Instructions::XOR, "XOR"),
    std::make_pair(Instructions::NOT, "NOT"),
    std::make_pair(Instructions::PSH, "PSH"),
    std::make_pair(Instructions::POP, "POP"),
    std::make_pair(Instructions::CMP, "CMP"),
    std::make_pair(Instructions::CMA, "CMA"),
    std::make_pair(Instructions::CMS, "CMS"),
    std::make_pair(Instructions::JMP, "JMP"),
    std::make_pair(Instructions::CAL, "CAL"),
    std::make_pair(Instructions::RET, "RET"),
    std::make_pair(Instructions::OUT, "OUT"),
    std::make_pair(Instructions::HLT, "HLT"),
};
