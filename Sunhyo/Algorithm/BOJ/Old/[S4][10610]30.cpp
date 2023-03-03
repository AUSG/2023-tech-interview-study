#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    long long sum;
    string str;

    cin >> str;

    sort(str.begin(), str.end(), greater<>());

    if (str[str.length() - 1] != '0')
        cout << -1;
    else {
        sum = 0;
        for (auto s : str)
            sum += s - '0';
        if (sum % 3 == 0)
            cout << str;
        else
            cout << -1;
    }

    return 0;
}