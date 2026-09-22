#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 12345 -> 패턴의 길이 5
// 2 1 2 3 2 4 2 5 -> 패턴의 길이 8
// 33 11 22 44 55  -> 패턴의 길이 10 
vector<int> p1 = {1,2,3,4,5};
vector<int> p2 = {2,1,2,3,2,4,2,5};
vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == p1[i%5]){
            s1++;
        }
        if(answers[i] == p2[i%8]){
            s2++;
        }
        if(answers[i] == p3[i%10]){
            s3++;
        }
    }
    
    int largest = std::max({s1, s2, s3});
    
    if(largest == s1) answer.push_back(1);
    if(largest == s2) answer.push_back(2);
    if(largest == s3) answer.push_back(3);

    return answer;
}