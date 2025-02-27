#ifndef         __GAME_HPP__
#define         __GAME_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Item.hpp"
#include "Location.hpp"
#include "NPC.hpp"

class Game {

    public:
        Game() {
            create_world();
            this->commands = setup_commands();
            this->calories = 0;
            this->gameOver = false;
            this-> current_location = random_location();
        }

        void create_world() {
            //CREATE WORLD

            //Create Items
            Item Apple("Apple", "A delicious red apple", 1, 0.5);
            Item Bread("Bread", "A loaf of bread", 1, 1.0);
            Item LoMein("Lo Mein", "A cup of lo mein from Panda Express", 1, 2.0);

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
            Location Kirkoff_one("Kirkoff Main Level", "Student Union, there is a restaurant, \
                a coffee shop, and study spaces.\
                 There are stairs to the second floor.");
            Location Kirkoff_two("Kirkoff Second Floor", "There are large rooms and study spaces here.");
            Location Padnos("Padnos Hall", "There are many classrooms here.");
            Location Rec_Center("Recreation Center", "There is a pool, a gym, and basketball courts here.");

            //Add items to locations
            Library.addItem(Apple);
            Kirkoff_one.addItem(LoMein);
            Padnos.addItem(Bread);

            //Add NPCs to locations
            Library.addNPC(Bob);
            Library.addNPC(Alice);
            Kirkoff_one.addNPC(Elf);
            Rec_Center.addNPC(Charlie);
            Padnos.addNPC(David);
            Padnos.addNPC(Eve);
            
            
            this->locations.push_back(Library);
            this->locations.push_back(Kirkoff_one);
            this->locations.push_back(Kirkoff_two);
            this->locations.push_back(Padnos);
            this->locations.push_back(Rec_Center);

        }

        void quit() {
            std::cout << "Goodbye!" << std::endl;
            gameOver = true;
        } 

        void look(std::vector<std::string> target) {
            std::cout << current_location << std::endl;
        }

        void show_items(std::vector<std::string> target) {
            std::cout << "You have the following items:" << std::endl;
        }

        void go(std::vector<std::string> target) {
            std::cout << "You go to " << target[0] << std::endl;
        }

        void give(std::vector<std::string> target) {
            std::cout << "You give " << target[0] << " to " << target[0] << std::endl;
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
            std::cout << "You take " << target << std::endl;
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
            return locations[rand() % locations.size()];
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
            std::cout << "Welcome to GVZORK I" << std::endl;
            std::cout << "Developed for CIS 343 at GVSU" << std::endl;
            std::cout << "Authors: Jared Bradley, Connor Valley, and James Zesiger" << std::endl;
            std::cout << "This is a text-based adventure game." << std::endl;

	    std::cout << this->current_location << std::endl;

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
};

#endif
