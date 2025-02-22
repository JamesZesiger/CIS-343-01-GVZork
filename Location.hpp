// Jared Bradley
// 2/19/2025

#ifndef         __HPP__LOCATION__
#define         __HPP__LOCATION__

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <functional>
#include <map>
#include "NPC.hpp"
#include "Item.hpp"

class Location {
        public:
            Location(std::string name, std::string description) {

                this->name = name;
                this->description = description;
                this->visited = false;
            }

            void setName(std::string name) {
                this->name = name;
            }

            void setDescription(std::string description) {
                this->description = description;
            }

            std::string getName() {
                return this->name;
            }

            std::string getDescription() {
                return this->description;
            }

            std::map<string, Location> getLocations() {
                return neighbors;
            }



            friend std::ostream& operator<<(std::ostream& os, const Location& location) {
                os << location.name << " - " << location.description;
                return os;
            }


        private:
            std::string name;
            std::string description;
            bool visited;
            std::vector<NPC> npcs;
            std::vector<Item> items;
            std::map<std::string, Location> neighbors;




};

#endif

