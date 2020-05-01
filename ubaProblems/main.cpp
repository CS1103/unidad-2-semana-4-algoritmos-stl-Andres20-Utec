#include "funciones.h"

int main() {

    // UBA 146
    nextPermutation();

    //UBA 299
    size_t size;
    vector<int> answer;
    cout << "Cantidad de veces: "; cin >> size;
    for(int i= 0; i < size;++i)
    {
        int size_;
        cin >> size_; // inputs : size_=(4) 4 3 2 1 / 5 1 3 2 5 4
        vector<int> vec = rellenarVector(size_);
        answer.push_back(amountOfSwaps(vec));
    }
    for(int i = 0; i < answer.size();++i){
        cout << "Optimal train swapping takes " << answer.at(i) << " swaps"<< endl;
    }

// UBA 482
    string text;
    getline(cin, text);
    vector <int> vecI;
    stringstream ss(text);
    int value;
    while(ss >> value){
        vecI.push_back(value);
    }
    string text1;
    getline(cin, text1);
    double value2;
    stringstream ss1(text1);
    vector<double> vecD;
    while(ss1 >> value2){
        vecD.push_back(value2);
    }
    displayOrder(vecI, vecD);

// UBA 612
    int sizeWord;
    int numWord;
    cin >> sizeWord >> numWord;
    vector<pair<string,int>> wordAndAmountOfSwaps;
    while(numWord--){
        string word;
        cin >> word;
        while(word.length()!= sizeWord){
            cout << "Enter a word with " << sizeWord << "letters: ";
            cin >> word;
        }
        wordAndAmountOfSwaps.push_back(pair<string,int>{word,AmountOfSwapsStr(word)});
    }
    displayOrder(wordAndAmountOfSwaps);
    cout << endl;

    // UBA 11136
    uba_11136();

    // UBA 11340
    payAuthor();
    return 0;
}
