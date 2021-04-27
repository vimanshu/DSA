// question:-
// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.


void sol_subsets(vector<int> &nums, int index , vector<vector<int>> &ans, vector<int> &subset){
    ans.push_back(subset);
    for(int i=index;i<nums.size();i++){
        subset.push_back(nums[i]); // pushing in the subset vector
        sol_subsets(nums,i+1,ans,subset);
        subset.pop_back(); // popping out of the subset vector
    }
}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        vector<int> subset;
        sol_subsets(nums,0,ans,subset);
        return ans;
    }
};
