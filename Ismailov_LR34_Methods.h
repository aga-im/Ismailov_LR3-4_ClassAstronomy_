#ifndef ISMAILOV_LR34_METHODS_H
#define ISMAILOV_LR34_METHODS_H

#include "Ismailov_LR34_Planet.h"
#include <algorithm>

vector<Planet> DB_Planet;

const string LIST {"planet.txt"};

bool UserInput(const string& input) {
    if (input.empty()) return false;
    try {
        int number = stoi(input);
        if (number < 0) return false;
    }
    catch (...) { return false; }
    return true;
}

bool UserStringInput(const string& input) {
    return !input.empty();
}

function<void()> EnterNumber(int& varLink, string label) {
    return [&varLink, label]() {
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);
        while (!UserInput(raw_input)) {
            cout << label << " = ";
            getline(cin, raw_input);
        }
        varLink = stoi(raw_input);
    };
}

function<void()> EnterString(string& varLink, string label) {
    return [&varLink, label]() {
        cout << label << " = ";
        getline(cin, varLink);
        while (!UserStringInput(varLink)) {
            cout << label << " = ";
            getline(cin, varLink);
        }
    };
}

void addPlanetToDB() {
    DB_Planet.emplace_back(*Planet::input());
}

function<void()> createPlanetsFromFile(string filename) {
    return [filename]() {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Failed to open file: " << filename << endl;
            return;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string name;
            int mass, radius;
            vector<int> years;
            getline(ss, name, ' ');
            ss >> mass;
            ss.ignore();
            ss >> radius;
            ss.ignore();
            int year;
            while (ss >> year) {
                years.push_back(year);
                if (ss.peek() == ',') ss.ignore();
            }
            Planet planet(name, mass, radius, years);
            DB_Planet.emplace_back(planet);
        }
        cout << "Planets loaded from file" << endl;
        file.close();
    };
}

void showPlanets() {
    for (const auto& planet : DB_Planet) {
        planet.show();
    }
}

vector<Planet> getSortedPlanetsByMass() {
    vector<Planet> sorted = DB_Planet;
    sort(sorted.begin(), sorted.end(), [](const Planet& a, const Planet& b) {
        return a.getMass() < b.getMass();
    });
    return sorted;
}

void showSortedPlanetsByMass() {
    vector<Planet> sorted = getSortedPlanetsByMass();
    for (const auto& planet : sorted) {
        planet.show();
    }
}

#endif