#include<iostream>
using namespace std;


class Solution {
public:
    bool isNumber(string str) {
        bool start_flag = false, sign = false, point = false, expflag = false, digit = false, end = false;
        int i=0, n=0;
        while(i < str.length()){
            if(!start_flag){
                if(str[i] == ' ') {
                    i++;
                    continue;
                }
                if(str[i] != '-' && str[i] != '+' && str[i] != '.' && !(str[i]>= '0' && str[i] <= '9')) return false;
                else start_flag = true;
            }

            if(!sign && !end && !digit && !point && (str[i] == '-' || str[i] == '+')) sign = true;
            else if(!end && isdigit(str[i])) {
                digit = true;
            }else if(!point &&!end &&!expflag && str[i] == '.'){
                point = true;
            }else if(!expflag &&!end && digit && str[i] == 'e'){
                expflag = true;
                point = false;
                sign = false;
                digit = false;
            }else if(str[i] == ' '){
                end = true;
            }else{
                return false;
            }

            i++;
        }
        if(!digit) return false;
        return true;
    }
};

int main(){
    Solution s;

    bool r = s.isNumber("0454");
    assert(r == true);

    r = s.isNumber("0");
    assert(r == true);

    r = s.isNumber(" 0.1 ");
    assert(r == true);

    r = s.isNumber("abc");
    assert(r == false);

    r = s.isNumber("1 a");
    assert(r == false);

    r = s.isNumber("2e10");
    assert(r == true);

    r = s.isNumber(" -90e3   ");
    assert(r == true);

    r = s.isNumber(" 1e");
    assert(r == false);

    r = s.isNumber("e3");
    assert(r == false);

    r = s.isNumber(" 6e-1");
    assert(r == true);

    r = s.isNumber(" 99e2.5 ");
    assert(r == false);

    r = s.isNumber("53.5e93");
    assert(r == true);

    r = s.isNumber(" --6 ");
    assert(r == false);

    r = s.isNumber("-+3");
    assert(r == false);

    r = s.isNumber("95a54e53");
    assert(r == false);

    r = s.isNumber(" ");
    assert(r == false);

    r = s.isNumber(".1");
    assert(r == true);

    r = s.isNumber(".e1");
    assert(r == false);

    r = s.isNumber("6+1");
    assert(r == false);

    r = s.isNumber(".-4");
    assert(r == false);

}