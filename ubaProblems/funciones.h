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
#include <utility>
using namespace std;

//UBA 146
void nextPermutation(){
    string word;
    do{
        cin >> word;
        if(next_permutation(word.begin(),word.end()))
            cout << word << endl;
        else if(word.at(0) == '#') {
            cout << endl;
            return;
        }
        else{
            cout << "No sucesor" << endl;
        }
    }
    while(word.at(0) != '#');
}

// UBA299
template<typename T>
int amountOfSwaps(vector<T> vec){
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
// UBA 482
template<typename T1, typename T2>
void displayOrder(vector<T1> vecI, vector<T2> vecD){
    for(int i = 0; i < vecI.size(); ++i){
        for(int j = 0, f = 0; j < vecI.size()- 1;++f ,++j){
            if(vecI.at(j) > vecI.at(j + 1)){
                T1 temp = vecI.at(j);
                vecI.at(j) = vecI.at(j + 1);//Posición inicial
                vecI.at(j + 1) = temp; // Posición siguiente
                T2 tempS = vecD.at(f);
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

// UBA 612
bool compareInterval(pair<string,int> i1, pair<string,int> i2)
{
    return (i1.second < i2.second);
}
int AmountOfSwapsStr(string word){
    int count = 0;
    for(int j = 0; j < word.size();++j){
        for(int i = 0; i < word.size() - 1;++i){
            if(static_cast<int>(word[i]) > static_cast<int>(word[i + 1])){
                string before = word.substr(0, i);
                string after = word.substr(i+2,word.size()-i-1);
                word = before + word[i + 1] + word[i] + after;
                count++;
            }
        }
    }
    return count;
}
void displayOrder(vector<pair<string,int>> wordAndAmountOfSwaps){
    sort(wordAndAmountOfSwaps.begin(),wordAndAmountOfSwaps.end(),compareInterval);
    cout << endl;
    for(auto dniWord : wordAndAmountOfSwaps){
        cout << dniWord.first <<endl;
    }
}
#endif //UBAPROBLEMS_FUNCIONES_H
