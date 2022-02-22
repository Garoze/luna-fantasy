#pragma once

#include <map>
#include <string>

#include "Instructions.hpp"

static const std::map<Instructions, std::string> Mnemonic_t = {
    std::make_pair(Instructions::NOP, "NOP"),
    std::make_pair(Instructions::LDI, "LDI"),
    std::make_pair(Instructions::LDA, "LDA"),
    std::make_pair(Instructions::LDS, "LDS"),
    std::make_pair(Instructions::LDR, "LDR"),
    std::make_pair(Instructions::STA, "STA"),
    std::make_pair(Instructions::STR, "STR"),
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
    std::make_pair(Instructions::PSA, "PSA"),
    std::make_pair(Instructions::PSI, "PSI"),
    std::make_pair(Instructions::PSR, "PSR"),
    std::make_pair(Instructions::POA, "POA"),
    std::make_pair(Instructions::POR, "POR"),
    std::make_pair(Instructions::CMP, "CMP"),
    std::make_pair(Instructions::CMA, "CMA"),
    std::make_pair(Instructions::CMS, "CMS"),
    std::make_pair(Instructions::JMP, "JMP"),
    std::make_pair(Instructions::JMZ, "JMZ"),
    std::make_pair(Instructions::JNZ, "JNZ"),
    std::make_pair(Instructions::CAL, "CAL"),
    std::make_pair(Instructions::RET, "RET"),
    std::make_pair(Instructions::OUT, "OUT"),
    std::make_pair(Instructions::HLT, "HLT"),
};
