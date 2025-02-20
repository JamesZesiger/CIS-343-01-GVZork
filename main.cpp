// Jared Bradley
// 2/18/2025

#include "Item.hpp"
#include "NPC.hpp"
#include <iostream>

int main(int argc, char** argv){
    Item nail("Rusty Nail", "A rusty nail (I hope you've had a tetanus shot)", 0, 1.0);
    std::cout << nail << std::endl;

    NPC Kevin("Kevin", "A normal Comp-Sci student at GV.");
    std::cout << Kevin << std::endl;
}
