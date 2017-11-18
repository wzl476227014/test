/*
 * File Name   : 90.cpp
 * Author      : Andrew ()
 * Description :
 *  version 1.0: 2017-11-18 14:07:50
 */
class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> res(1);
            if(nums.empty())
                return {};
            sort(nums.begin(),nums.end());
            int size= 1;
            int last=nums[0];
            for(int i = 0;i < nums.size();i++){
                if(last!=nums[i]){
                    last=nums[i];
                    size=res.size();
                }
                int newv=res.size();
                for(int j=newv-size;j<newv;j++){
                    res.push_back(res[j]);
                    res.back().push_back(nums[i]);
                }
            }
            return res;
        }

};
