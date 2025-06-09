class Solution {
public:
    long long count(long curr,long next,long n)
    {
        long long ans=0;
        while(curr<=n)
        {
            ans+=(next-curr);
            curr*=10;
            next=min((long)next*10,n+1);
        }
        return ans;
    }
    int findKthNumber(int n, int k) {
        long curr=1;
        k-=1; // WE modfied meaning of k now k mean show many numbers we need to skip 
        while(k>0)
        {
            long cnt=count(curr,curr+1,n);
            if(cnt<=k) // Equal is liye hai taki if cnt is 4 and k is 4 mtlb we can skip all 4
            {
                curr++;
                k-=cnt;
            }
            else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};
