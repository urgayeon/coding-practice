#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int hp = health;
    int success = 0;
    int attack_last_time = attacks[attacks.size()-1][0];
    int attack_idx = 0;
    
    for(int time = 0; time <= attack_last_time; time++){
        // 공격 시간이라면 
        if(attacks[attack_idx][0] == time){
            hp -= attacks[attack_idx][1];
            attack_idx++;
            success = 0;
            
            if(hp<=0) {
                hp = -1;
                break;
            }
        }
        // 회복 시간이라면
        else{
            hp += bandage[1];
            success++;

            if(success == bandage[0]) {
                hp += bandage[2];
                success = 0;
            }
            
            hp = min(health, hp);
        }
        
    }
    return hp;
}