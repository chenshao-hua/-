#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class StreamCheckerOne {
public:
    StreamCheckerOne(vector<string>& words) {
        //ans.swap(words);// ans.assign(words.begin(),words.end());
        for(auto& word:words){
            ans.insert(word);
        }
        str.clear();
    }
    
    bool query(char letter) {
        str+=letter;
        for(auto& an:ans){
            int n=an.size();
            for(int i=0;i<=str.size()-n;++i){
                if(n<=str.size()&&ans.count(str.substr(i,n))){
                    return true;
                } 
            }
        }
        return false;
    }
private:
    set<string> ans;
    string str;
};

class StreamChecker{
public:
    StreamChecker(vector<string>& words){
        root=new TrieNode();
        for(string word:words){
            TrieNode *node=root;
            //逆序遍历
            for(int i=(int)word.size()-1;i>=0;i--){
                //word[i]-'a'转换下标为0-25
                if(!node->next[word[i]-'a']){//不存在此字符,新建节点
                    node->next[word[i]-'a']=new TrieNode();
                }
                node=node->next[word[i]-'a'];
            }
            node->isWord=true;
        }
    }
    bool query(char letter){
        queryStr.push_back(letter);//push_back只能插入单个字符
        TrieNode* node=root;
        for(int i=(int)queryStr.size()-1;i>=0&&node;i--){
            node=node->next[queryStr[i]-'a'];
            if(node&&node->isWord)//node存在且isWord为真
               return true;
        }
        return false;
    }
private:
    struct  TrieNode{
        bool isWord;
        TrieNode* next[26];
        TrieNode():isWord(false),next{NULL}{}
    };
    TrieNode* root;
    string queryStr;
};



int main(int argc,char* argv[]){
    vector<string> words={"cd","f","kl"};
    StreamChecker* obj=new StreamChecker(words);
    bool ans=obj->query('a');
    return 0;
}