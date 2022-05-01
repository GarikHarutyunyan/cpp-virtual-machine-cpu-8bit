#include <iostream>
#include <string>
#include "common.h"
#include "Utils.h"
#include "Alu.h"
#include "Cpu.h"

int main()
{
    Alu alu;
    Cpu cpu;
    std::string m;
    std::bitset<8> a;
    std::cout << "Enter input value(number): ";
    std::cin >> m;
    a = std::stoi(m);
    std::cout << "Input * 6 = " << Utils::binaryToInt(cpu.run(a)) << std::endl;
}