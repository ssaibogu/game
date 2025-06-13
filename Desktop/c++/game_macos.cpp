//
//  game_macos.cpp
//  
//
//  Created by Massimo Alto on 30.05.2025.
//

#include "game_macos.hpp"
#include <vector>

struct location_ 
{

    string name; 
    string descr; 
    vector <int> portal;
};

location_ location[4]; 

void InitGame() {
    location[0].name = "Зона удара"; 
    location[0].descr = "Место болезненного столкновения с поверхностью планеты. Спасательная капусла ещё дымится";
    location[1].name = "Коридор";
    location[1].descr = "Длинный запустелый коридор";
    location[0].portal.push_back(1);






}



int main() {
    setlocale(LC_ALL, "Russian");

    InitGame();

    if 




      


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
//cout << " ";
//for (int i = 0; i < 5; ++i)
//{
//cout << temp[i] << " ";
//}
//cout << endl;
//
//// Расписать локации, продумать механики
//// Контейнеры - вектор, операции с векторами
// // показаит цифры порталов (1 ведет в локацию 1); команда go - выводятся доступные переходы, при выборе переместиться в локацию и вывести сообщение о текущем местонахождении
//
//for (int i = 0; i < 2; i++) {
//
//cout << location[i].name; cout << endl;
//
//
//}
        
        
    
    



}

