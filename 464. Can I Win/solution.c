/*
In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
*/

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) return true; 
        //example: can choose from 1...15, target=2. can win
        
        if(maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal) return false; 
        //sum of 1...15 not greater than target, and we can not re-use, so can not win
        
        unordered_map<int, bool> m;
        return canWin(maxChoosableInteger, desiredTotal, 0, m);
    }
    
    bool canWin(int length, int total, int used, unordered_map<int, bool>& m){
        //length: maxChoosableInteger
        //total: target left
        //used: denotes the numbers already used, from binary to decimal, example: 1101. 1st,2nd,4th number already used
        if(m.count(used)) return m[used];//because we use a map to store the result, memorization helps to skip duplicate calculation 
        
        for(int i= 0; i< length; i++){
            int cur= (1<< i); //ith number to check
            if((cur & used == 0)){ //not used
                if(total <= i+1 || !canWin(length, total- (i+1), cur|used, m)){ //add already used number to cur through or(|) mask
                    m[used]= true;
                    return true;
                }
            }
        }
        m[used]= false;
        return false;
    }
};