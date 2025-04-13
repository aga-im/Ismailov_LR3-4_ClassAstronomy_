#ifndef ISMAILOV_LR34_PLANET_H
#define ISMAILOV_LR34_PLANET_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <functional>

using namespace std;

class Planet {
private:
    string name;           
    int mass;              
    int radius;            
    vector<int> researchYears; 

public:
    // Конструкторы
    Planet() : name("Unknown"), mass(0), radius(0) {} // По умолчанию
    Planet(string n, int m, int r) : name(n), mass(m), radius(r) {} // Параметризованный
    Planet(string n, int m, int r, vector<int> years) : name(n), mass(m), radius(r), researchYears(years) {} // С годами
    Planet(const Planet& other) : name(other.name), mass(other.mass), radius(other.radius), researchYears(other.researchYears) {} // Копирования
    Planet(int m) : name("Converted"), mass(m), radius(0) {} // Преобразования из массы

   
    void setName(const string& n) { name = n; }
    void setMass(int m) { mass = m; }
    void setRadius(int r) { radius = r; }
    void setResearchYears(const vector<int>& years) { researchYears = years; }

    
    string getName() const { return name; }
    int getMass() const { return mass; }
    int getRadius() const { return radius; }
    vector<int> getResearchYears() const { return researchYears; }

    
    static Planet* input(); 
    void show() const;      
    double calcGravity() const; 

    
    bool operator<(const Planet& other) const { return mass < other.mass; }
    Planet operator+(const Planet& other) const;
    Planet& operator++();          // Префиксный инкремент
    Planet operator++(int);        // Постфиксный инкремент
    Planet& operator=(const Planet& other);
    friend ostream& operator<<(ostream& os, const Planet& p);
    friend istream& operator>>(istream& is, Planet& p);

    ~Planet() = default;
};
#endif 