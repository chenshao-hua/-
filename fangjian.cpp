#include <iostream>
#include <vector>

using namespace std;
class solution{
public:
    solution(vector<int> &x):nums(x){}
    int rob(){
        int n=nums.size();//n为nums数组大小
        cout<<n<<endl;
        if(!n){
            cout<<"数组为空..."<<endl;
            return 0;
        }
        if(n==1){
            return nums[0];//如果n为1，代表只有一个房间
        }
        //初始化value数组，value[i]表示前i个房间的最大收益
        vector<int> value(n,0);
        value[0]=nums[0];//初始化value[0]等于nums[0]

        value[1]=max(nums[0],nums[1]);//value[1]等于nums[0]和nums[1]的较大值
        for(int i=2;i<n;++i){//循环计算value数组
        //动态规划的状态方程为，value[i]等于value[i-1]和value[i-2]+nums[i]的较大值
             value[i]=max(value[i-1],value[i-2]+nums[i]);
        }
        return value[n-1];//返回value数组的最后一个元素
    }
private:
    vector<int> nums;  
};

int main(int argc,char* argv[]){
    int _nums[7]={1,3,4,3,0,2,7};
    vector<int> nums(_nums,_nums+7);
    solution so(nums);
    cout<<so.rob()<<endl;
    return 0;
}
