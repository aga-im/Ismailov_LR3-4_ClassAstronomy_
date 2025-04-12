#ifndef ISMAILOV_LR34_PLANET_H
#define ISMAILOV_LR34_PLANET_H

#include <string>
#include <vector>
#include <iostream>

class Planet {
private:
    std::string name;                
    double mass;                     
    double radius;                 
    std::vector<std::string> researchDates; 

public:
    
    Planet(); 
    Planet(const std::string& name, double mass, double radius, const std::vector<std::string>& dates); 
    Planet(const Planet& other); 
    Planet(double mass); 
    Planet(const std::string& name, double mass, double radius); 
    
    std::string getName() const { return name; }
    void setName(const std::string& name) { this->name = name; }
    double getMass() const { return mass; }
    void setMass(double mass) { this->mass = mass; }
    double getRadius() const { return radius; }
    void setRadius(double radius) { this->radius = radius; }
    std::vector<std::string> getResearchDates() const { return researchDates; }
    void setResearchDates(const std::vector<std::string>& dates) { researchDates = dates; }

    
    double calculateGravity() const; 
    void display() const; 
    void input(); 
    
    bool operator<(const Planet& other) const;
    bool operator>(const Planet& other) const;
    bool operator==(const Planet& other) const;
    Planet operator+(const Planet& other) const;
    Planet& operator++(); // Префиксный инкремент
    Planet operator++(int); // Постфиксный инкремент
    Planet& operator=(const Planet& other);

    
    friend std::ostream& operator<<(std::ostream& os, const Planet& planet);
    friend std::istream& operator>>(std::istream& is, Planet& planet);
};

#endif 