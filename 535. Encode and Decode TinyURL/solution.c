/*
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/

class Solution {
public:
    Solution(){
        dist= "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        short2long.clear();
        long2short.clear();
        srand(time(NULL));
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string _return;
        if(long2short.find(longUrl) != long2short.end())
            _return = long2short[longUrl];
        else{
            int idx= 0;
            string tmp="";
            for(int i = 0; i< 6; i++){
                tmp.push_back(dist[rand() % 62]);
            }
            cout<<tmp<<endl;
            while(short2long.count(tmp)){
                tmp[idx] = dist[rand() % 62];
                idx = (idx +1 )%5;
            }
            short2long[tmp] = longUrl;
            long2short[longUrl] = tmp;
            _return = tmp;
        }
        //cout<< "http://tinyurl.com/"+_return<< endl;
        return "http://tinyurl.com/"+_return;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string _return;
        
        _return = shortUrl.substr(shortUrl.find_last_of('/')+1);
        _return = short2long.count(_return) ? short2long[_return]: shortUrl;
        return _return;
    }
private:
    unordered_map<string, string> short2long, long2short;
    string dist;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
