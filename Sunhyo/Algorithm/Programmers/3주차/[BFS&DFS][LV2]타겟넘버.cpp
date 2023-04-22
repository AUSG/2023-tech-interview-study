#include <string>
#include <vector>
#include <queue>

using namespace std;

int dfs(int result, int target, int n, vector<int> numbers, int size)
{
    int answer = 0;
    int value = 0;
    
    if(n == size)
        return 0;
    
    for(int j=0; j<2; j++)
    {
        value = j == 0 ? numbers[n] : -numbers[n];

        if(n == size-1)
        {
            if(result + value == target)
            {
                answer += 1;
            }
        }

        answer += dfs(result + value, target, n+1, numbers, size);
    }
    
    return answer;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    return dfs(0, target, 0, numbers, numbers.size());
}