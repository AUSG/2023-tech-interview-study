#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> parent;
map<int, int> answers;

int GetParent(int i)
{
    if(parent[i] == i)
        return i;
    else
        return parent[i] = GetParent(parent[i]);
}

void UnionParent(int a, int b)
{
    a = GetParent(a);
    b = GetParent(b);
    
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<computers.size(); i++)
        parent.push_back(i);
    
    for(int i=0; i<computers.size(); i++)
    {
        for(int j=0; j<computers[i].size(); j++)
        {
            if(computers[i][j] == 1)
            {
                UnionParent(i, j);
            }
        }
    }
    
    for(int i=0; i<computers.size(); i++)
    {
        answers[GetParent(i)] = 1;
    }
    
    return answers.size();
}