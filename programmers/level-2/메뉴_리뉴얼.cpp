#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

void combination(string order, string menu, int start, int target,
                map<string, int>& cnt){
    
    
    // target 에 맞을 때까지 단어를 한 칸씩 옮기며 조합
    // target 에 맞다면 매핑값 +1
    if(menu.size() == target){
        cnt[menu]++;
        return; // 재귀 직전의 상태로 돌아가는 것 
    }
    
    // order 의 length에 도달했을 때 다음 course 로 가는 것 (solution 함수로 돌아감 )
    for(int i = start; i<order.length(); i++){
        combination(order, menu + order[i], i+1, target, cnt);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> cnt;
    
    for(string order : orders){
        sort(order.begin(), order.end());
            
        for(int c : course){
            combination(order, "", 0, c, cnt);
        }
    }
    
    for(int c : course){
        int max_count = 0;
        
        for(auto& p : cnt){
            if(p.first.length() == c){
                max_count = max(max_count, p.second);
            }
        }
        
        if(max_count >= 2){
            for(auto& p : cnt){
                if(p.first.length() == c && p.second == max_count)
                    answer.push_back(p.first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}