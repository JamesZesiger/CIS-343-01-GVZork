// Authors: Jared Bradley, Connor Valley, and James Zesiger
// 2/20/25

#ifndef         __HPP__NPC__
#define         __HPP__NPC__

#include "Item.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

class NPC {
        public:
            NPC(std::string name, std::string description){

                if (name.empty()) {
                    throw std::invalid_argument("Name cannot be blank.");
                }

                if (description.empty()) {
                    throw std::invalid_argument("Description cannot be blank.");
                }             

                this->name = name;
                this->description = description;
                this->messageNum = 0;

            }

            void addItem(Item item) {
                this->item = item;
            }

            Item getItem() {
                return this->item;
            }

            void removeItem() {
                this->item = Item("none", "none", 0, 0);
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
                if (item.getName() != "none") {
                    return this->description + " They are holding a " + item.getName() + ".";
                }
                return this->description;
            }

            std::string getMessage() {
                if (messages.empty()) {
                    return "They don't want to talk to you.";
                }
                std::string currentMessage = messages[messageNum];
                messageNum = messageNum + 1;
                return currentMessage;
            }

            void setMessage(std::string message) {
                if (message.empty()) {
                    throw std::invalid_argument("Message cannot be blank.");
                }
                messages.push_back(message);
            }

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