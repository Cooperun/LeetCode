#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

/***********解法一***************/
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		unordered_map<char, int> str;
//		int max = 0;
//		int length = 0;
//		int flag = -1;
//		for (int i = 0; i < s.size(); i++) {
//			if (str.count(s[i])) {
//				if (str[s[i]] < flag) {
//					length++;
//				}
//				else {
//					if (max < length)
//						max = length;
//					length = i - str[s[i]];
//				}
//				if(flag < str[s[i]])
//					flag = str[s[i]];
//			}
//			else {
//				length++;
//			}
//			str[s[i]] = i;
//		}
//		if (max < length)
//			max = length;
//		return max;
//	}
//};

/*****************解法二******************/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max = 0;
		int z = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = z; j < i; j++) {
				if (s[j] == s[i]) {
					z = j + 1;
					break;
				}
			}
			if (max < i - z + 1)
				max = i - z + 1;
		}
		return max;
	}
};
int main() {
	Solution a = Solution();
	int res = a.lengthOfLongestSubstring("blqsearxxxbiwqa");
	cout << res << endl;
	system("pause");
	return 0;
}