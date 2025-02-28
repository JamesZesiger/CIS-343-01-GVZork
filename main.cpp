// Authors: Jared Bradley, Connor Valley, and James Zesiger
// 2/18/2025

#include "Game.hpp"
#include "Item.hpp"
#include "Location.hpp"
#include "NPC.hpp"
#include <iostream>
#include <algorithm>

void printInventory(std::vector<std::reference_wrapper<Item>> inventory){
    if (inventory.size() > 0){
        for (int i = 0; i < inventory.size(); i++){
            std::cout << inventory[i].get().getName() << std::endl;
        }
    }
    else{
        std::cout << "Inventory is empty." << std::endl;
    }
}

void addInventory(std::vector<std::reference_wrapper<Item>> &inv, Item item, float capacity){
    if ((capacity + item.getWeight())  < 30){
        inv.push_back(item);
        capacity += item.getWeight();
        std::cout << item.getName() + " added to inventory" << std::endl;
    }
    else{
        std::cout << "Inventory is full." << std::endl;
    }
}

void removeInventory(std::vector<std::reference_wrapper<Item>> &inv, Item &item, float capacity){
    for (int i = 0; i < inv.size(); i++){
        if (inv[i].get().getName() == item.getName()){
            inv.erase(inv.begin() + i);
            capacity -= item.getWeight();
            std::cout << item.getName() + " removed from inventory" << std::endl;
            return;
        }   
    }
    std::cout << item.getName() + " not found in inventory" << std::endl;
}

int main(int argc, char** argv){

    Game game;
    game.create_world();
    game.play();

    return 0;
}
