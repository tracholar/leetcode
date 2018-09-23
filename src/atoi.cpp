#include<iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i=0, v=0, sign = 1, n=0;
        bool start_flag = false;
        while(i < str.length()){
            if(!start_flag){
                if(str[i] == ' ') {
                    i++;
                    continue;
                }
                if(str[i] != '-' && str[i] != '+' && !(str[i]>= '0' && str[i] <= '9')) return 0;
                else start_flag = true;
            }

            if(n == 0 && str[i] == '-') sign = -1;
            else if(n == 0 && str[i] == '+') sign = 1;
            else if(isdigit(str[i])){
                int c = str[i] - '0';
                if(sign == -1 && -v < (INT_MIN + c)/10) return INT_MIN;
                if(sign == 1 && v > (INT_MAX - c)/10) return INT_MAX;
                v = v * 10 + c;
            }else{
                break;
            }
            
            i++;
            n++;
        }
        return v * sign;
    }
};


int main(){
    Solution s;
    int v = s.myAtoi("48");
    assert(v == 48);

    v = s.myAtoi("   -42");
    assert(v == -42);

    v = s.myAtoi("4193 with words");
    assert(v == 4193);

    v = s.myAtoi("words and 987");
    assert(v == 0);

    v = s.myAtoi("-91283472332");
    assert(v == -2147483648);

    v = s.myAtoi("+1");
    assert(v == 1);

    v = s.myAtoi("-000000000000001");
    assert(v == -1);

    v = s.myAtoi("+-2");
    assert(v == 0);
}