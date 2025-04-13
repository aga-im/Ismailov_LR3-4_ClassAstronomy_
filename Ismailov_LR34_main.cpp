#include "Ismailov_LR34_Planet.cpp"
#include <map>
#include <iostream>

using namespace std;

struct MenuItem {
    string title;
    function<void()> action;
};

int main() {
    setlocale(LC_ALL,"Russian");
    map<int, MenuItem> menu = {
        {1, {"Show Planets", createPlanetsFromFile(LIST)}},
        {2, {"Add Planet", addPlanetToDB}},
        {3, {"Show All Planets", showPlanets}},
        {4, {"Show Planets Sorted by Mass", showSortedPlanetsByMass}}

    };

    int choice = 0;
    for(const auto& item : menu){
        cout<<"Task "<<item.first<<". "<<item.second.title<<endl;
    }
    cout<<"0.Exit"<<endl;
    while (true) {
        EnterNumber(choice, "Введите номер пункта: ")();
        if (choice == 0) {
            std::cout << " 2025 Ismailov Agafendi" << std::endl;
            break;
        }
        cout << endl << " ============Action===========" << endl;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        }
        else
        {
            std::cout << "Некорректный ввод.";
        }
        std::cout << std::endl;
    }
    
    return 0;
}