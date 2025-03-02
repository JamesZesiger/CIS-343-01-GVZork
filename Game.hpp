// Authors: Jared Bradley, Connor Valley, and James Zesiger
// 2/20/25

#ifndef         __GAME_HPP__
#define         __GAME_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>
#include "Item.hpp"
#include "Location.hpp"
#include "NPC.hpp"

class Game {

    public:
        Game() {
            create_world();
            this->commands = setup_commands();
            this->calories = 500;
            this->gameOver = false;
            this-> current_location = random_location();
        }

        void create_world() {
            //CREATE WORLD

            //Create Items
            Item Apple("Apple", "A delicious red apple", 1, 0.5);
            Item Bread("Bread", "A loaf of bread", 1, 1.0);
            Item LoMein("Lo Mein", "A cup of lo mein from Panda Express", 1, 2.0);
            Item Stick("Stick", "A regular wooden stick", 0, 1.0);
            Item Anvil("Anvil", "An iron anvil", 0, 50.0);
            Item Turkey_Leg("Turkey Leg", "A delicious Turkey Leg", 10, 3.0);
            Item Rusty_Nail("Rusty Nail", "A Rusty Nail, (I hope you had your tetanus shot)", 0, 1.0);
            Item Fruit_Snacks("Fruit Snacks", "A package of assorted fruit snacks", 5, 1.0);
            Item Banana("Banana", "A great source of potassium", 5, 3.0);
            Item Steak("Steak", "A tasty hunk of beef", 15, 5.0);
            Item Pizza("Pizza", "A simple peperoni pizza", 10, 4.0);

            //Create NPCs
            NPC Bob("Bob", "A normal Comp-Sci student at GV.");
            NPC Alice("Alice", "A sub-par Comp-Sci student at GV.");
            NPC Charlie("Charlie", "A Comp-Sci student at GV who is always late.");
            NPC David("David", "A Comp-Sci student at GV who is always early.");
            NPC Eve("Eve", "A Comp-Sci student at GV who is always on time.");
            NPC Elf("Elf","A magical creature that is hungry.");

            //Set NPC messages
            Bob.setMessage("Bob: Hi, I'm Bob. I'm a Comp-Sci student at GV.");
            Eve.setMessage("Eve: Hi, I'm Eve. I'm a Comp-Sci student at GV. I love the Kirkoff Center!");

            //Create Locations  
            Location Library("Library", "There's lots of books in here.");
            Location Kirkoff("Kirkoff Center", "Student Union, there is a restaurant, a coffee shop, and study spaces.");
            Location Padnos("Padnos Hall", "There are many classrooms here.");
            Location Rec_Center("Recreation Center", "There is a pool, a gym, and basketball courts here.");
            Location Forest("Forest", "It is magical and full of life.");
            Location Cafeteria("Cafeteria", "It smells like moldy cheese in here.");
            Location Manitou("Manitou", "There's a lot of printers in here.");
            Location Mackinac("Mackinac", "There are lots of whiteboards with math equations.");

            //Add items to locations
            Library.addItem(Apple);
            Kirkoff.addItem(LoMein);
            Padnos.addItem(Bread);
            Cafeteria.addItem(Steak);
            Manitou.addItem(Banana);
            Mackinac.addItem(Anvil);
            Forest.addItem(Stick);
            Rec_Center.addItem(Fruit_Snacks);
            Forest.addItem(Rusty_Nail);
            Cafeteria.addItem(Turkey_Leg);
            Kirkoff.addItem(Pizza);

            //Add NPCs to locations
            Library.addNPC(Bob);
            Library.addNPC(Alice);
            Forest.addNPC(Elf);
            Rec_Center.addNPC(Charlie);
            Padnos.addNPC(David);
            Padnos.addNPC(Eve);
            
            
            this->locations.push_back(Library);
            this->locations.push_back(Kirkoff);
            this->locations.push_back(Padnos);
            this->locations.push_back(Rec_Center);
            this->locations.push_back(Forest);
            this->locations.push_back(Cafeteria);
            this->locations.push_back(Manitou);
            this->locations.push_back(Mackinac);
            this->locations[0].addLocation("north", std::reference_wrapper<Location>(locations[1]));
            this->locations[1].addLocation("south",  std::reference_wrapper<Location>(locations[0]));
            this->locations[1].addLocation("east",  std::reference_wrapper<Location>(locations[2]));
            this->locations[1].addLocation("north", std::reference_wrapper<Location>(locations[7]));
            this->locations[1].addLocation("west", std::reference_wrapper<Location>(locations[5]));
            this->locations[2].addLocation("west",  std::reference_wrapper<Location>(locations[1]));
            this->locations[2].addLocation("north",  std::reference_wrapper<Location>(locations[3]));
            this->locations[3].addLocation("south",  std::reference_wrapper<Location>(locations[2]));
            this->locations[3].addLocation("east",  std::reference_wrapper<Location>(locations[4]));
            this->locations[3].addLocation("west",  std::reference_wrapper<Location>(locations[7]));
            this->locations[4].addLocation("west",  std::reference_wrapper<Location>(locations[3]));
            this->locations[5].addLocation("east",  std::reference_wrapper<Location>(locations[1]));
            this->locations[5].addLocation("north",  std::reference_wrapper<Location>(locations[6]));
            this->locations[6].addLocation("south",  std::reference_wrapper<Location>(locations[5]));
            this->locations[6].addLocation("east",  std::reference_wrapper<Location>(locations[7]));
            this->locations[7].addLocation("east",  std::reference_wrapper<Location>(locations[3]));
            this->locations[7].addLocation("west",  std::reference_wrapper<Location>(locations[6]));
            this->locations[7].addLocation("south",  std::reference_wrapper<Location>(locations[1]));
   
        }

        void quit() {
            std::cout << "Goodbye!" << std::endl;
            gameOver = true;
        } 

        void look(std::vector<std::string> target) {
            std::cout << current_location << std::endl;
        }

        void show_items(std::vector<std::string> target) {
            if (items.size() > 0){
                for (int i = 0; i < items.size(); i++){
                    std::cout << items[i] << std::endl;
                }
            }
            else{
                std::cout << "Inventory is empty." << std::endl;
            }
        }

        void go(std::vector<std::string> target) {
            std::map<std::string, Location> neighbors = current_location.get_Locations();   
                if (neighbors.find(toLowercase(target[0])) != neighbors.end()) {
                    for(int i=0; i<locations.size(); i++){
                        std::string name = neighbors.at(target[0]).getName();
                        if(locations[i].getName() == name){
                            locations[i].setVisited();
                            for (int x = 0; x < locations.size(); x++){
                                locations[x].updateLocation(locations[i]);
                            }
                            
                            current_location = locations[i];
                            std::cout << current_location << std::endl;
                            
                            return;
                        }
                    }
            }

            std::cout << "You can't go that way." << std::endl;
        }

        void give(std::vector<std::string> target) {
           for (auto item : items) {
                std::string name = item.getName();
                if (toLowercase(name) == toLowercase(target[0])) {
                    current_location.addItem(item);
                    if (current_location.getName() == "Forest"){
                        std::cout << "You gave the Elf a " << item.getName() << std::endl;
                        calories -= item.getCalories();
                        if (calories <= 0){
                            std::cout << "The elf is full" << std::endl;
                            quit();
                        }
                        else{
                            std::cout << "The elf needs " << calories << " more calories" << std::endl;
                        }
                    }
                        
                    for (int x = 0; x < locations.size(); x++){
                        if (locations[x].getName() == current_location.getName()){
                            locations[x].addItem(item);
                        }
                    }
                    for(int i = 0; i < items.size(); i++) {
                        if (items[i].getName() == item.getName()) {
                            items.erase(items.begin() + i);
                        }
                    }
                    std::cout << "You dropped " << item.getName() << std::endl;
                }
                else {
                    std::cout << "You don't have that item." << std::endl;
                }     

            }
            
        }

        void meet(std::vector<std::string> target) {
            std::cout << "You meet " << target[0] << std::endl;
        }

        void talk(std::vector<std::string> target) {
            std::vector<NPC> npcs = current_location.getNPCs();
            for (auto npc : npcs) {
                std::string npc_name = npc.getName();
                for (auto word : target) {
                    if (toLowercase(word) == toLowercase(npc_name)) {
                        std::cout << npc.getMessage() << std::endl;
                        return;
                    }
                }
            }
            std::cout << "You don't see that person here." << std::endl;
        }

        void take(std::string target) {
           for (int x = 0; x < locations.size(); x++){
            if (locations[x].getName() == current_location.getName()){
                std::vector<Item> loc_items = locations[x].getItems();
                bool found = false;
                for (int i = 0; i < loc_items.size(); i++){
                    std::string name = loc_items[i].getName();
                    if (toLowercase(name) == toLowercase(target)){
                        items.push_back(loc_items[i]);
                        locations[x].removeItem(loc_items[i]);
                        current_location.removeItem(loc_items[i]);
                        found = true;
                        std::cout << "You picked up " << target << std::endl;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "You can't take that item." << std::endl;
                }
            }
        }

    }

        void show_help() {
            std::cout << "Available commands:" << std::endl;
            for (const auto& command : commands) {
                std::cout << command.first << std::endl;
            }
            std::cout << "Type 'help' for a list of commands." << std::endl;
            std::cout << "Type 'quit' or 'exit' to quit the game." << std::endl;
            std::cout << "Type 'look' to look around." << std::endl;
            std::cout << "Type 'show_items' to show your items." << std::endl;
            std::cout << "Type 'go' to go to a location." << std::endl;
            std::cout << "Type 'give' to give an item to a NPC." << std::endl;
            std::cout << "Type 'meet' to meet a NPC." << std::endl;
        }

        Location random_location() {
            std::mt19937 engine (std::random_device{}());
            std::uniform_int_distribution<int> dist(0, locations.size() - 1);
            int random_index = dist(engine);
            locations[random_index].setVisited();
            for (int x = 0; x < locations.size(); x++){
                locations[x].updateLocation(locations[random_index]);
            }
            return locations[random_index];
        }

        std::map<std::string, std::function<void(std::vector<std::string>)>> setup_commands() {
            std::map<std::string, std::function<void(std::vector<std::string>)>> commands;
            commands["quit"] = [this](std::vector<std::string> target) { quit(); };
            commands["exit"] = [this](std::vector<std::string> target) { quit(); };

            commands["look"] = [this](std::vector<std::string> target) { look(target); };
            commands["examine"] = [this](std::vector<std::string> target) { look(target); };
            commands["inspect"] = [this](std::vector<std::string> target) { look(target); };
            commands["search"] = [this](std::vector<std::string> target) { look(target); };

            commands["show_items"] = [this](std::vector<std::string> target) { show_items(target); };
            commands["inventory"] = [this](std::vector<std::string> target) { show_items(target); };
            commands["show"] = [this](std::vector<std::string> target) { show_items(target); };
            commands["items"] = [this](std::vector<std::string> target) { show_items(target); };

            commands["go"] = [this](std::vector<std::string> target) { go(target); };
            commands["move"] = [this](std::vector<std::string> target) { go(target); };
            commands["travel"] = [this](std::vector<std::string> target) { go(target); };
            commands["walk"] = [this](std::vector<std::string> target) { go(target); };
            commands["head"] = [this](std::vector<std::string> target) { go(target); };

            commands["give"] = [this](std::vector<std::string> target) { give(target); };
            commands["drop"] = [this](std::vector<std::string> target) { give(target); };

            commands["meet"] = [this](std::vector<std::string> target) { meet(target); };
            commands["who"] = [this](std::vector<std::string> target) { meet(target); };


            commands["talk"] = [this](std::vector<std::string> target) { talk(target); };
            commands["speak"] = [this](std::vector<std::string> target) { talk(target); };
            commands["ask"] = [this](std::vector<std::string> target) { talk(target); };
            commands["chat"] = [this](std::vector<std::string> target) { talk(target); };

            commands["take"] = [this](std::vector<std::string> target) { take(target[0]); };
            commands["grab"] = [this](std::vector<std::string> target) { take(target[0]); };
            commands["pick_up"] = [this](std::vector<std::string> target) { take(target[0]); };
            commands["pick"] = [this](std::vector<std::string> target) { take(target[0]); };


            commands["help"] = [this](std::vector<std::string> target) { show_help(); };
            commands["commands"] = [this](std::vector<std::string> target) { show_help(); };
            commands["?"] = [this](std::vector<std::string> target) { show_help(); };

            return commands;
        }
            
        
        void play() {
            // std::cout << "Welcome to GVZORK I" << std::endl;
            printASCIIart();

            std::cout << "Developed for CIS 343 at GVSU" << std::endl;
            std::cout << "Authors: Jared Bradley, Connor Valley, and James Zesiger" << std::endl;
            std::cout << "This is a text-based adventure game." << std::endl;

	        std::cout << this->current_location << std::endl;
            current_location.setVisited();

            while (!this->gameOver) {
                // Game loop
                std::string input;
                std::cout << "> ";
                std::getline(std::cin, input);

                // Process command
                std::vector<std::string> tokens;
                size_t start = 0;

                for (size_t i = 0; i < input.length(); ++i) {
                    if (input[i] == ' ') {
                        tokens.push_back(input.substr(start, i - start)); 
                        start = i + 1;
                    } else if (i == input.length() - 1) {
                        tokens.push_back(input.substr(start, i - start + 1)); 
                    }
                }

                std::string command = tokens[0];
                tokens.erase(tokens.begin()); // Remove the command from the tokens
                if (tokens.size() > 1) {
                    for (int x = 1; x < tokens.size(); x++){
                        tokens[0] += " " + tokens[1];
                        tokens.erase(tokens.begin() + 1);
                    }
                }
                if (commands.find(command) != commands.end()) {
                    commands[command](tokens);
                } else {
                    std::cout << "Invalid command." << std::endl;
                }
            }
        }

    private:
        std::vector<Item> items;
        std::map<std::string, std::function<void(std::vector<std::string>)>> commands;
        std::vector<Location> locations;
    
        Location current_location = Location("tmp", "tmp");
        int weight;
        int calories;
        bool gameOver;

        std::string toLowercase(std::string& str) {
            for (auto& c : str) {
                c = tolower(c);
            }
            return str;
        }

        void printASCIIart() {
            // ASCII art made using https://patorjk.com/
            std::cout << "888       888          888                                                   888            " << std::endl;
            std::cout << "888   o   888          888                                                   888            " << std::endl;
            std::cout << "888  d8b  888          888                                                   888            " << std::endl;
            std::cout << "888 d888b 888  .d88b.  888  .d8888b .d88b.  88888b.d88b.   .d88b.            888888 .d88b.  " << std::endl;
            std::cout << "888d88888b888 d8P  Y8b 888 d88P'   d88''88b 888 '888 '88b d8P  Y8b           888   d88''88b " << std::endl;
            std::cout << "88888P Y88888 88888888 888 888     888  888 888  888  888 88888888           888   888  888 " << std::endl;
            std::cout << "8888P   Y8888 Y8b.     888 Y88b.   Y88..88P 888  888  888 Y8b.               Y88b. Y88..88P " << std::endl;
            std::cout << "888P     Y888  'Y8888  888  'Y8888P 'Y88P'  888  888  888  '8888             'Y888 'Y88P'   " << std::endl;                                                                                           
            std::cout << "                                                                                            " << std::endl;                                                                                        
                                                                                                        
            std::cout << ".d8888b.  888     888      8888888888P  .d88888b.  8888888b.  888    d8P                    " << std::endl;
            std::cout << "d88P  Y88b 888     888            d88P  d88P' 'Y88b 888   Y88b 888   d8P                    " << std::endl;
            std::cout << "888    888 888     888           d88P   888     888 888    888 888  d8P                     " << std::endl;
            std::cout << "888        Y88b   d88P          d88P    888     888 888   d88P 888d88K                      " << std::endl;
            std::cout << "888  88888  Y88b d88P          d88P     888     888 8888888P'  8888888b                     " << std::endl;
            std::cout << "888    888   Y88o88P          d88P      888     888 888 T88b   888  Y88b                    " << std::endl;
            std::cout << "Y88b  d88P    Y888P          d88P       Y88b. .d88P 888  T88b  888   Y88b                   " << std::endl;
            std::cout << "'Y8888P88     Y8P          d8888888888  'Y88888P'  888   T88b 888    Y88b                   " << std::endl; 
            std::cout << "                                                                                            " << std::endl;
        }
};

#endif
