#include <iostream>
#include <vector>

#define TARGET 2020
#define MIN_SIZE_ONE 2
#define MIN_SIZE_TWO 3

using namespace std;

// 0, 1, 2, 3, 4, 5

int solve_part_one(vector<int> nums) {
  vector<int> ret(MIN_SIZE_ONE);

  for(int i = 0; i < nums.size() - 1; i++) {
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

int solve_part_two(vector<int> nums) {
  vector<int> ret(MIN_SIZE_TWO);

  for(int i = 0; i < nums.size() - 2; i++) {
    ret[0] = nums[i];
    for(int j = i + 1; j < nums.size() - 1; j++) {
      ret[1] = nums[j];
      for(int k = j + 1; k < nums.size(); k++) {
        if(nums[i] + nums[j] + nums[k] == TARGET) {
          ret[2] = nums[k];
          return ret[0] * ret[1] * ret[2];
        }
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
  
  cout << "Part one result: " << solve_part_one(nums) << endl;
  cout << "Part two result: " << solve_part_two(nums) << endl;

  return 0;
}