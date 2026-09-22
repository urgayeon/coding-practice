#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool compare(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> number;
    
    for(int num : numbers){
        number.push_back(to_string(num));
    }
    
    sort(number.begin(), number.end(), compare);
    
    for(string num : number){
        answer += num;
    }
    
    if(number[0] == "0") answer = "0";
    return answer;
}