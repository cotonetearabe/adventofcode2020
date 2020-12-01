#include <iostream>
#include <vector>

#define TARGET 2020
#define MIN_SIZE 2

using namespace std;

int solve(vector<int> nums) {
  vector<int> ret(MIN_SIZE);

  for(int i = 0; i < nums.size(); i++) {
    ret[0] = nums[i];
    for(int j = i + 1; j < nums.size(); j++) {
      if(nums[i] + nums[j] == TARGET) {
        ret[1] = nums[j];
        return ret[0] * ret[1];
      }
    }
  }
  return -1;
}


int main() {
  vector<int> nums;
  vector<int> res;

  int temp;

  while(cin >> temp)
    nums.push_back(temp);
  
  cout << solve(nums) << endl;

  return 0;
}