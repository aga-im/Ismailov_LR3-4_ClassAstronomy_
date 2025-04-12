#include "Ismailov_LR34_Planet.h"
#include "Ismailov_LR34_Methods.h"
#include <map>
#include <functional>

int main() {
    std::map<int, std::pair<std::string, std::function<void()>>> menu = {
        {1, {"Create Planet (Default Constructor)", createPlanetDefault}},
        {2, {"Create Planet (Parameterized Constructor)", createPlanetParameterized}},
        {3, {"Show All Planets", showAllPlanets}},
        {4, {"Calculate Gravity for a Planet", calculateGravityForPlanet}},
        {5, {"Sort Planets by Mass", sortAndDisplayPlanets}}
    };

    unsigned choice = 0;
    while (true) {
        std::cout << "\nMenu:\n";
        for (const auto& item : menu) {
            std::cout << item.first << ". " << item.second.first << "\n";
        }
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Exiting program.\n";
            break;
        }

        if (menu.find(choice) != menu.end()) {
            menu[choice].second();
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}