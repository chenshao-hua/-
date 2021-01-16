package RussianDollEnvelopes;

import java.util.Arrays;

public class RussianDollEnvelopes {
    public int maxEnvelopes(int[][] envelopes){
        Arrays.sort(envelopes,(int[] a,int[] b)->{
            if(a[0]==b[0]){
                return b[1]-a[1];
            }
            return a[0]-b[0];
        });
        int[] heights=new int[envelopes.length];
        for(int i=0;i<envelopes.length;++i){
            heights[i]=envelopes[i][1];
        }
        return back(heights);
    }
    private int back(int[] nums){
        int len=0;
        for(int num:nums){
            int i=Arrays.binarySearch(nums,0,len,num);
            if(i<0){
                i=-(i+1);
            }
            if(i==len){
                len++;
            }
            System.out.println(i);
            nums[i]=num;
        }
        return len;
    }
    public static void main(String[] args){
        int[][] envelopes={{5,4},{6,4},{6,7},{2,3}};
        RussianDollEnvelopes so=new RussianDollEnvelopes();
        System.out.println(so.maxEnvelopes(envelopes));
    }
}
