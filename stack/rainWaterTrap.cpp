

#include <bits/stdc++.h>

using namespace std;
int trap(vector<int>& height) {
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());
        int mx=-1;
        for(int i=0; i<height.size();i++){
            maxLeft[i]=mx;
            mx=max(height[i],maxLeft[i]);
           //cout<<"maxL:"<<maxLeft[i]<<" ";
        }
        mx=-1;
        for(int i=height.size()-1; i>=0;i--){
            maxRight[i]=mx;
            mx=max(height[i],maxRight[i]);
        }
        int c=0;
        for(int i=0; i<height.size();i++){
            int x= min(maxLeft[i],maxRight[i])-height[i];
            if(x>0){
                c+=x;
            }
           // cout<<"count: "<<c<<endl;
        }
       return c; 
    }
int main()
{
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height);

    return 0;
}
