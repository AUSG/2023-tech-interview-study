#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string ss;
	cin >> ss;

	int num = 0;

	vector<int>oper;
	vector<int> numbers;

	for (int i = 0; i < ss.length(); i++) {
		if (ss[i] == '-' || ss[i] == '+') {
			if (ss[i] == '+') {
				oper.push_back(1);
			}
			else {
				oper.push_back(-1);
			}

			numbers.push_back(num);
			num = 0;
		}
		else {
			num = num * 10 + ss[i] - '0';
		}


	}

	bool isminus = false;

	int ans = numbers[0];
	numbers.erase(numbers.begin());

	for (int i = 0; i < oper.size(); i++) {
		if (oper[i] == -1) {
			isminus = true;
		}
		if (isminus) {
			ans -= numbers[i];
		}
		else {
			ans += numbers[i];
		}
	}


	cout << ans;
}