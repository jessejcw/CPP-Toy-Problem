#include <iostream>
#include "inc_me.h"

int main() {
#include "CountAndSay.h"
    CountAndSay CS;
    string ret = CS.countAndSay(5);

#if 0
    InorderSuccessorOfBST is;
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(1);
    node1->left = node2;
    TreeNode* ret = is.inorderSuccessor(node1, node2);
#endif
#if 0
#include "DecodeWays.h"
    DecodeWays dw;
    int ret = dw.numDecodings("12");
#endif
#if 0
#include "RemoveInvalidParenthesis.h"
    RemoveInvalidParenthesis rp;
    string str = "(()";
    vector<string>  res = rp.removeInvalidParentheses(str);
#endif
#if 0
#include "WordLadder1.h"
    WordLadder1 wl1;
    vector<string> str = {"hot", "dot", "dog", "lot", "log", "cog"};
    int len = wl1.ladderLength("hit", "cog", str);
#endif

#if 0 // blocking_ring
    #include "blocking_ring.h"
    blocking_ring<int, 5> ringBuff;
    ringBuff.push(2);
    ringBuff.push(3);
    ringBuff.push(4);
    ringBuff.push(5);
    ringBuff.push(6);
    int front = ringBuff.front();
    int back = ringBuff.back();
#endif
    return 0;
}