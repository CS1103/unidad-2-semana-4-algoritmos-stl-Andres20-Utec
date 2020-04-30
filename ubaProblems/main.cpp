#include "funciones.h"

int main() {

  string word;
  cin >> word;
  int size1;
  if(next_permutation(word.begin(),word.end()))
    cout << word << endl;
  else{
    cout << "No sucesor" << endl;
  }
  size_t size;
  vector<int> answer;
  cout << "Cantidad de veces: "; cin >> size;
  for(int i= 0; i < size;++i)
  {
    vector<int> vec;
    int size2;
    cin>> size2;
    for(int j=0; j < size2; ++j){
      int elem;
      cin >> elem;
      vec.push_back(elem);
    }
    answer.push_back(amountSwap(vec));
  }
  for(int i = 0; i < answer.size();++i){
    cout << "Optimal train swapping takes " << answer.at(i) << " swaps"<< endl;
  }

  string text = "3 1 2 5 4";
  vector <int> vecI;
  stringstream ss(text);
  int value;
  while(ss >> value){
    vecI.push_back(value);
  }
  string text1 = "32.0 54.7 -2 11.25 32.1";
  double value2;
  stringstream ss1(text1);
  vector<double> vecD;
  while(ss1 >> value2){
    vecD.push_back(value2);
  }

  displayOrder(vecI, vecD);
  return 0;

}