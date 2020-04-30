//
// Created by Andres Riveros on 4/29/20.
//

#ifndef UBAPROBLEMS_FUNCIONES_H
#define UBAPROBLEMS_FUNCIONES_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int amountSwap(vector<int> vec){
    int count = 0;
    for(int i = 0; i < vec.size(); ++i){
        for(int j = 0; j < vec.size()- 1; ++j){
            if(vec.at(j) > vec.at(j + 1)){
                int temp = vec.at(j);
                vec.at(j) = vec.at(j + 1);//Posición inicila
                vec.at(j + 1) = temp; // Posición siguiente
                count++;
            }
        }
    }
    return count;
}

void displayOrder(vector<int> vecI, vector<double> vecD){
    for(int i = 0; i < vecI.size(); ++i){
        for(int j = 0, f = 0; j < vecI.size()- 1;++f ,++j){
            if(vecI.at(j) > vecI.at(j + 1)){
                int temp = vecI.at(j);
                vecI.at(j) = vecI.at(j + 1);//Posición inicial
                vecI.at(j + 1) = temp; // Posición siguiente
                int tempS = vecD.at(f);
                vecD.at(f) = vecD.at(f + 1);//Posición inicial
                vecD.at(f + 1) = tempS; // Posición siguiente
            }
        }
    }
    for(auto& vec: vecD){
        cout << vec << " ";
    }
    cout << endl;
}
#endif //UBAPROBLEMS_FUNCIONES_H
