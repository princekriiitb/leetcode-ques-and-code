class Solution {
public:
    int minInsertions(string s) {
        stack<char> open;
        int count=0;
        int i=0;
       while(s[i]!='\0'){ 
            if(s[i]=='('){
                open.push(s[i]);
                i++;
            }
            else{
                if(s[i+1]==')'){
                    if(open.empty()){
                        count++;
                    }
                    else{ 
                    open.pop();
                    }
                    i+=2;
                }
                else{
                  if(open.empty()){
                    count+=2;
                }
                else{
                    open.pop();
                    count++;
                }
                i++;

                }
            }
        }
        if(open.empty()) return count;
        else return count+(2*open.size());
    }
};