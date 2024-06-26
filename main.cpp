bool compare1(vector<int>&A, vector<int>&B)
{
    int opt1 = min(-A[0], -A[0] + A[1] -B[0]) ;
    int opt2 = min(-B[0], -B[0]+B[1]-A[0]) ;
    
    if(opt1 < opt2) return true ;
    if(opt1 > opt2) return false ;
    
    return A[0] > B[0] ;
}
    

class Solution {
public:
    
    bool canSolve(vector<vector<int>>&A, long long mid)
    {        
        for(int i=0; i<A.size(); i++)
        {
            if(mid < A[i][0]) return false ;
            
            mid = mid - (long)A[i][0] + (long)A[i][1] ; 
        }
        
        return true;
    }
    
    

    long long Solve(vector<vector<int>>&A)
    {
        long long start = 0 , end = LONG_MAX ;
        
        while(start < end)
        {
            if(end-start==1) break; 
            
            long long mid = start + (end-start)/2 ;
            
            if(canSolve(A,mid)) {
                end = mid ;
            }
            else{
                start = mid;
            }
        }
        
        if(canSolve(A,start)) return start ;
        
        return end;         
    }
    
    long long minimumMoney(vector<vector<int>>& A) {
     
        long long Ans = -1e9 ;        
        sort(A.begin(),A.end(), compare1) ; 
        Ans = max(Ans,Solve(A)) ;
        return Ans ;
    }
};
