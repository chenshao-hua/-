#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Findcard{
public:
    void solution(vector<int>& card,int n){
        if(!card.size()||(card.size()%n!=0)){
            cout<<"不存在"<<endl;
            return;
        }
        int numone; 
        vector<int> b;//存储数组，并打印    
        sort(card.begin(),card.end());
#if 0
        for(int i=0;i<card.size();++i)
            cout<<card[i]<<"  ";
        cout<<endl;
#endif

        vector<int>::iterator it=card.begin();
        int number=card.size();
        while(card.size()>0){
            numone=card.front();
            b.push_back(numone);
            it=card.erase(card.begin());  //如果不加it会产生野指针
            int decide=1;
            for(;it!=card.end();){//!(b.size()%n)
                if((*it==numone+1)&&decide!=number/n){
                    ++numone;
                    b.push_back(*it); 
                    it=card.erase(it);
                    //it=card.begin(); //如果不加it会产生野指针
                    ++decide;
                }
                else
                   ++it;
            }
            if(number!=decide*n){
                cout<<"不存在"<<endl;
                break;   
            }
        }
        for(int i=0;i<b.size();++i){
            cout<<b[i]<<"  ";
            if(!((i+1)%((number/n))))
                 cout<<endl;
        }  
    }
};
int main(int argc,char* argv[]){
    int temp[8]={2,1,3,10,8,4,6,7};
    vector<int> cd(temp,temp+8);
    Findcard fcd;
    fcd.solution(cd,2);
    return 0;
}
