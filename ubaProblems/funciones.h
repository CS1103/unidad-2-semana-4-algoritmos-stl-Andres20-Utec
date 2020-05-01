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
#include <list>
using namespace std;

vector<int> rellenarVector(int size_){
    vector<int> vec;
    int elem;
    string text;
    getline(cin,text);
    stringstream ss(text);
    int count=0;
    while(ss >> elem){
        vec.push_back(elem);
        if(size_ == count)
            break;
    }
    return vec;
}
//UBA 146
void nextPermutation(){
    string word;
    vector<string> nextP;
    do{
        cin >> word;
        if(next_permutation(word.begin(),word.end())){
            nextP.push_back(word + "\n");
        }
        else if(word.at(0) == '#'){
            break;
        }
        else{
            nextP.emplace_back("No sucesor\n");
        }
    }
    while(word.at(0) != '#');
    for(auto p : nextP){
        cout << p;
    }
}

// UBA299
template<typename T>
int amountOfSwaps(vector<T> vec){
    int count = 0;
    for(int i = 0; i < vec.size(); ++i){
        for(int j = 0; j < vec.size()- 1 - i; ++j){
            if(vec.at(j) > vec.at(j + 1)){
                int temp = vec.at(j);
                vec.at(j) = vec.at(j + 1);//Posición inicial
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
//UBA 11136
int findMaxMinBill(size_t days,list<int> &urna);
void showAnswer(vector<int> &max_values,const int &min){
    int max = max_values.at(0);
    for(auto val : max_values){if(val > max) max = val;}
    cout << max << '\n' << min << '\n';
}
int sumaTotaldelDía(){
    int elem;
    int total_bill = 0;
    size_t size_;
    cin >> size_;
    if(size_ == 0)
        return total_bill;
    string text;
    getline(cin,text);
    stringstream ss(text);
    while(ss >> elem){total_bill += elem;}
    return total_bill;
}
void uba_11136(){
    vector<int> max_values;
    list<int> urna;
    int min_value;
    int count = 0;
    size_t days;
    while(true){
        cin >> days;
        if(days == 0) break;
        max_values.push_back(findMaxMinBill(days,urna));
        if(count == 0){
            min_value = max_values.at(0);
            min_value= (min_value >= urna.front())? urna.front(): min_value;
            count++;
        }
        else
            min_value= (min_value >= urna.front())? urna.front(): min_value;
    }
    showAnswer(max_values, min_value);
}

int findMaxMinBill(size_t days,list<int> &urna){

    for(int i = 0; i < days; ++i) {
        urna.push_back(sumaTotaldelDía());
    }
    urna.sort();
    if(urna.front()==0) urna.pop_front();
    int winner = urna.back() - urna.front();
    urna.pop_front();
    urna.pop_back();
    return winner;
}
#endif //UBAPROBLEMS_FUNCIONES_H
