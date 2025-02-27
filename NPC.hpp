// Jared Bradley
// Feb 19th, 2025

#ifndef         __HPP__NPC__
#define         __HPP__NPC__

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
            std::vector<std::string> messages;
            int messageNum;

};


#endif
