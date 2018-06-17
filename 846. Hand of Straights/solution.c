/*
Alice has a hand of cards, given as an array of integers.

Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.

Return true if and only if she can.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
Example 2:

Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.
 

Note:

1 <= hand.length <= 10000
0 <= hand[i] <= 10^9
1 <= W <= hand.length
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> map;
        for(int h: hand) ++map[h];
        
        while(!map.empty()){
            auto it= map.begin();
            int start = it->first;
            for(int j= 0; j< W; j++){
                if(it == map.end() || it->first != start +j) //start+j is because we need consecutive
                    return false;
                auto prev = it;
                it++;
                prev->second--;
                if(prev->second == 0){
                    map.erase(prev);
                }
            }
        }
        return true;
    }
};
