// Read in the text input from file
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
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
    int totalSum = 0;
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
    sort(firstList.begin(), firstList.end());
    sort(secondList.begin(), secondList.end());

    for(int i = 0; i < firstList.size(); i++){
        int first = firstList[i];
        int second = secondList[i];
        int diff = first - second;
        int absDiff = abs(diff);
        totalSum += absDiff;
    }
    cout << totalSum << "\n" << endl;

    return 0;
}