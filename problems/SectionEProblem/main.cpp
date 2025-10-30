#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(){
  ifstream MyReadFile("./text.txt");
  string srcStr;
  while (getline(MyReadFile,srcStr)){
    cout << srcStr;
  }
}
