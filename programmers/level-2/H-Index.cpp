#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> citations) {
    int cnt = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int i = 0; i < citations.size(); i++){
        if(cnt >= citations[i]){
            break;
        }
        else {
            cnt++;
        }
    }
    
    
    return cnt;
}