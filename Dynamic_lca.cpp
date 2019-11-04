#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100001
#include "link.h"
typedef long long ll;
int main()
{  
   linkCut tree;
   ll n,m,p,q;
    ifstream in("test.txt");
    if(!in){
        cout<<"Cannot open input file. \n";
        return 0;
    }
    char str[255];
    in.getline(str,255);
     n=stoi(strtok(str," "));
     m=stoi(strtok(NULL,""));   
   // cin>>n>>m;
     //cout<<n<<m<<endl;
   for (int i=1;i<=n;i++) (tree.make_tree(i));
    
    while (m--)
    {    char  *cmd;
          in.getline(str,255);
          cmd=strtok(str," ");
          cout<<cmd<<endl;
          // p=stoi(strtok(NULL," "));
          // q=stoi(strtok(NULL," "));
          cin>>cmd;
        if (strcmp(cmd, "link") == 0)
        {    p=stoi(strtok(NULL," "));
              q=stoi(strtok(NULL," "));
           // cin>>p>>q;
            tree.link(p, q);
        }
        else if (strcmp(cmd, "cut") == 0)
        {     p=stoi(strtok(NULL," "));
              //cin>>p;
            tree.cut(p);
        }
        else if (strcmp(cmd, "lca") == 0)
        {       p=stoi(strtok(NULL," "));
                q=stoi(strtok(NULL," "));
            cin>>p>>q;
              //cout<<p<<q<<endl;
             cout<<(tree.LongestCommonAncestor(p, q))<<endl;
        }
    }
    
    return 0;
}