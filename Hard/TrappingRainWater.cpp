class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n);
        vector<int> right(n);
        if(n<=2)return 0;
        left[1]=height[0];
        right[n-2]=height[n-1];
        for(int i=2;i<n;i++)
        {
            left[i]=max(left[i-1], height[i-1]);
            right[n-1-i]=max(right[n-i], height[n-i]);
        }



        
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(left[i]>height[i]&& right[i]>height[i])
            {

                ans+=min(left[i],right[i])-height[i];
            }
        }

        return ans;

    }
};