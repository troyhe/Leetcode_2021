class Solution {
public:
    string simplifyPath(string path) {
        deque<string> s;
        string temp = "";
        path += "/";
        for (char c: path){
            if (c == '/'){
                if (!temp.empty()){
                    if (temp == ".."){
                        if (!s.empty()) s.pop_back();
                    } else if (temp != "." && temp != ""){
                        s.push_back(temp);
                    }
                    temp = "";
                }
            } else {
                temp += c;
            }
        }
        if (s.empty()) return "/";
        string ans = "";
        while (!s.empty()){
            ans += "/" + s.front();
            s.pop_front();
        }
        return ans;
    }
};
