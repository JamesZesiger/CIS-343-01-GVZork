// Jared Bradley
// 2/19/2025

#ifndef         __HPP__LOCATION__
#define         __HPP__LOCATION__

#include <memory>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
#include "NPC.hpp"
#include "Item.hpp"

class Location {
        public:
            Location(std::string name, std::string description) {
                if (name.empty()) {
                    throw std::invalid_argument("Name cannot be blank.");
                }

                if (description.empty()) {
                    throw std::invalid_argument("Description cannot be blank.");
                }

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

            std::map<std::string, Location> get_Locations() {
                return neighbors;
            }

            void addLocation(std::string direction, Location location) {
                if (direction.empty()) {
                    throw std::invalid_argument("Direction cannot be blank.");
                }

                if (neighbors.find(direction) != neighbors.end()) {
                    throw std::invalid_argument("Location already exists in that direction.");
            }

                neighbors.insert(std::pair<std::string, Location>(direction, location));
            }
            
            void updateLocation(Location location) {
                for(auto& neighbor : neighbors) {
                    if (neighbor.second.getName() == location.getName()) {
                        neighbor.second = location;
                    }
                }
                          
            }

            void addNPC(NPC npc) {
                npcs.push_back(npc);
            }

            std::vector<NPC> getNPCs() {
                return npcs;
            }

            void addItem(Item item) {
                items.push_back(item);
            }

            void removeItem(Item item) {
                for(int i = 0; i < items.size(); i++) {
                    if (items[i].getName() == item.getName()) {
                        items.erase(items.begin() + i);
                        return;
                    }
                }
            }
            
            std::vector<Item> getItems() {
                return items;
            }

            void setVisited() {
                this->visited = true;
            }

            bool getVisited() {
                return this->visited;
            }


            friend std::ostream& operator<<(std::ostream& os, const Location& location) {
                os << location.name << " - " << location.description << "\n";
                
                if (!location.npcs.empty()) {
                    os << "You see the following NPCs:\n";
                    for (auto npc : location.npcs) {
                        os << "- " << npc.getName() << "\n";
                    }
                }

                if (!location.items.empty()) {
                    os << "You see the following Items:\n";
                    for (auto item : location.items) {
                        os << "- " << item.getName() << " (" << item.getCalories() << " calories) - " << item.getWeight() << " lbs - " << item.getDescription() << ".\n";
                    }
                }

                os << "You can go in the following directions:\n";

                for (auto neighbor : location.neighbors) {
                    os << "- " << neighbor.first;
                    if (neighbor.second.getVisited()) {
                        os << " - " << neighbor.second.getName() << " (You have visited this location before.)\n";
                    } else {
                        os << " - Unknown\n";
                    }
                }

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