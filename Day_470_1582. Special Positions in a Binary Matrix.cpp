class Solution {
public:
    bool rowc(vector<vector<int>>& mat,int x,int y){
        int m = mat.size() ;
        int n = mat[0].size() ;

        for(int j=0 ;j<n ;j++){
            if(y!=j){
                if(mat[x][j]) return false ;
            }
        }

        return true ;
    }

    bool colc(vector<vector<int>>& mat,int x,int y){
        int m = mat.size() ;
        int n = mat[0].size() ;

        for(int j=0 ;j<m ;j++){
            if(x!=j){
                if(mat[j][y]) return false ;
            }
        }

        return true ;
    }


    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0 ;
        int m = mat.size() ;
        int n = mat[0].size() ;

        for(int i=0 ;i<m ;i++){
            for(int j=0 ;j<n ;j++){
                if(mat[i][j] == 1 && rowc(mat,i,j) && colc(mat,i,j)) ans++ ;
            }
        }

        return ans ;
    }
};