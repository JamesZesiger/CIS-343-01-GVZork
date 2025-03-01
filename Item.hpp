// Authors: Jared Bradley, Connor Valley, and James Zesiger
// 2/20/25

#ifndef         __HPP__ITEM__
#define         __HPP__ITEM__

#include <stdexcept>
#include <iostream>
#include <string>

class Item {
        public:
            Item(std::string name, std::string description, int calories, float weight) {
                if (name.empty()) {
                    throw std::invalid_argument("Name cannot be blank.");
                }

                if (description.empty()) {
                    throw std::invalid_argument("Description cannot be blank.");
                }

                if (calories < 0 || calories > 1000) {
                    throw std::invalid_argument("Calories must be between 0 and 1000.");
                }

                if (weight < 0.0 || weight > 500.0) {
                    throw std::invalid_argument("Weight must be between 0 and 500");
                }

                this->name = name;
                this->description = description;
                this->calories = calories;
                this->weight = weight;
            }

            void setName(std::string name) {
                this->name = name;
            }

            void setDescription(std::string description) {
                this->description = description;
            }

            void setCalories(int calories) {
                this->calories = calories;
            }

            void setWeight(float weight) {
                this->weight = weight;
            }

            std::string getName() {
                return this->name;
            }

            std::string getDescription() {
                return this->description;
            }

            int getCalories() {
                return this->calories;
            }

            float getWeight() {
                return this->weight;
            }

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