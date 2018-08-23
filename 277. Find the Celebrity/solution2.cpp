// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if(n<=1) return n; 

        int candidate = 0; //set first person as candidate

        for(int i=1; i< n; i++){
            if(knows(candidate, i)){ 
                //celebrity don't know anyone else, so if candidate knows i, candidate is definately not celebrity
                
                //Rule 1. If A knows B: A must not be celebrity, B possible
                //Rule 2. If A doesn't know B: A possible, B must not be celebrity.
                candidate = i;
            }
        }

        for(int i=0; i< n; i++){
            if(i<candidate && knows(candidate, i) || !knows(i, candidate)) return -1;
            if(i>candidate && !knows(i, candidate)) return -1;
                //check if candidate indeed does not know any other persons and all other persons know candidate
                //if j does not know candidate, or candidate knows j, return -1;
        }
        return candidate;
    }
};