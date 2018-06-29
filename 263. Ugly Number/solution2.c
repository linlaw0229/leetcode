class Solution {
public:
    bool isUgly(int num) {
        if(num> 0){
            for(int i= 2; i< 6; i++){ //2, 3, 4, 5. however, 4 will be divided by 2 
                while(num%i == 0)
                    num/=i;
            }
        }
        return (num== 1);
    }
};