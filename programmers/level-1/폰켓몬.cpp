#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> phoneketmon;
    int take = nums.size()/2;
    
    for(int num : nums){
        phoneketmon.insert(num);
    }
    
    int phoneketmon_type = phoneketmon.size();
        
    if(phoneketmon_type < take)
        return phoneketmon_type;
    
    else if(phoneketmon_type >= take)
        return take;

}