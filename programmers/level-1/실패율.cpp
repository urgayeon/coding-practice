#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>


using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, double> fail; // 분수 형태니까 double type 
    
    for(int i = 1; i <= N; i++){
        int stage_count = 0;
        stage_count = count(stages.begin(), stages.end(), i); // i번 스테이지에 머무르고 있는 사람 
        int success = 0; // i번 스테이지에 도달한 사람 
        
        for(int j = 0; j<stages.size(); j++){
            if(i <= stages[j]) success++;
            continue;
        }
        if (success == 0)
            fail[i] = 0.0;
        else
            fail[i] = static_cast<double>(stage_count) / success; 
    }
    // ☆ map 의 value 를 기준으로 정렬하여 그 기준에 맞춰 정렬된 key 반환하는 법
    vector<pair<int, double>> v(fail.begin(), fail.end());
    
    // ☆ sort 함수 정렬 기준 직접 정하는 법 
    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        // 실패율이 같은 경우
        if(a.second == b.second) return a.first < b.first;
            
        return a.second > b.second; // 내림차순 
    });
    
    for (const auto& p : v) // 복사 없이 원본(v)을 읽기만 함 
        answer.push_back(p.first);
    
    return answer;
}