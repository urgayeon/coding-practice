#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> score;
    
    for(int i = 0 ; i < choices.size(); i++){
        if(choices[i] < 4) score[survey[i][0]] += 4 - choices[i];
        else if(choices[i] > 4) score[survey[i][1]] += choices[i] - 4;
    }
    
    if(score['R'] < score['T']) answer += "T";
    else answer += "R";
    
    if(score['C'] < score['F']) answer += "F";
    else answer += "C";
    
    if(score['J'] < score['M']) answer += "M";
    else answer += "J";
    
    if(score['A'] < score['N']) answer += "N";
    else answer += 'A';
    
    
    
    return answer;
}