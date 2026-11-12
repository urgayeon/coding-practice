#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 이분탐색 정석 문제 

int solution(vector<int> diffs, vector<int> times, long long limit) {
    // level의 가능한 범위는 diffs의 최솟값과 최댓값 사이의 값
    // 이분 탐색, left/mid/right
    
    int maxDiff = *std::max_element(diffs.begin(), diffs.end());
    
    int left = 1;
    int right = maxDiff;
    int level = maxDiff; // left가 right 끝까지 갈 수 있음 
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        long long totaltime = 0;
        
        for(int i = 0; i < diffs.size(); i++){
            if(diffs[i] <= mid){
                totaltime += times[i];
            }
            else{
                totaltime += (diffs[i]-mid)*(times[i] + times[i-1]) + times[i];
            }
        }
        if(totaltime > limit){ // left ~ mid 에 있는 어떤 값들도 다 시간초과니까 범위를 줄이는 것 
            left = mid + 1;
        }
        else{ // right ~ mid 에 있는 값들은 최솟값에 만족하지 않으니까 범위를 줄이는 것 
            level = mid;
            right = mid - 1;
        }
    }
    return level;
}