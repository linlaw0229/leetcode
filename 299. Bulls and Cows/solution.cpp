/*
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:

Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
Example 2:

Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        //1. get how many A, if position and character both equal
        //2. store the Cows
        //3. check how many cows in guess
        unordered_map<char, int> correctmap;
        int A= 0, B= 0;
        for(int i= 0; i< secret.length(); i++){
            if(secret[i] == guess[i])
                A++;
            else
                correctmap[secret[i]]++;
            //secret: 1234, guess: 1299
            //correctmap[3]= 1, correctmap[4]= 1
        }
        
        for(int i= 0; i< guess.length(); i++){
            if(secret[i]!= guess[i] && correctmap[guess[i]]>0){
                B++;
                correctmap[guess[i]]--;
            }
        }
        
        return to_string(A)+"A"+to_string(B)+"B";
    }
};