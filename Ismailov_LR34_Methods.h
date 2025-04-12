#ifndef ISMAILOV_LR34_METHODS_H
#define ISMAILOV_LR34_METHODS_H

#include "Ismailov_LR34_Planet.h"
#include <vector>
#include <algorithm>
#include <functional>

// Глобальный вектор объектов
std::vector<Planet> planets;

// Функция проверки корректности ввода числа
bool isValidNumber(const std::string& str) {
    try {
        size_t pos;
        std::stod(str, &pos);
        return pos == str.length();
    } catch (...) {
        return false;
    }
}

// Функция ввода числа с проверкой
double inputNumber(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;
        if (isValidNumber(input)) {
            return std::stod(input);
        }
        std::cout << "Invalid input. Try again.\n";
    }
}

// Функция отображения всех объектов
void showAllPlanets() {
    if (planets.empty()) {
        std::cout << "No planets in the list.\n";
        return;
    }
    for (const auto& planet : planets) {
        planet.display();
    }
}

// Функция создания планеты с помощью конструктора по умолчанию
void createPlanetDefault() {
    Planet planet;
    planets.push_back(planet);
    std::cout << "Created planet with default constructor:\n";
    planet.display();
}

// Функция создания планеты с помощью параметризованного конструктора
void createPlanetParameterized() {
    std::string name;
    double mass, radius;
    int numDates;
    std::vector<std::string> dates;

    std::cout << "Enter name: ";
    std::cin >> name;
    mass = inputNumber("Enter mass (kg): ");
    radius = inputNumber("Enter radius (m): ");
    std::cout << "Enter number of research dates: ";
    std::cin >> numDates;
    for (int i = 0; i < numDates; ++i) {
        std::string date;
        std::cout << "Enter research date " << i + 1 << ": ";
        std::cin >> date;
        dates.push_back(date);
    }
    Planet planet(name, mass, radius, dates);
    planets.push_back(planet);
    std::cout << "Created planet with parameterized constructor:\n";
    planet.display();
}

// Функция для вычисления ускорения свободного падения
void calculateGravityForPlanet() {
    if (planets.empty()) {
        std::cout << "No planets to calculate gravity.\n";
        return;
    }
    std::cout << "Select planet (index 0 to " << planets.size() - 1 << "): ";
    int index;
    std::cin >> index;
    if (index >= 0 && index < planets.size()) {
        std::cout << "Gravity on " << planets[index].getName() << ": " << planets[index].calculateGravity() << " m/s^2\n";
    } else {
        std::cout << "Invalid index.\n";
    }
}

// Функция сортировки планет по массе
std::vector<Planet> sortPlanetsByMass() {
    std::vector<Planet> sortedPlanets = planets;
    std::sort(sortedPlanets.begin(), sortedPlanets.end(), [](const Planet& a, const Planet& b) {
        return a.getMass() < b.getMass();
    });
    return sortedPlanets;
}

// Функция сортировки и отображения планет по массе
void sortAndDisplayPlanets() {
    auto sorted = sortPlanetsByMass();
    std::cout << "Planets sorted by mass:\n";
    for (const auto& planet : sorted) {
        planet.display();
    }
}

#endif // METHODS_H