#include<iostream>
using namespace std;


class Solution {
    bool * match;
    bool * match_empty; //是否匹配空字符串
    int sn, pn;
    // i是p的长度-1， j是s的长度-1
    inline bool get(int i, int j){
        assert(i<pn && j<sn);
        if(i < 0) return j<0; // 空模板只匹配空字符串
        if(j < 0){
            if(i<0){ //空字符串匹配空模板
                return true;
            }else{ //空字符串匹配非空模板
                return match_empty[i];
            }
        }
        return match[i * sn + j];
    }
    inline void set(int i, int j, bool v){
        assert(i<pn && j<sn);
        if(j < 0){//空字符串
            assert(i >= 0);
            match_empty[i] = v;
        }else{
            match[i * sn + j] = v;
        }
    }
public:
    bool isMatch(string s, string p) {
        sn = s.length();
        pn = p.length();
        match = new bool[sn*pn];
        //memset(match, 1, sizeof(bool) * sn * pn);
        match_empty = new bool[pn];
        //memset(match, 1, sizeof(bool) * pn);

        // 处理空字符串
        if(sn == 0 && pn == 0) return true;
        //if(sn == 0) return false;
        if(pn == 0) return false;

        // s和p都非空了
        for(int i = 0; i<pn; i++){
            for(int j=-1; j<sn; j++){
                //if(i == 0 && j == 0) continue;
                if(p[i] == '.'){
                    if(j < 0) set(i, j, false); // 如果匹配空字符串，则为false
                    else set(i, j, get(i-1, j-1));
                }else if(p[i] == '*'){
                    //a* 不匹配任何字符串
                    bool v1 = get(i-2, j);
                    // 匹配一个或多个字符
                    bool v2;
                    if(p[i-1]== '.' || (j >=0 && p[i-1] == s[j])){
                        //   匹配多个字符  || 匹配一个字符
                        v2 = get(i, j-1) || get(i-2, j-1);
                    }else{
                        v2 = false;
                    }
                    set(i, j, v1 || v2);
                }else{
                    bool v1 = j>=0 ? (p[i] == s[j]) : false, v2 = get(i-1, j-1);
                    set(i, j, v1 && v2);
                }
            }
        }
        if(sn == 0) //空字符串
            return match_empty[pn - 1];
        else
            return match[sn * pn -1];

        
    }
};

int main(){
    Solution s;
    bool match;
    match = s.isMatch("aa", "a");
    assert(match == false);
    match = s.isMatch("aa", "a*");
    assert(match == true);
    match = s.isMatch("aa", "a.");
    assert(match == true);
    match = s.isMatch("ab", ".*");
    assert(match == true);
    match = s.isMatch("aab", "c*a*b");
    assert(match == true);
    match = s.isMatch("mississippi", "mis*is*p*.");
    assert(match == false);

    match = s.isMatch("a", ".*..a*");
    assert(match == false);

    match = s.isMatch("", ".*");
    assert(match == true);

    //"cacabbabaaabccb"
    //"ab*b*.*a*.*.*b*"
    match = s.isMatch("cacabbabaaabccb", "ab*b*.*a*.*.*b*");
    assert(match == false);

}
