#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> s;
vector<int> v[10];
int container[4] = {0, };

int solution(int N, int number) {
    int answer = 0;
    string str = "";
    int temp = 0;
    
    s.insert(0);
    v[0].push_back(0);
    
    for(int i=1; i<=8; i++)
    {
        str += to_string(N);
        temp = stoi(str);
        
        s.insert(temp);
        v[i].push_back(temp);
    }
    
    for(int i=1; i<=8; i++)
    {
        for(int j=0; j<=i/2; j++)
        {
            // 큰 개수의 벡터
            for(int k=0; k<v[i-j].size(); k++)
            {
                // 작은 개수의 벡터
                for(int l=0; l<v[j].size(); l++)
                {
                    // 연산군!
                    container[0] = v[i-j][k] + v[j][l];
                    container[1] = v[i-j][k] - v[j][l];                    
                    container[2] = v[i-j][k] * v[j][l];
                    if(v[i-j][k] != 0 && v[j][l] != 0)
                        container[3] = v[i-j][k] / v[j][l];
                    else
                        container[3] = 0;
                    
                    for(int m=0; m<4; m++)
                    {
                        if(container[m] == number)
                        {
                            return i;
                        }
                        
                        if(s.find(container[m]) == s.end())
                        {
                            s.insert(container[m]);
                            v[i].push_back(container[m]);
                            
                            if(s.find(-container[m]) == s.end())
                            {
                                s.insert(-container[m]);
                                v[i].push_back(-container[m]);
                            }
                        }
                    }
                }
            }
        }
    }
    
    return -1;
}