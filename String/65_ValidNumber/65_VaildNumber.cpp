#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        vector<unordered_map<string, int>> dfa;
        unordered_map<string, int> state0;
        unordered_map<string, int> state1({{"blank", 1}, {"digit", 2}, {"sign", 3}, {"dot", 4}});
        unordered_map<string, int> state2({{"digit", 2}, {"dot", 5}, {"e", 6}, {"blank", 9}});
        unordered_map<string, int> state3({{"digit", 2}, {"dot", 4}});
        unordered_map<string, int> state4({{"digit", 5}});
        unordered_map<string, int> state5({{"digit", 5}, {"e", 6}, {"blank", 9}});
        unordered_map<string, int> state6({{"sign", 7}, {"digit", 8}});
        unordered_map<string, int> state7({{"digit", 8}});
        unordered_map<string, int> state8({{"digit", 8}, {"blank", 9}});
        unordered_map<string, int> state9({{"blank", 9}});
        dfa.push_back(state0);
        dfa.push_back(state1);
        dfa.push_back(state2);
        dfa.push_back(state3);
        dfa.push_back(state4);
        dfa.push_back(state5);
        dfa.push_back(state6);
        dfa.push_back(state7);
        dfa.push_back(state8);
        dfa.push_back(state9);

        int curState = 1;
        string cond;
        for (auto c: s) {
            if (c >= '0' && c <= '9')
                cond = "digit";
            else if (c == ' ')
                cond = "blank";
            else if (c == '+' || c == '-')
                cond = "sign";
            else if (c == 'e')
                cond = "e";
            else if (c == '.')
                cond = "dot";
            else
                cond = "";

            if (dfa[curState].count(cond) == 0)
                return false;

            curState = dfa[curState][cond];
        }

        int final[] = {2, 5, 8, 9};
        set<int> finalState(final, final+4);
        return finalState.count(curState) != 0;
    }
};
