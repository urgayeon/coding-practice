#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> cnt;
    
    string num = "";
    
    for(char c : s){
        if(c >= '0' && c <= '9'){
            num += c;
        } // ,{,} 이런 것들을 만났을 시
        else{
            if(!num.empty()){
                int n = stoi(num);
                cnt[n]++;
                num = "";
            }
        }
    }
    // ☆ map 의 value 를 기준으로 정렬이 필요할 때 자주 쓰이는 패턴 
    vector<pair<int,int>> v(cnt.begin(), cnt.end());
    
    sort(v.begin(), v.end(), [](auto &a, auto&b){
        return a.second > b.second;
    });
    
    for(const auto& p : v){
        answer.push_back(p.first);
    }
    
    return answer;
}