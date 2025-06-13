#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

std::string ToLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}
struct portal
{
    std::string name;
    int target;
};

struct player
{
    int currentLoc = 0;

};

struct location_
{

    std::string name;
    std::string descr;
    std::vector <portal> portals;
    std::vector<std::string> points;
};

location_ locations[5];
player user;

//int currentLocation = 0;
std::vector<std::string> inventory;
std::unordered_map<std::string, bool> state;
std::unordered_map<std::string, std::string> interestDescriptions;



void InitGame() {
    locations[0].name = "Зона удара";
    locations[0].descr = "Место болезненного столкновения с поверхностью планеты. Спасательная капсула ещё дымится.";
    locations[0].portals.push_back({ "qom", 1 });
    locations[0].points = { "Капсула", "Окрестности", "Тело" };

    locations[1].name = "Долина ветра";
    locations[1].descr = "Место, где ветра играют среди густой растительности. Ускользающие тени указывают на движение.";
    locations[1].portals.push_back({ "zona", 0 });
    locations[1].portals.push_back({ "forest", 2 });
    locations[1].points = { "Растения", "Следы" };


    locations[2].name = "Туманный лес";
    locations[2].descr = "Густой лес, пропитанный влагой и туманом. Повсюду слышны звуки шуршания и шепота.";
    locations[2].portals.push_back({ "Долина_ветра", 1 });
    locations[2].portals.push_back({ "Пещера_света", 4 });
    locations[2].points = { "Дерево", "Туман" };

    locations[3].name = "Пещера света";
    locations[3].descr = "Пещера с сияющими стенами. Загадочная энергия пронизывает воздух.";
    locations[3].portals.push_back({ "Долина_ветра", 4 });
    locations[3].portals.push_back({ "Центр", 5 });
    locations[3].points = { "Камни", "Ручей" };

    locations[4].name = "Центр зарождения";
    locations[4].descr = "Сердце экосистемы. Таинственное существо ожидает вашего прихода.";
    locations[4].points = { "Существо", "Центр" };

    interestDescriptions[ToLower("Капсула")] = "Вы осмотрели капсулу. Она сильно повреждена, но внутри можно найти что-то полезное.";
    interestDescriptions[ToLower("Окрестности")] = "Окрестности выглядят сурово. Следы на земле указывают на движение в направлении Долины Ветра.";
    interestDescriptions[ToLower("Тело")] = "Вы находите тело пилота. Оно безжизненно, но в руках зажат поврежденный модуль связи.";




    state["осмотрел_капсулу"] = false;
    state["взял_модуль"] = false;
}

int Find(const std::string& name) {
    for (int i = 0; i < 5; i++) {
        if (locations[i].name == name) {
            return i;
        }
    }
    return -1; // Локация не найдена
}

void DisplayLocation() {
    std::cout << "Вы находитесь в: " << locations[user.currentLoc].name << "\n";
    std::cout << locations[user.currentLoc].descr << "\n";
}

//void Go() {
//    std::cout << "Доступные переходы:\n";
//    for (int portal : locations[user.currentLoc].portals.size()) {
//        std::cout << "- " << locations[portal].name << "\n";
//    }
//    std::string destination;
//    std::cout << "Введите название локации: ";
//    std::getline(std::cin, destination);
//
//    int targetLocation;
//    for (int i = 0; i < 5; ++i) {
//        if (locations[i].name == destination) {
//            targetLocation = i;
//            break;
//        }
//    }
//
//    if (targetLocation == -1) {
//        std::cout << "Такой локации не существует.\n";
//    }
//    else if (std::find(locations[user.currentLoc].portals.begin(), locations[user.currentLoc].portals.end(), targetLocation) != locations[user.currentLoc].portals.end()) {
//        currentLoc = targetLocation;
//        DisplayLocation();
//    }
//    else {
//        std::cout << "Вы не можете перейти в эту локацию.\n";
//    }
//}
//
//
void ShowActions() {
    std::cout << "Доступные команды: go, take, look, act.\n";
}
//
//void Look() {
//    std::cout << "Доступные точки для осмотра:\n";
//    for (const std::string& point : locations[currentLocation].points) {
//        std::cout << "- " << point << "\n";
//    }
//    std::string point;
//    std::cout << "Введите название точки для осмотра: ";
//    std::getline(std::cin, point);
//
//    if (point == "капсула" && currentLocation == 0) {
//        std::cout << "Вы осмотрели капсулу и заметили поврежденный модуль связи.\n";
//        state["осмотрел_капсулу"] = true;
//    }
//    else if (point == "окрестности" && currentLocation == 0) {
//        std::cout << "Вы осмотрели окрестности и заметили следы, ведущие к 'Долине Ветра'.\n";
//    }
//    else if (point == "тело" && currentLocation == 0) {
//        std::cout << "На ваших руках видны фиолетовые пульсирующие пятна, внутри ощутимо движение.\n";
//    }
//    else {
//        std::cout << "Здесь ничего интересного.\n";
//    }
//}
//
//
//void Take() {
//    if (state["осмотрел_капсулу"] && !state["взял_модуль"] && currentLocation == 0) {
//        inventory.push_back("поврежденный модуль связи");
//        std::cout << "Вы взяли поврежденный модуль связи.\n";
//        state["взял_модуль"] = true;
//    }
//    else {
//        std::cout << "Не выходит.\n";
//    }
//}
//
//
//void Act() {
//    if (currentLocation == 1 && state["взял_модуль"]) {
//        std::cout << "Вы можете попробовать использовать модуль связи для изучения сигналов.\n";
//    }
//    else {
//        std::cout << "Здесь пока нечего делать.\n";
//    }
//}


//void PlayGame() {
//    std::string command;
//    while (true) {
//        DisplayLocation();
//        std::cout << "Введите команду (action для списка команд): ";
//        std::getline(std::cin, command);
//
//        if (command == "action") {
//            ShowActions();
//        }
//        else if (command == "go") {
//            Go();
//        }
//        else if (command == "take") {
//            Take();
//        }
//        else if (command == "look") {
//            Look();
//        }
//        else if (command == "act") {
//            Act();
//        }
//        else if (command == "exit") {
//            std::cout << "Выход из игры.\n";
//            break;
//        }
//        else {
//            std::cout << "Не выходит.\n";
//        }
//    }
//}


int main() {
    setlocale(LC_ALL, "Russian");
    InitGame();
    //PlayGame();

    std::string command;

    //cout << locations[1].portals.size();
    
    while (true) {

        std::cout << "Введите команду (action для списка команд): ";
        std::getline(std::cin, command);

        if (command == "action") {
            ShowActions();
        }



        if (command == "go") {

            std::cout << "Доступные переходы:\n";

            for (int i = 0; i < locations[user.currentLoc].portals.size(); i++)
            {
                std::cout << "- " << locations[user.currentLoc].portals[i].name << "\n";
            }
                std::cout << "Введите название локации: ";

                cin >> command;

                for (int i = 0; i < locations[user.currentLoc].portals.size(); i++) {

                    if (locations[user.currentLoc].portals[i].name == command) {
                        user.currentLoc = locations[user.currentLoc].portals[i].target;

                        cout << "Локация: \n" << locations[user.currentLoc].name;

                    }
                }


           /* std::string destination;
                std::getline(std::cin, destination);

                int targetLocation;
                for (int i = 0; i < 5; ++i) {
                    if (locations[i].name == destination) {
                        targetLocation = i;
                        break;
                    }
                }*/

            /*if (targetLocation == -1) {
                std::cout << "Такой локации не существует.\n";
            }
            else if (std::find(locations[user.currentLoc].portals.begin(), locations[user.currentLoc].portals.end(), targetLocation) != locations[user.currentLoc].portals.end()) {
                currentLoc = targetLocation;
                DisplayLocation();
            }
            else {
                std::cout << "Вы не можете перейти в эту локацию.\n";
            }*/
        }
    }







    //return 0;









    //    int temp[5] = { 1,6,-5,4,-9 };
    //
    //for (int i = 1; i < 5; i++) {
    //for (int j = 0; j < 5 - 1; j++) {
    //if (temp[j] > temp[j+1])
    //{
    //int temp1 = temp[j];
    //temp[j] = temp[j+1];
    //temp[j + 1] = temp1;
    //}
    //}
    //}
    //    std::cout << " ";
    //for (int i = 0; i < 5; ++i)
    //{
    //std::cout << temp[i] << " ";
    //}
    //std::cout << std::endl;

    // Расписать локации, продумать механики
    // Контейнеры - вектор, операции с векторами
     // показаит цифры порталов (1 ведет в локацию 1); команда go - выводятся доступные переходы, при выборе переместиться в локацию и вывести сообщение о текущем местонахождении

    /*for (int i = 0; i < 2; i++) {

        std::cout << locations[i].name; std::cout << std::endl;


    }*/







}