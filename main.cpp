// Jared Bradley
// 2/18/2025

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

void play(std::vector<std::reference_wrapper<Item>> &itemList, std::vector<std::reference_wrapper<NPC>> &npcList, std::vector<std::reference_wrapper<Location>> &locationList, std::vector<std::reference_wrapper<Item>> &inventory, float &inventory_capacity){
    addInventory(inventory, itemList[0], inventory_capacity);
    printInventory(inventory);
    addInventory(inventory, itemList[1], inventory_capacity);
    removeInventory(inventory, itemList[0], inventory_capacity);
    printInventory(inventory);
}

void createWorld(){
    //CREATE WORLD
        std::vector<std::reference_wrapper<Item>> itemList;
    std::vector<std::reference_wrapper<NPC>> npcList;
    std::vector<std::reference_wrapper<Location>> locationList;
    //Create Items
    Item Apple("Apple", "A delicious red apple", 1, 0.5);
    Item Bread("Bread", "A loaf of bread", 1, 1.0); 
    //Create NPCs
    NPC Bob("Bob", "A normal Comp-Sci student at GV.");
    NPC Alice("Alice", "A sub-par Comp-Sci student at GV.");
    NPC Charlie("Charlie", "A Comp-Sci student at GV who is always late.");
    NPC David("David", "A Comp-Sci student at GV who is always early.");
    NPC Eve("Eve", "A Comp-Sci student at GV who is always on time.");
    NPC Elf("Elf","A magical creature that is hungry.");
    //Create Locations 
    Location Library("Library", "There's lots of books in here.");
    //Create Inventory
    std::vector<std::reference_wrapper<Item>> inventory;
    float inventory_capacity = 0;
    itemList.push_back(Apple);
    itemList.push_back(Bread); 
    npcList.push_back(Bob);
    npcList.push_back(Alice);
    npcList.push_back(Charlie);
    npcList.push_back(David);
    npcList.push_back(Eve);
    npcList.push_back(Elf);
    locationList.push_back(Library);
    play(itemList, npcList, locationList, inventory, inventory_capacity);
}



int main(int argc, char** argv){
    createWorld();    
    
}
