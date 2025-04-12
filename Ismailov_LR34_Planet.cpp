#include "Ismailov_LR34_Planet.h"
#include <cmath>

const double G = 6.67430e-11; 


Planet::Planet() : name("Unknown"), mass(0.0), radius(0.0) {}

Planet::Planet(const std::string& name, double mass, double radius, const std::vector<std::string>& dates)
    : name(name), mass(mass), radius(radius), researchDates(dates) {}

Planet::Planet(const Planet& other)
    : name(other.name), mass(other.mass), radius(other.radius), researchDates(other.researchDates) {}

Planet::Planet(double mass) : name("Unknown"), mass(mass), radius(0.0) {}

Planet::Planet(const std::string& name, double mass, double radius)
    : Planet(name, mass, radius, {}) {}

// Метод вычисления ускорения свободного падения
double Planet::calculateGravity() const {
    if (radius <= 0) return 0.0;
    return (G * mass) / (radius * radius);
}

// Метод вывода
void Planet::display() const {
    std::cout << *this << std::endl;
}

// Метод ввода
void Planet::input() {
    std::cin >> *this;
}

// Перегруженные операции
bool Planet::operator<(const Planet& other) const { return mass < other.mass; }
bool Planet::operator>(const Planet& other) const { return mass > other.mass; }
bool Planet::operator==(const Planet& other) const { return mass == other.mass; }

Planet Planet::operator+(const Planet& other) const {
    Planet result = *this;
    result.researchDates.insert(result.researchDates.end(), other.researchDates.begin(), other.researchDates.end());
    return result;
}

Planet& Planet::operator++() {
    mass += 1.0e24; 
    return *this;
}

Planet Planet::operator++(int) {
    Planet temp = *this;
    mass += 1.0e24;
    return temp;
}

Planet& Planet::operator=(const Planet& other) {
    if (this != &other) {
        name = other.name;
        mass = other.mass;
        radius = other.radius;
        researchDates = other.researchDates;
    }
    return *this;
}

// Ввод и вывод
std::ostream& operator<<(std::ostream& os, const Planet& planet) {
    os << "Planet: " << planet.name << ", Mass: " << planet.mass << " kg, Radius: " << planet.radius << " m";
    os << ", Research Dates: ";
    for (const auto& date : planet.researchDates) {
        os << date << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Planet& planet) {
    std::cout << "Enter name: ";
    is >> planet.name;
    std::cout << "Enter mass (kg): ";
    is >> planet.mass;
    std::cout << "Enter radius (m): ";
    is >> planet.radius;
    std::cout << "Enter number of research dates: ";
    int numDates;
    is >> numDates;
    planet.researchDates.clear();
    for (int i = 0; i < numDates; ++i) {
        std::string date;
        std::cout << "Enter research date " << i + 1 << ": ";
        is >> date;
        planet.researchDates.push_back(date);
    }
    return is;
}