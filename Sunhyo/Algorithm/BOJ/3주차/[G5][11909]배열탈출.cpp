/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <algorithm>

using namespace std;

int arr[2223][2223] = {0, };
int dp[2223][2223] = {0, };

int main()
{
    int N;
    int left, up;
    
    scanf("%d", &N);
    
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            up = dp[i-1][j];
            left = dp[i][j-1];
            
            if(i > 1)
            {
                if(arr[i-1][j] <= arr[i][j])
                    up += arr[i][j] - arr[i-1][j] + 1;
            }

            if(j > 1)
            {
                if(arr[i][j-1] <= arr[i][j])
                    left += arr[i][j] - arr[i][j-1] + 1;
            }
            
            if(i == 1) up = left;
            if(j == 1) left = up;
            
            dp[i][j] = min(up, left);
        }
    }
    
    printf("%d", dp[N][N]);
    
    return 0;
}
