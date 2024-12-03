#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
using namespace std;

int main() {

    
    ifstream file("day_3_1_input.txt");
    ostringstream oss;
    oss << file.rdbuf(); // Get better understanding of this
    string input = oss.str();

    // Matching logic
    vector<string> matches;   
    regex regexp("mul\\([0-9]+,[0-9]+\\)");
    smatch match; // Check what this returns
    auto searchStart = input.cbegin();


    // Would like to clean this up into its own function but we'll worry about that 'later'

    while(regex_search(searchStart, input.cend(), match, regexp)){
        matches.push_back(match.str());
        searchStart = match[0].second; // Get a better understanding of this
        // Sets the search point to the end of the last entry's index
    }
    
    // Have the list at this stage

    int total  = 0;
    for (auto match: matches){
        int comma = match.find(",");

        int firstParenthesis = match.find("(");
        int secondParenthesis = match.size() - 1;
        int firstNumberLength = comma - firstParenthesis - 1;
        int secondNumberLength = secondParenthesis - comma - 1;
        // string substr (size_t pos = 0, size_t len = npos) const;
        string firstNumber = match.substr(match.find("(")+1,firstNumberLength);
        string secondNumber = match.substr(comma+1,secondNumberLength);

        int multiplicationResult = stoi(firstNumber) * stoi(secondNumber);
        total += multiplicationResult;
    }
    cout << total << "\n";
    return 0;

}