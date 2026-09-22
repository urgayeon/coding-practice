#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int extent = brown + yellow;
    vector<pair<int, int>> measure;
    
    for(int i = 1; i <= extent; i++){
        if(extent%i == 0){
            measure.push_back({i, extent/i});
        }
    }
    
    for(const auto& p : measure){
        if((p.first-2)*(p.second-2) == yellow && p.first >= p.second){
            answer.push_back(p.first);
            answer.push_back(p.second);
        }
    }
    
    return answer;
}