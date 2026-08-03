#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int row = wallpaper.size();
    int col = wallpaper[0].length();
    // 초기화 
    int top = row;
    int bottom = 0;
    int left = col;
    int right = 0;
    
    for(int r = 0; r<row; r++){
        for (int c = 0; c<col; c++){
            if(wallpaper[r][c] == '#'){
                top = min(top,r);
                bottom = max(bottom,r);
                left = min(left, c);
                right = max(right, c);
            }
        }
    }
    answer.push_back(top);
    answer.push_back(left);
    // 인덱스가 0부터 시작하기 때문에 +1 해줘야함
    answer.push_back(bottom+1);
    answer.push_back(right+1);
    return answer;
}