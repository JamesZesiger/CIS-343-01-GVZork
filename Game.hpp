#ifndef         __GAME_HPP__
#define         __GAME_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Item.hpp"
#include "Location.hpp"

class Game {

    public:
        Game() {
            create_world();
            this->commands = setup_commands();
            this->current_location = random_location();
            this->calories = 0;
            this->gameOver = false;

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

        } 

        void look(std::vector<std::string> target) {
            
        }

        void show_items(std::vector<std::string> target) {

        }

        void go(std::vector<std::string> target) {

        }

        void give(std::vector<std::string> target) {

        }

        void meet(std::vector<std::string> target) {

        }

        void talk(std::string target) {

        }

        void take(std::string target) {

        }

        void show_help() {
        
        }

        Location random_location() {

        }

        std::map<std::string, void(*)(std::vector<std::string>)> setup_commands() {
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("quit", &Game::quit));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("exit", &Game::quit));

            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("look", &Game::look));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("examine", &Game::look));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("inspect", &Game::look));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("search", &Game::look));

            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("show_items", &Game::show_items));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("show", &Game::show_items));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("inventory", &Game::show_items));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("inv", &Game::show_items));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("items", &Game::show_items));

            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("go", &Game::go));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("move", &Game::go));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("walk", &Game::go));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("travel", &Game::go));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("head", &Game::go));

            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("give", &Game::give));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("drop", &Game::give));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("put", &Game::give));

            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("meet", &Game::meet));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("who", &Game::meet));

            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("talk", &Game::talk));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("speak", &Game::talk));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("ask", &Game::talk));

            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("take", &Game::take));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("grab", &Game::take));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("pick", &Game::take));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("pickup", &Game::take));

            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("help", &Game::show_help));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("?", &Game::show_help));
            commands.insert(std::pair<std::string, void(*)(std::vector<std::string>)>("commands", &Game::show_help));

            return this->commands;
        }
        
        void play() {
            bool gameOver = false;

            std::cout << "Welcome to GVZORK I" << std::endl;
            std::cout << "Developed for CIS 343 at GVSU" << std::endl;
            std::cout << "Authors: Jared Bradley, Connor Valley, and James Zesiger" << std::endl;
            std::cout << "This is a text-based adventure game." << std::endl;

            std::cout << "<placeholder for starting scenario>" << std::endl;

            while (!gameOver) {
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
                std::string target;
                for (const auto& token : tokens) {
                    target += token + " ";
                }
                
                std::cout << "Processing command: " << command << " on target " << target << std::endl;
                break; // Placeholder for command processing
            }
        }

    private:
        std::map<std::string, void(*)(std::vector<std::string>)> commands;
        std::vector<Item> items;
        std::vector<Location> locations;
        int weight;
        Location current_location;
        int calories;
        bool gameOver;
};



#endif