#include "Ismailov_LR34_Methods.h"
#include <iostream>
#include <cmath>

using namespace std;

const double G = 6.67430e-11; 

Planet* Planet::input() {
    Planet* planet = new Planet;
    string raw_input;
    cout << "Input name: ";
    getline(cin, planet->name);
    while (planet->name.empty()) {
        cout << "Input name: ";
        getline(cin, planet->name);
    }

    cout << "Input mass (kg): ";
    getline(cin, raw_input);
    while (raw_input.empty() || stoi(raw_input) <= 0) {
        cout << "Input mass (kg): ";
        getline(cin, raw_input);
    }
    planet->mass = stoi(raw_input);

    cout << "Input radius (m): ";
    getline(cin, raw_input);
    while (raw_input.empty() || stoi(raw_input) <= 0) {
        cout << "Input radius (m): ";
        getline(cin, raw_input);
    }
    planet->radius = stoi(raw_input);

    cout << "Input number of research years: ";
    getline(cin, raw_input);
    int numYears = stoi(raw_input);
    for (int i = 0; i < numYears; i++) {
        cout << "Year " << i + 1 << ": ";
        getline(cin, raw_input);
        planet->researchYears.push_back(stoi(raw_input));
    }
    cout << "----------------------------------" << endl;
    return planet;
}

void Planet::show() const {
    cout << "Name: " << name << endl;
    cout << "Mass: " << mass << " kg" << endl;
    cout << "Radius: " << radius << " m" << endl;
    cout << "Research Years: ";
    for (int year : researchYears) cout << year << "_";
    cout << endl << "Gravity: " << calcGravity() << " m/s^2" << endl;
    cout << "---------------------------------" << endl;
}

double Planet::calcGravity() const {
    if (radius == 0) return 0.0;
    return (G * mass) / (radius * radius); // g = GM/r^2
}

Planet Planet::operator+(const Planet& other) const {
    string combinedName = name + "+" + other.name;
    int combinedMass = mass + other.mass;
    int avgRadius = (radius + other.radius) / 2;
    vector<int> combinedYears = researchYears;
    combinedYears.insert(combinedYears.end(), other.researchYears.begin(), other.researchYears.end());
    return Planet(combinedName, combinedMass, avgRadius, combinedYears);
}

Planet& Planet::operator++() {
    mass += 1000; 
    return *this;
}

Planet Planet::operator++(int) {
    Planet temp(*this);
    ++(*this);
    return temp;
}

Planet& Planet::operator=(const Planet& other) {
    if (this != &other) {
        name = other.name;
        mass = other.mass;
        radius = other.radius;
        researchYears = other.researchYears;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Planet& p) {
    os << "Name: " << p.name << ", Mass: " << p.mass << " kg, Radius: " << p.radius << " m, Years: ";
    for (int year : p.researchYears) os << year << " ";
    return os;
}

istream& operator>>(istream& is, Planet& p) {
    cout << "Enter name: ";
    getline(is, p.name);
    cout << "Enter mass (kg): ";
    is >> p.mass;
    cout << "Enter radius (m): ";
    is >> p.radius;
    is.ignore();
    cout << "Enter number of research years: ";
    int numYears;
    is >> numYears;
    is.ignore();
    p.researchYears.clear();
    for (int i = 0; i < numYears; i++) {
        int year;
        cout << "Year " << i + 1 << ": ";
        is >> year;
        p.researchYears.push_back(year);
    }
    is.ignore();
    return is;
}