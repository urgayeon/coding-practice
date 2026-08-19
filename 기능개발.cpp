#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> last;
    
    for(int i = 0; i<progresses.size(); i++){
        int last_thing = 0;
        if((100-progresses[i])%speeds[i] != 0) last_thing = ((100-progresses[i])/speeds[i]) + 1;
        else last_thing = (100-progresses[i])/speeds[i];
        last.push(last_thing);
    }
    
    while(!last.empty()){
        int count = 0;
        int standard = last.front();
        
        while(!last.empty() && last.front() <= standard){
            last.pop();
            count++;
        }
        answer.push_back(count);
    }
    
    return answer;
}