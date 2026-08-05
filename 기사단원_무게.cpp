#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> weapon;
    
    for(int i = 1; i <= number; i++){
        int count = 0;
        for (int j = 1; j * j <= i; j++){
            if(i % j == 0){
                if (j * j == i) count++;
                else count += 2;
            }
        }
        if(count > limit) weapon.push_back(power);
        else weapon.push_back(count);
    }
    answer = accumulate(weapon.begin(), weapon.end(), 0);
    return answer;
}