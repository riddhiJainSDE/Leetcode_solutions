class Solution {
public:
map<int, int> mpp;
  vector<int> twoSum(vector<int>& nums, int target) {
for(int i=0;i<nums.size();i++){

int remaining=target-nums[i];
if(mpp.find(remaining)!=mpp.end()){

return{mpp[remaining],i};

}
mpp[nums[i]]=i;
}
return{-1,1};
    }
       
};