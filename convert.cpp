#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.size();
		string res = "";
		int t;
		if (len == 1 || len == 0 || len == 2)
			return s;
		for (int i = 0; i < numRows; i++) {
			t = i;
			int space1, space2;
			if (i == 0) {
				space1 = (numRows - 1) * 2;
				space2 = space1;
			}
			else if (i == numRows - 1) {
				space1 = (numRows - 1) * 2;
				space2 = space1;
			}
			else {
				space1 = (numRows - 1 - i) * 2;
				space2 = i * 2;
			}
			int flag = 1;
			while (t < len) {
				res += s[t];
				if (space1 == 0)
					space1 = space2 = 1;
				if (flag==1) {
					t += space1;
					flag = 0;
				}
				else {
					t += space2;
					flag = 1;
				}
			}
		}
		return res;
	}
};

int main() {
	Solution a = Solution();
	cout << a.convert("a", 1) << endl;
	system("pause");
	return 0;
}