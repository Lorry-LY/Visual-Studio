#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		vector<int>time;
		while (!timePoints.empty()) {
			string str = timePoints.back();
			timePoints.pop_back();
			stringstream s1(str.substr(0, 2));
			stringstream s2(str.substr(3, 2));
			int minute, second;
			s1 >> minute;
			s2 >> second;
			time.push_back(minute * 60 + second);
			cout << minute << ":" << second << "  " << minute * 60 + second << endl;
		}
		sort(time.begin(), time.end());
		int minTime = 20000;
		for (int i = 0; i < time.size() - 1; i++)
		{
			int t = time[i + 1] - time[i];
			if (t > 1440 / 2) {
				t = 1440 - t;
			}
			if ( t< minTime) {
				minTime = t;
			}
		}
		int t = time.back() - time.front();
		if (t > 1440 / 2) {
			t = 1440 - t;
		}
		if (t < minTime) {
			minTime = t;
		}

		return minTime;
	}
};

int main()
{
	Solution s;
	vector<string>t = {"23:59","00:00"};
	cout<<s.findMinDifference(t);
	return 0;
}