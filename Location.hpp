/*
* Authors: Jared Bradley, Connor Valley, and James Zesiger
* Date: 2/20/25
* Description: Header for Loaction class
*/ 

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
            // Default constructor
            Location(std::string name, std::string description) {
                // Error handeling for empty name
                if (name.empty()) {
                    throw std::invalid_argument("Name cannot be blank.");
                }
                // Error handeling for empty description
                if (description.empty()) {
                    throw std::invalid_argument("Description cannot be blank.");
                }

                this->name = name;
                this->description = description;
                this->visited = false;
            }

            void setName(std::string name) {
                /*
                * Setter for name of the location
                * Parameters: name - string
                * Returns: None
                */
                this->name = name;
            }

            void setDescription(std::string description) {
                /*
                * Setter for description of the location
                * Parameters: description - string
                * Returns: None
                */
                this->description = description;
            }

            std::string getName() {
                /*
                * Getter for location name
                * Parameters: None
                * Returns: string
                */
                return this->name;
            }

            std::string getDescription() {
                /*
                * Getter for location description
                * Parameters: None
                * Returns: string
                */
                return this->description;
            }

            std::map<std::string, Location> get_Locations() {
                /*
                * Getter for neighbors map
                * Parameters: None
                * Returns: map<string, Location>
                */
                return neighbors;
            }

            void addLocation(std::string direction, Location location) {
                /*
                * Method that adds a location to the neighbors map
                * Parameters: direction - string, location - Location
                * Returns: None
                */
                if (direction.empty()) {
                    throw std::invalid_argument("Direction cannot be blank.");
                }

                if (neighbors.find(direction) != neighbors.end()) {
                    throw std::invalid_argument("Location already exists in that direction.");
            }

                neighbors.insert(std::pair<std::string, Location>(direction, location));
            }
            
            void updateLocation(Location location) {
                /**
                 * Method that updates location in neighbors map
                 * Parameters: location - Location
                 * Returns: None
                 */
                for(auto& neighbor : neighbors) {
                    if (neighbor.second.getName() == location.getName()) {
                        neighbor.second = location;
                    }
                }
                          
            }

            void addNPC(NPC npc) {
                /*
                * Method that adds NPC to location\
                * Parameters: npc - NPC
                * Returns: None
                */
                npcs.push_back(npc);
            }

            std::vector<NPC> getNPCs() {
                /*
                * Getter for NPC vector in location
                * Parameters: None
                * Returns: vector<NPC>
                */
                return npcs;
            }

            void updateNPC (NPC npc) {
                /*
                 * Method that updates NPC in location
                 * Parameters: npc - NPC
                 * Returns: None
                 */
                for (auto& npc_ : npcs) {
                    if (npc_.getName() == npc.getName()) {
                        npc_ = npc;
                    }
                }
            }

            void addItem(Item item) {
                /*
                * Method that adds item to location
                * Parameters: item - Item
                * Returns: None
                */
                items.push_back(item);
            }

            void removeItem(Item item) {
                /* 
                * Method that removes item from location
                * Parameters: item - Item
                * Returns: None
                */
                std::string d = item.getName();
                for(int i = 0; i < items.size(); i++) {
                    std::string c = items[i].getName();
                    
                    if (c == d) {
                        items.erase(items.begin() + i);
                        return;
                    }
                   
                }
            }
            
            std::vector<Item> getItems() {
                /*
                * Getter for items vector in location
                * Parameters: None
                * Returns: vector<Item>
                */
                return items;
            }

            void setVisited() {
                /*
                * Method that sets the visited variable to true
                * Parameters: None
                * Returns: None
                */
                this->visited = true;
            }

            bool getVisited() {
                /*
                * Getter for visited variable
                * Parameters: None
                * Returns: bool
                */
                return this->visited;
            }

            // operator overload for output
            friend std::ostream& operator<<(std::ostream& os, const Location& location) {
                os << location.name << " - " << location.description << "\n";
                os << "\n";
                
                if (!location.npcs.empty()) {
                    os << "You see the following NPCs:\n";
                    for (auto npc : location.npcs) {
                        os << "- " << npc.getName() << "\n";
                    }
                    os << "\n";
                }
                else {
                    os << "You are alone." << "\n";
                }

                if (!location.items.empty()) {
                    os << "You see the following Items:\n";
                    for (auto item : location.items) {
                        os << "- " << item.getName() << " (" << item.getCalories() << " calories) - " << item.getWeight() << " lbs - " << item.getDescription() << ".\n";
                    }
                    os << "\n";
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
                os << "*********************************";

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
