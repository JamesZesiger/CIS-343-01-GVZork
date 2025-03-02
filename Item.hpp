/*
* Authors: Jared Bradley, Connor Valley, and James Zesiger
* Date: 2/20/25
* Description: Header for Item class
*/ 

#ifndef         __HPP__ITEM__
#define         __HPP__ITEM__

#include <stdexcept>
#include <iostream>
#include <string>

class Item {
        public:
            // Default constructor
            Item(std::string name, std::string description, int calories, float weight) {
                // Error handeling for empty name
                if (name.empty()) {
                    throw std::invalid_argument("Name cannot be blank.");
                }
                // Error handeling for empty description
                if (description.empty()) {
                    throw std::invalid_argument("Description cannot be blank.");
                }
                // Error handeling for calories
                if (calories < 0 || calories > 1000) {
                    throw std::invalid_argument("Calories must be between 0 and 1000.");
                }
                // Error handeling for weight
                if (weight < 0.0 || weight > 500.0) {
                    throw std::invalid_argument("Weight must be between 0 and 500");
                }

                this->name = name;
                this->description = description;
                this->calories = calories;
                this->weight = weight;
            }

            void setName(std::string name) {
                /*
                * Method that sets the name of the item
                * Parameters: name - string
                * Returns: None
                */
                this->name = name;
            }

            void setDescription(std::string description) {
                /*
                * Method that sets the description of the item
                * Parameters: description - string
                * Returns: None
                */
                this->description = description;
            }

            void setCalories(int calories) {
                /*
                * Method that sets the calories of the item
                * Parameters: calories - int
                * Returns: None
                */
                this->calories = calories;
            }

            void setWeight(float weight) {
                /*
                * Method that sets the weight of the item
                * Parameters: weight - float
                * Returns: None
                */
                this->weight = weight;
            }

            std::string getName() {
                /*
                * Getter for item name
                * Parameters: None
                * Returns: string                
                */
                return this->name;
            }

            std::string getDescription() {
                /*
                * Getter for item description
                * Parameters: None
                * Returns: string                
                */
                return this->description;
            }

            int getCalories() {
                /*
                * Getter for item calories
                * Parameters: None
                * Returns: int                
                */
                return this->calories;
            }

            float getWeight() {
                /*
                * Getter for item weight
                * Parameters: None
                * Returns: float                
                */
                return this->weight;
            }

            // operator overload for output
            friend std::ostream& operator<<(std::ostream& os, const Item& item) {
                os << item.name << " (" << item.calories << " calories) - " << item.weight << " lb - " << item.description;
                return os;
            } 



        private:
            std::string name;
            std::string description;
            int calories;
            float weight;



};

#endif