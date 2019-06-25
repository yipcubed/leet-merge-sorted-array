#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <climits>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) {
  os << "[";
  for (int i : v) {
    os << i << " ";
  }
  os << "]";
  return os;
}

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // fill from back
        int loc = nums1.size() - 1;
        int total = m + n;
        for (int i = 0; i < total; ++i) {
          if (m == 0) {
            nums1[loc--] = nums2[--n];
            continue;
          }
          if (n == 0) {
            nums1[loc--] = nums1[--m];
            continue;
          }
          if (nums1[m-1] >= nums2[n-1]) {
            nums1[loc--] = nums1[--m];
          } else {
            nums1[loc--] = nums2[--n];  
          }
        }
        // shift m if not at beginning of m
        // cout << "loc: " << loc << endl;
        int tomove = nums1.size() - total;
        for (int i = 0; i < total; ++i) {
          nums1[i] = nums1[i+tomove];
        }
        for (int i = total; i < nums1.size(); ++i) {
          nums1[i] = 0;
        }
    }
};


void test1() {
  Solution S;
  vector<int> m1{1,2,3,0,0,0, 0, 0, 0, 0};
  vector<int> n1{4,5,6};
  S.merge(m1, 3, n1, 3);
  cout << "1,2,2,3,5,6 ? " << m1 << endl;
}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}


