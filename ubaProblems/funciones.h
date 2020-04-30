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
        for(int j = 0; j < vec.size()- 1; ++j){
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
pair<int,int> findMaxMinBill(size_t size_, int value = 0);
void showAnswer(vector<pair<int,int>> maxAndMin){
    int max = 0, min = maxAndMin[0].first;
    for(auto c : maxAndMin){
        if(max < c.first){
            max = c.first;
        }
        if(min > c.second){
            min = c.second;
        }
    }
    cout << max << '\n' << min << '\n';
}
int sumaTotaldelDía(){
    int elem;
    size_t size_;
    cin >> size_;
    string text;
    getline(cin,text);
    stringstream ss(text);
    int total_bill = 0;
    int count = 0;
    while(ss >> elem){
        total_bill += elem;
        count++;
        if(size_ == count){
            break;
        }
    }
    return total_bill;
}

void uba_11136(){
    vector<pair<int,int>> maxAndmin;
    size_t numCases=0;
    int count=0;
    do{
        cin >> numCases;
        if(numCases == 0) break;
        if(count > 0){
            int last_value =maxAndmin[count-1].second;
            maxAndmin.push_back(findMaxMinBill(numCases,last_value));
        }
        else{
            maxAndmin.push_back(findMaxMinBill(numCases));
        }
        count++;
    }while(true);
    showAnswer(maxAndmin);
}

pair<int,int> findMaxMinBill(size_t numCases, int value){
    pair<int,int> maxMin;
    maxMin.second = value;
    for(int i = 0; i < numCases; ++i){
        int result = sumaTotaldelDía();
        if(result >= maxMin.first){
            maxMin.first = result;
        }
        else{
            maxMin.second = result;
        }
    }
    maxMin.first -=maxMin.second;
    return maxMin;
}
#endif //UBAPROBLEMS_FUNCIONES_H
