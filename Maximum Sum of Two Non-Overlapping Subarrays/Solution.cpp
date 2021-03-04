#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A,int L,int M){
        if(A.size()<L+M) return 0;
        int ans=0;
        for(int i=0;i<A.size()-L+1;++i){
            int lm=0,lmax=0;
            while(lm<L){
                lmax+=A[i+lm];
                lm++;
            }
            int rmax=0;
            if(i-M>=0){
                for(int j=0;j<=i-M;++j){
                    //cout<<i<<" "<<j<<endl;
                    int r1=0,tmp=0;
                    while(r1<M){
                        tmp+=A[j+r1];
                        r1++;
                    }
                    rmax=max(tmp,rmax);
                }
            }
            if(A.size()-i-L>=0){
                for(int j=i+L;j<=A.size()-M;++j){
                    //cout<<i<<" "<<j<<endl;
                    int r1=0,tmp=0;
                    while(r1<M){
                        tmp+=A[j+r1];
                        r1++;
                    }
                    rmax=max(tmp,rmax);
                }
            } 
            ans=max(ans,lmax+rmax); 
        }
        return ans;
    }
    int maxSumTwoNoOverlapOne(vector<int>& A,int L,int M){
        for(int i=1;i<A.size();++i){
            A[i]+=A[i-1];
        }

        int ans=A[L+M-1],Lmax=A[L-1],Mmax=A[M-1];
        //分别以L在前M在后,M在前L在后两种方式,滑动窗口,每次移动一格,其实可以进行拆分
        for(int i=L+M;i<A.size();++i){
            Lmax=max(Lmax,A[i-M]-A[i-M-L]);//L在M之前
            Mmax=max(Mmax,A[i-L]-A[i-M-L]);//M在L之前
            ans=max(ans,max(Lmax+A[i]-A[i-M],Mmax+A[i]-A[i-L]));
        }
        return ans;
    }
};

int main(int argc,char* argv[]){
    vector<int> A={3,8,1,3,2,1,8,9,0};
    int L=3,M=2;
    printf("%d\n",Solution().maxSumTwoNoOverlap(A,L,M));
    printf("%d\n",Solution().maxSumTwoNoOverlapOne(A,L,M));
    return 0;
}