#include <string>
#include <vector>
#include <map>

using namespace std;

// map 으로 시간복잡도 줄이도록 설계

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> runner;
    
    for(string run : participant){
        runner[run]++;
    }
    
    for(string complete : completion){
        runner[complete]--;
    }
    
    for(auto p : runner){
        if(p.second > 0) return p.first;
    }
}