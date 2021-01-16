/*
尝试建立一个字典树,支持快速插入单词、查找单词、查找单词前缀的功能.

Example 1:
Trie trie=new Trie();
trie.insert("apple");
trie.search("apple");  //true
trie.search("app");    //false
trie.startsWith("app");//true
trie.insert("app");   
trie.search("app");     //true

字典树(Trie)用于判断字符串是否存在或者是否具有某种字符串前缀.为什么需要用字典树解决这类问题呢?假如有一个
存储了近万个单词的字典,即使使用哈希,在其中搜索一个单词的实际开销也是非常大的,且无法轻易支持搜索单词前缀,
然而由于一个英文单词的长度n通常在10以内,如果使用字典树,则可以在O(n)-近似O(1)的时间内完成搜索,且额外的
开销非常小.查找S是否存在一个字符串,从根节点出发沿着某条路径出发,如果最后成功到达一个终结点,则就说明S在
Trie树中如果最后无路可走,或者到达一个不是终结点的节点,就说明S不在Trie树中;注意,这个所谓的终结点是
是代码标记的终结点,并不是所谓的叶子节点.

可以将字母转换为0-25的索引下标;
*/
#include <iostream>

using namespace std;

class TrieNode{
public:
    TrieNode *childNode[26];/*26个字母*/
    bool isVal;  /*初始为false*/
    TrieNode():isVal(false){
        for(int i=0;i<26;++i){
            childNode[i]=nullptr;
        }
    }
};

class Trie{
private:
    TrieNode* root;

public:
    Trie():root(new TrieNode()){}

    /*向字典树插入一个词*/
    void insert(string word){
        TrieNode* temp=root;
        for(int i=0;i<word.size();++i){
            if(!temp->childNode[word[i]-'a']){
                temp->childNode[word[i]-'a']=new TrieNode();
            }
            temp=temp->childNode[word[i]-'a'];
        }
        temp->isVal=true; /*此字符的终结点*/
    }

    /*判断字典树里是否有一个词*/
    bool search(string word){
        TrieNode* temp=root;
        for(int i=0;i<word.size();++i){
            if(!temp)  break;  /*达到终结点或无路可走,为空退出*/
            temp=temp->childNode[word[i]-'a'];
        }
        return temp?temp->isVal:false;
    }

    /*判断字典树是否有一个以词开始的前缀*/
    bool startsWith(string prefix){
        TrieNode* temp=root;
        for(int i=0;i<prefix.size();++i){
            if(!temp)  break; /*达到终结点或无路可走,为空退出*/
            temp=temp->childNode[prefix[i]-'a'];
        }
        return temp;/*为nullptr则fasel,否则为true*/
    }
    ~Trie(){
        delete root;
    }
};
int main(int argc,char* argv[]){
    Trie trie;
    trie.insert("apple");
    cout<<trie.search("app")<<endl;
    cout<<trie.search("apple")<<endl;
    cout<<trie.startsWith("appl")<<endl;
    return 0;
}