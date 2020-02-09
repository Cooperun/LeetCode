
#include <iostream>
#include <vector>
using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		if (m > n) {
			return findMedianSortedArrays(nums2, nums1);
		}
		int b = 0, e = 2 * m;
		double maxL1, maxL2, minR1, minR2;
		while (b <= e) {
			int mid = (b + e) / 2;
			int l_mid = m + n - mid;
			maxL1 = (mid==0)?INT_MIN:nums1[(mid - 1) / 2];
			minR1 = (mid==2*m)?INT_MAX:nums1[mid / 2];
			maxL2 = (l_mid==0)?INT_MIN:nums2[(l_mid - 1) / 2];
			minR2 = (l_mid==2*n)?INT_MAX:nums2[l_mid / 2];
			if (maxL1 > minR2) {
				e = mid - 1;
			}
			else if (maxL2 > minR1) {
				b = mid + 1;
			}
			else {
				break;
			}
		}
		return (max(maxL1, maxL2) + min(minR1, minR2)) / 2;
	}
};


int main(int argc, char *argv[])
{
	vector<int> nums1 = { 1,3, 5 };
	vector<int> nums2 = { 2 };

	Solution solution;
	double ret = solution.findMedianSortedArrays(nums1, nums2);
	cout << ret << endl;
	system("pause");
	return 0;
}