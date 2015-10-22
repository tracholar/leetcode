#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cmin , *P, s,Pmax,Q;
		s= prices.size();
		P = new int[s];
		if(s<=1){
			return 0;
		} 
		cmin = prices[0];
		P[0] = 0;

		for(int i=1;i<s;i++){
			if(prices[i]<cmin){
				cmin = prices[i];
			}
			P[i] = max(prices[i] - cmin, P[i-1]);
		} 

		Pmax = P[s-1];
		int cmax = prices[s-1];
		Q = 0;
		for(int i=s-2; i>=0;i--){
			if(prices[i]>cmax) cmax=prices[i];
			Q = max(Q, cmax-prices[i]);
			Pmax = max(Pmax, P[i]+Q);
		}

		return Pmax;
    }
};

int main(){
	Solution s;
	int a[] = {1,-2,3,2,3};
	vector<int> v; 
	for(int i=0;i<5;i++){
		v.push_back(a[i]);
	}
	cout<<s.maxProfit(v)<<endl;
	getchar();
}