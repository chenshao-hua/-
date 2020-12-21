/*求股票出售的最大利润
把数组中的数字以折线图的形式反映,我们发现这就是有波峰和波谷的折线图.而我们要找最大利润,
其实就是我们要找到所有挨得最近的一组波谷和波峰差值的总和;
在这种情况下:只需要一次循环,不停的找某个波谷的值,然后紧接着找到离它最近的一个波峰的值,
他们的差值就是最大利润的一部分;然后接下去再找下一组波谷和波峰;

*/
#include <iostream>
#include <vector>

using namespace std;

class Solutin{
public:
    int maxProfit(vector<int>& prices){
        int peak,valley,maxprofit=0,i=1,n=prices.size();
        while(i<n){
            while(i<prices.size()&&prices[i]-prices[i-1]<=0)
               i++;/*波谷*/
            valley=prices[i-1];
            while(i<prices.size()&&prices[i]-prices[i-1]>=0)
               i++;/*波峰*/
            peak=prices[i-1];
            maxprofit+=peak-valley;
        }
        return maxprofit;
    }
};
int main(int argc,char* argv[]){
    vector<int> prices{7,1,5,3,6,4};
    cout<<Solutin().maxProfit(prices)<<endl;
    return 0;
}