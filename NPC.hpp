/*
* Authors: Jared Bradley, Connor Valley, and James Zesiger
* Date: 2/20/25
* Description: Header for NPC class
*/ 


#ifndef         __HPP__NPC__
#define         __HPP__NPC__

#include "Item.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

class NPC {
        public:
            // Default constructor
            NPC(std::string name, std::string description){
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
                this->messageNum = 0;

            }

            void addItem(Item item) {
                /**
                 * Method that adds item to NPC
                 * Parameters: item - Item
                 * Returns: None
                 */
                this->item = item;
            }

            Item getItem() {
                /**
                 * Method that returns item from NPC
                 * Parameters: None
                 * Returns: Item
                 */
                return this->item;
            }

            void removeItem() {
                /**
                 * Method that removes item from NPC
                 * Parameters: None
                 * Returns: None
                 */
                this->item = Item("none", "none", 0, 0);
            }

            void setName(std::string name) {
                /**
                 * setter for NPC name
                 * Parameters: name - string
                 * Returns: None
                 */
                this->name = name;
            }

            void setDescription(std::string description) {
                /*
                * Setter for NPC description
                * Parameters: desciption - strings
                * Returns: None
                */
                this->description = description;
            }

            std::string getName() {
                /*
                * Getter for NPC name
                * Parameters: None
                * Returns: string
                */
                return this->name;
            }

            std::string getDescription() {
                /*
                * Getter for NPC desctiption
                * Parameters: None
                * Returns: string
                */
                if (item.getName() != "none") {
                    return this->description + " They are holding a " + item.getName() + ".";
                }
                return this->description;
            }

            std::string getMessage() {
                /*
                * Getter for NPC message
                * Parameters: None
                * Retruns: string
                */
                if (messages.empty()) {
                    return "They don't want to talk to you.";
                }
                std::string currentMessage = messages[messageNum];
                this->messageNum = this->messageNum + 1;
                if (messageNum >= messages.size()) {
                    messageNum = 0;
                }
                return currentMessage;
            }

            void addMessage(std::string message) {
                /*
                * Setter for NPC message
                * Parameters: message : string
                * Returns: None
                */
                if (message.empty()) {
                    throw std::invalid_argument("Message cannot be blank.");
                }
                messages.push_back(message);
            }

            // operator overload
            friend std::ostream& operator<<(std::ostream& os, const NPC& npc) {
                os << npc.name;
                return os;

            }



        private:
            std::string name;
            std::string description;
            Item item = Item("none", "none", 0, 0);
            std::vector<std::string> messages;
            int messageNum;

};


#endif