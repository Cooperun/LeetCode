#include <iostream>
#include <string>
using namespace std;

//class Solution {
//public:
//	string longestPalindrome(string s) {
//		int **rec = new int*[s.size()];
//		int len = s.size();
//		int max_len = 1;
//		int start = 0;
//		if (len == 0 || len == 1)
//			return s;
//		for (int i = 0; i < s.size(); i++) {
//			rec[i] = new int[s.size()];
//			rec[i][i] = 1;
//			if (i < len - 1 && s[i] == s[i + 1]) {
//				rec[i][i + 1] = 1;
//				max_len = 2;
//				start = i;
//			}
//			else if(i < len - 1){
//				rec[i][i + 1] = 0;
//			}
//		}
//		for (int i = 3; i <= len; i++) {
//			for (int j = 0; j + i - 1 < len; j++) {
//				if (s[j] == s[j + i - 1]&& rec[j + 1][j + i - 2]) {
//					rec[j][j + i - 1] = rec[j + 1][j + i - 2];
//					max_len = i;
//					start = j;
//				}
//				else {
//					rec[j][j + i - 1] = 0;
//				}
//			}
//		}
//		
//		cout << s.substr(start, max_len) << endl;
//
//		return s.substr(start, max_len);
//	}
//};


class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		int max_len = 0;
		int start = 0;
		if (len == 0 || len == 1)
			return s;
		for (int i = 0; i < 2 * len - 2; i++) {
			int j = i / 2, k = (i + 1) / 2;
			int temp = 1;
			if (j == k)
				temp = 1;
			else {
				temp = 0;
			}
			while (j >= 0 && k < len) {
				if (s[j] == s[k]&&j!=k) {
					temp += 2;
				}
				else if (s[j] != s[k]) {
					break;
				}
				j--;
				k++;
			}
			if (max_len < temp) {
				max_len = temp;
				start = j + 1;
			}
		}
		return s.substr(start, max_len);
	}
};


int main() {
	Solution s = Solution();
	cout << s.longestPalindrome("ccc") << endl;
	system("pause");
	return 0;
}