#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 이분 탐색을 떠올리는 게 관건 

long long solution(int n, vector<int> times) {
    
    int minTimes = *std::min_element(times.begin(), times.end());
    long long right = 1LL * minTimes * n; // minTimes, n 이 다 int 라서 type 변환해야함 
    long long left = 1;
    long long answer = right;
    
    
    while(left <= right){
        long long mid = left + (right-left) / 2;
        long long people = 0;
        
        for(int i = 0; i < times.size(); i++){
            people += mid/times[i];
        }
        
        if(people < n){
            left = mid + 1;
        }
        else{
            answer = mid;
            right = mid - 1;   
        }  
    }
    return answer;
}