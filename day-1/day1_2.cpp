// Read in the text input from file
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

vector<string> split(const string &str){
    
    vector<string> tokens;
    istringstream ss(str);
    string token;

    while(ss >> token){
        tokens.push_back(token);
    }

    return tokens;
}

int main(){
    ifstream myfile;
    myfile.open("day1_1_input.txt");
    string myline;
    vector<int> firstList;
    vector<int> secondList;

    if(myfile.is_open()){
        while(getline(myfile, myline)){
            if(!myline.empty()){
                vector<string> pair = split(myline);
                firstList.push_back(stoi(pair[0]));
                secondList.push_back(stoi(pair[1]));
            }
        }
    }

    map<int, int> countMap;

    for(int num: secondList){
        countMap[num]++;
    }
    int totalSum = 0;
    for(int i; i < firstList.size(); i++){
        totalSum += firstList[i] * countMap[firstList[i]];
    }
    cout << totalSum << "\n" << endl;

    return 0;
}