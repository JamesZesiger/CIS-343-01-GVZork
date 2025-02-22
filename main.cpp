// Jared Bradley
// 2/18/2025

#include "Item.hpp"
#include "Location.hpp"
#include "NPC.hpp"
#include <iostream>

void printInventory(std::vector<Item> inventory){
    for(auto it=inventory.begin(); it != inventory.end(); it++){
        std::cout << *it << std::endl;
    }
}

void addInventory(std::vector<Item> inventory, Item item){
    inventory.push_back(item);
}

void removeInventory(std::vector<Item> inventory, Item item){
    for(auto it=inventory.begin(); it != inventory.end(); it++){
        if(*it == item){
            inventory.erase(it);
            break;
        }
    }
}

int main(int argc, char** argv){
    //CREATE WORLD
    //Create Items
    Item Apple("Apple", "A delicious red apple", 1, 0.5);
    Item Bread("Bread", "A loaf of bread", 1, 1.0);
    
    //Create NPCs
    NPC Bob("Bob", "A normal Comp-Sci student at GV.");
    NPC Alice("Alice", "A sub-par Comp-Sci student at GV.");
    NPC Charlie("Charlie", "A Comp-Sci student at GV who is always late.");
    NPC David("David", "A Comp-Sci student at GV who is always early.");
    NPC Eve("Eve", "A Comp-Sci student at GV who is always on time.");
    //Create Locations
    
    Location Library("Library", "There's lots of books in here.")

    //Create Inventory
    std::vector<Item> inventory;


    

    Item nail("Rusty Nail", "A rusty nail (I hope you've had a tetanus shot)", 0, 1.0);
    std::cout << nail << std::endl;
    inventory.push_back(nail);
    NPC Kevin("Kevin", "A normal Comp-Sci student at GV.");
    std::cout << Kevin << std::endl;
    printInventory(inventory);
    
    std::cout << Library<< std::endl;

}
