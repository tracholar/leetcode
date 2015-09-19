#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> retval;
		unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            int j = nums[i];
			if(m.find(target - j)!=m.end()){
				retval.push_back(m[target-j]+1);
				retval.push_back(i+1);
				return retval;
			}

			m[j] = i;
			
        }
		return retval;
    }
};


int main(){
	int arr[] = {2, 7, 11, 15};
	vector<int> numbers;
	int target=9;
	Solution s;
	for(int i=0;i<4;i++){
		numbers.push_back(arr[i]);
	}
	vector<int> p = s.twoSum(numbers, target);
	printf("index1=%d, index2=%d\n",p[0],p[1]);
	getchar();
}
