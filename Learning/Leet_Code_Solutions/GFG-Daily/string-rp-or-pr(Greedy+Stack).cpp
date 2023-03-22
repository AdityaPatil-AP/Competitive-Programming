class Solution{   
public:
    long long solve(int X,int Y,string s){
      //code here
      
      long long ans = 0;
      string a = "pr";
      string b = "rp";
      
      if(X < Y){
          swap(a, b);
          swap(X, Y);
      }
      
      stack<char> st;
      
      for(int i = (int)s.size() - 1;i >= 0;i--){
          if(st.size() > 0 && st.top() == a[1] && s[i] == a[0]){
              st.pop();
              ans += X;
          }
          else{
              st.push(s[i]);
          }
      }
      
      
      string newS = "";
      while(!st.empty()){
          newS.push_back(st.top());
          st.pop();
      }
      
      for(int i = (int)newS.size() - 1;i >= 0;i--){
          if(st.size() > 0 && st.top() == b[1] && newS[i] == b[0]){
              st.pop();
              ans += Y;
          }
          else{
              st.push(newS[i]);
          }
      }
      
      return ans;
      
    //   stack<char> st1;
    //   stack<char> st2;
    //   string create;
    //   if(X > Y){
    //       create = "pr";
    //   }
    //   else{
    //       create = "rp";
    //   }
      
    //   long long ans = 0;
      
    //   for(int i = 0;i < s.size();i++){
    //       if(s[i] != create[0] && s[i] != create[1]){
    //           while(!st1.empty() && !st2.empty()){
    //               ans += min(X, Y);
    //               st1.pop();
    //               st2.pop();
    //           }
    //           while(!st2.empty()){
    //               st2.pop();
    //           }
    //           while(!st1.empty()){
    //               st1.pop();
    //           }
    //       }
    //       if(s[i] == create[0]){
    //           st1.push(create[0]);
    //       }
    //       else if(s[i] == create[1] && !st1.empty()){
    //           if(!st1.empty()){
    //               st1.pop();
    //                 ans += max(X, Y);
    //           }
    //       }
    //       else if(s[i] == create[1]){
    //           st2.push(create[1]);
    //       }
    //   }
      
    //   while(!st1.empty() && !st2.empty()){
    //       ans += min(X, Y);
    //       st1.pop();
    //       st2.pop();
    //   }

      return ans;
    }
};