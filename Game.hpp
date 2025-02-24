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

        void show_help() {
        
        }

        Location random_location() {
            
        }

        std::map<std::string, void(*)(std::vector<std::string>)> setup_commands() {
            
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
        Location current_location;
        int calories;
        bool gameOver;
};



#endif