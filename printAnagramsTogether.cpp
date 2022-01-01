class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        int n = string_list.size(),anagCnt = 0;
        bool vis[n] = {false};
        vector<vector<string>> ans(n);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                int cnt1[26] = {0}, s1 = string_list[i].size();
                for(int k=0;k<s1;k++) cnt1[string_list[i][k]-'a']++;
                vis[i] = true;
                ans[anagCnt].push_back(string_list[i]);
                for(int j=i+1;j<n;j++){
                    if(vis[j]==false){
                        int cnt2[26]={0}, s2 = string_list[j].size();
                        bool flag = false;
                        for(int k=0;k<s2;k++) cnt2[string_list[j][k]-'a']++;
                        for(int k=0;k<26;k++){
                            if(cnt1[k]!=cnt2[k]) flag = true;
                        }
                        if(!flag){
                            vis[j] = true;
                            ans[anagCnt].push_back(string_list[j]);
                        }
                    }
                }
                anagCnt++;
            }
        }
        for(int i=anagCnt;i<n;i++) ans.pop_back();
        return ans;
    }
};
