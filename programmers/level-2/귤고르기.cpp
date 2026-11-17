#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

int solution(int k, vector<int> tangerine) {
    map<int, int> tangerineCount;
    
    // map => key - key갯수 할당 
    for(int key: tangerine){
        tangerineCount[key]++;
    }
    
    vector<pair<int, int>> entries(tangerineCount.begin(), tangerineCount.end());

    // value를 기준으로 정렬하기 위해 
    sort(entries.begin(), entries.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    
    int index = 0;
    
    while(k > 0){
        int ent = entries[index].second;
        index++;
        
        if(ent >= k) break;
        
        k -= ent;
    }
    return index;
}

// 하고보니 그리디 알고리즘이었음. 왜냐면 매번 항상 가장 크기가 큰 귤을 선택하게 했으니까. 