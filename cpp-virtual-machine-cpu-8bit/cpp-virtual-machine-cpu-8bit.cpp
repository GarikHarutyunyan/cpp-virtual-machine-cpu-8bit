#include <iostream>
#include "common.h"
#include "Utils.h"
#include "Alu.h"
#include "Cpu.h"

int main()
{
    Alu alu;

    std::bitset<8> inst("00000101");
    std::bitset<8> a(8);
    std::bitset<8> b(-2);
    /*std::bitset<8> c = ~(a&b);*/
    std::cout << a <<std::endl;
    Cpu cpu;
    std::cout << cpu.run(a) << std::endl;
    //std::cout << b << std::endl;
    //std::cout << alu.run(inst,a,b)  << std::endl;
}