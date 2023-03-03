#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int table[501][501] = {0, };

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int len = triangle.size();
    
    table[0][0] = triangle[0][0];
    
    for(int y=1; y<len; y++)
    {
        for(int x=0; x<triangle[y].size(); x++)
        {
            if(x == 0)
                table[y][x] = table[y-1][x] + triangle[y][x];
            else
                table[y][x] = triangle[y][x] + max(table[y-1][x], table[y-1][x-1]);
        }
    }
    
    for(int i=0; i<len; i++)
    {
        answer = max(answer, table[len-1][i]);
    }
    
    return answer;
}