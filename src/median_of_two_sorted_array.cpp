#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        if(n % 2 == 1){
            return findk(nums1, nums2, 0, n1, 0, n2, n/2);
        }else{
            double v1 = findk(nums1, nums2, 0, n1, 0, n2, n/2);
            double v2 = findk(nums1, nums2, 0, n1, 0, n2, n/2 - 1);
            return (v1 + v2)/2;
        }
        
    }
    double findk(vector<int>& nums1, vector<int>& nums2, int i1, int i2, int j1, int j2, int k){ 
        int n1 = i2 - i1, n2 = j2 - j1;
        if(n1 <= 0) return nums2[j1 + k];
        if(n2 <= 0) return nums1[i1 + k];

        if(k == 0){
            return nums1[i1] < nums2[j1] ? nums1[i1] : nums2[j1];
        }
        if(k == 1){
            if(nums1[i1] < nums2[j1]){
                i1++;
                k--;
            }else{
                j1++;
                k--;
            }
            return findk(nums1, nums2, i1, i2, j1, j2, k);
        }


        int m = k/2;
        int m1 = i1 + m, m2 = j1 + m;
        if(m1 >= i2) m1 = i2 - 1;
        if(m2 >= j2) m2 = j2 - 1;
        if(nums1[m1] < nums2[m2]){
            if(m1 > i1){
                k = k - (m1 - i1);
                i1 = m1;
            }else{
                k--;
                i1++;
            }
            
        }else if(nums2[m2] <= nums1[m1]){
            if(m2 > j1){
                k = k - (m2 - j1);
                j1 = m2;
            }else{
                k--;
                j1++;
            }
            
        }
        return findk(nums1, nums2, i1, i2, j1, j2, k);
    }
};


int main(){
    vector<int> nums1, nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    //nums2.push_back(2);
    nums2.push_back(3);
    nums2.push_back(4);
    Solution s;
    double m = s.findMedianSortedArrays(nums1, nums2);
    cout<<m<<endl;
    cout<<"hello cpp!"<<endl;
}