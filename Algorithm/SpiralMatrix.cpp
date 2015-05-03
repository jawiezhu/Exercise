#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int> >generateMatrix(int n) {
        int m=0;
        vector<vector<int> >a;
        a.resize(5,vector<int>(5));
        int x=0;
        int y=0;
        m=a[0][0]=1;

for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
        while(m<n*n)
        {
            while(y<n-1&&a[x][y+1]==0)
            {   
                y++;
                m++;
                a[x][y]=m;
                cout<<"[1]x:"<<x<<" "<<"y:"<<y<<" "<<a[x][y]<<endl;
                //m++;
                //y++;
                cout<<"y:"<<y<<endl;

            }
            while(x<n-1&&a[x+1][y]==0)
            {
                x++;
                m++;
                a[x][y]=m;
                cout<<"[2]x:"<<x<<" "<<"y:"<<y<<" "<<a[x][y]<<endl;
                //m++;
                //x++;
            }
           
            while(y-1>=0&&a[x][y-1]==0)
            {
                y--;
                m++;
                a[x][y]=m;
                cout<<"[3]x:"<<x<<" "<<"y:"<<y<<" "<<a[x][y]<<endl;
                //m++;
                //y--;
                cout<<"y:"<<y<<endl;
            }

            
            while(x-1>=0&&a[x-1][y]==0)
            {
                x--;
                m++;
                a[x][y]=m;
                cout<<"[4]x:"<<x<<" "<<"y:"<<y<<" "<<a[x][y]<<endl;
                //m++;
                //x--;
            }


        }   

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
        return a;
    }
};




int main()
{
    Solution s;
    
    s.generateMatrix(2);
    

    return 0;
}