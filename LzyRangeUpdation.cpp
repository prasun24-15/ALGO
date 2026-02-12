class Solution {
public:
    vector<int> segMin,segMax,Lazy;
    void propogate(int i,int l,int r)
    {
        if(Lazy[i] != 0)
        {
            segMin[i]+=Lazy[i];
            segMax[i]+=Lazy[i];
            if(l!=r)
            {
                Lazy[2*i+1]+=Lazy[i];
                Lazy[2*i+2]+=Lazy[i];
            }
            Lazy[i]=0;
        }
    }
    void updateRange(int start,int end,int i,int l,int r,int val)
    {
        propogate(i,l,r);
        if(start > r || l > end) return;
        if(l >= start && r <= end)
        {
            Lazy[i]+=val;
            propogate(i,l,r);
            return;
        }
        int mid=(l+(r-l)/2);
        updateRange(start,end,2*i+1,l,mid,val);
        updateRange(start,end,2*i+2,mid+1,r,val);
        segMin[i]=min(segMin[2*i+2],segMin[2*i+1]);
        segMax[i]=max(segMax[2*i+2],segMax[2*i+1]);
    }
    int findLeftMostZero(int i,int l ,int r)
    {
        propogate(i,l,r);
        if(segMin[i] > 0 || segMax[i] < 0) return -1;
        if(l == r) return l;
        int mid=(l+(r-l)/2);
        int left=findLeftMostZero(2*i+1,l,mid);
        if(left != -1) return left;
        return findLeftMostZero(2*i+2,mid+1,r);
    }
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        segMin.assign(4*n,0);
        segMax.assign(4*n,0);
        Lazy.assign(4*n,0);
        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        for(int r=0;r<n;r++)
        {
            int val=(nums[r] % 2 == 0) ? 1 : -1;
            int prev=-1;
            if(mp.count(nums[r]))
            {
                prev=mp[nums[r]];
            }
            if(prev != -1)
            {
                updateRange(0,prev,0,0,n-1,-val);
            }
            updateRange(0,r,0,0,n-1,val);
            int l = findLeftMostZero(0,0,n-1);
            if(l != -1) maxi=max(maxi,r-l+1);
            mp[nums[r]]=r;
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};
