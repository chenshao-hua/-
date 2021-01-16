        if(root==nullptr) return 0;
        int mi=mindepth(root->left),ma=mindepth(root->right);
        if(mi&&ma){
            return min(mi,ma)+1;
        }else{
            return max(mi,ma)+1;
        }