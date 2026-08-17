#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    for(string city : cities){
        // 대소문자 처리 -> & => 실제로 값을 변경하는 거니까
        for(char &c : city){
            c = tolower(c);
        }
        
        auto it = find(cache.begin(), cache.end(), city);
        
        // cache 에 있다면 (hit)
        if(it != cache.end()){
            answer += 1;
            
            cache.erase(it); // erase() 는 포인터로 지워야 함 
            cache.push_back(city);
        }
        //cache 에 없다면 (miss)
        else{
            answer += 5;

            if(cache.size() == cacheSize && cacheSize != 0)
                cache.erase(cache.begin());
            else if(cacheSize == 0)
                continue;
            
            cache.push_back(city);
        }
    }
    return answer;
}