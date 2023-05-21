class Solution {
public:
    int jump(vector<int>& nums) {
        int size=nums.size();
        if(size==1)
           return 0;
        if(nums[0]>=size)
           return 1;//Consider extreme special cases.
        int index=0;//start.Mark the start positon of elements whose value is count+1 in the array
        int maxindex=0;//end.Recorded the farthest distance that can be reached by taking one more step. 
        int count=1;//count 
        vector<int> vec;//vec[i] represents the minimum number of steps required to jump to the i-th position.
        vec.resize(size,0);
        for(int i=0;i<=nums[0];i++)
        {
            maxindex=max(i + nums[i], maxindex);
            vec[i]=count;
        }//At the beginning,it's a special condition.
        count+=1;
        index=nums[0]+1;
        while(index<size)
        {
            if(maxindex>=size-1)//this means we reach the end of the array, we need to terminate the while-loop. 
            {
                for(int i=index;i<=size-1;i++)
                {
                    vec[i]=count;
                }
                break;
            }
            else
            {
                int maxi=maxindex;
                for(int i=index;i<=maxi;i++)
                {
                    maxindex=max(i + nums[i], maxindex);
                    vec[i]=count;
                }
                count+=1;
                index=maxi+1;//enter the next loop.
            }
        }
        return vec[size-1]; 
    }
};
