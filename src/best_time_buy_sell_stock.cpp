#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cmin , P=0, s;
		s= prices.size();
		if(s<=1){
			return 0;
		} 
		cmin = prices[0];
		for(int i=1;i<s;i++){
			if(prices[i]<cmin){
				cmin = prices[i];
			}
			else if(P<prices[i] - cmin) P = prices[i] - cmin;
		} 
		return P;
    }
};

int main(){
	Solution s;
	int a[] = {1,-2,3,2};
	vector<int> v; 
	for(int i=0;i<4;i++){
		v.push_back(a[i]);
	}
	cout<<s.maxProfit(v)<<endl;

}