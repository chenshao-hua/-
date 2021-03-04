package SumofThree;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public List<List<Integer>> threeSum(int[] nums){
        Arrays.sort(nums);
        List<List<Integer>> ans=new ArrayList<>();
        for(int k=0;k<nums.length-2;k++){
            if(nums[k]>0)
                break;
            if(k>0&&nums[k]==nums[k-1])
                continue;
            int i=k+1,j=nums.length-1,sum=0;
            while(i<j){
                sum=nums[k]+nums[i]+nums[j];
                if(sum>0){
                    j--;
                }else if(sum<0){
                    i++;
                }else{
                    ans.add(Arrays.asList(nums[k],nums[i],nums[j]));//asList的数组是不能增删的
                    //去除重复元素或者自增,nums[i]->i=i+1->nums[i]==num[i+1]
                    while(i<j&&nums[i]==nums[++i]);
                    while(i<j&&nums[j]==nums[--j]);
                }
            }
        }
        return ans;
    }

    public static void main(String[] args){
        int[] nums={-1,0,1,2,-1,-4};
        new Solution().threeSum(nums).forEach((lists)->{
            for(Integer list:lists){
                System.out.print(list+" ");
            }
            System.out.println();
        });
    }
}
