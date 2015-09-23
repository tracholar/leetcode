#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  P=0, s;
		s= prices.size();
		if(s<=1){
			return 0;
		} 
		for(int i=1;i<s;i++){
			if(prices[i]>prices[i-1]){
				P += prices[i]-prices[i-1];
			}
		} 
		return P;
    }
};

int main(){
	Solution s;
	int a[] = {1,-2,3,1,4};
	vector<int> v; 
	for(int i=0;i<5;i++){
		v.push_back(a[i]);
	}
	cout<<s.maxProfit(v)<<endl;

}