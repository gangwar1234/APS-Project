#ifndef xxx
#define xxx

class linkCut
{
 
 public:    
 struct Node
{
    int Left, Right, Parent;
    int PP;
};

linkCut()
{

}

Node Link_cut[MAX_N];

int n, m;
int p,q;



 void make_tree(int v)
{
    if (v == -1) return;
    Link_cut[v].Left =-1;
    Link_cut[v].Right =-1;
    Link_cut[v].Parent =-1;
    Link_cut[v].PP = -1;
}

void rotate(int v)
{
    if (v == -1) return;
    if (Link_cut[v].Parent == -1) return;
    int p = Link_cut[v].Parent;
    int g = Link_cut[p].Parent;
    if (Link_cut[p].Left == v)
    {
        Link_cut[p].Left = Link_cut[v].Right;
        if (Link_cut[v].Right != -1)
        {
            Link_cut[Link_cut[v].Right].Parent = p;
        }
        Link_cut[v].Right = p;
        Link_cut[p].Parent = v;
    }
    else
    {
        Link_cut[p].Right = Link_cut[v].Left;
        if (Link_cut[v].Left != -1)
        {
            Link_cut[Link_cut[v].Left].Parent = p;
        }
        Link_cut[v].Left = p;
        Link_cut[p].Parent = v;
    }
    Link_cut[v].Parent = g;
    if (g != -1)
    {
        if (Link_cut[g].Left == p)
        {
            Link_cut[g].Left = v;
        }
        else
        {
            Link_cut[g].Right = v;
        }
    }
    Link_cut[v].PP = Link_cut[p].PP;
    Link_cut[p].PP = -1;
}




//splay trees are used to represent the auxillary tree which represents each preffered path by splay tree keyed by depth

//root of aux tree stores path parent =paths top nodes parent in represented tree
 void splay(int v)
{
    if (v == -1) return;
    while (Link_cut[v].Parent != -1)
    {
        int p = Link_cut[v].Parent;
        int g = Link_cut[p].Parent;
        if (g == -1) // zig
        {
            rotate(v);
        }
        else if ((Link_cut[p].Left == v) == (Link_cut[g].Left == p)) // zig-zig
        {
            rotate(p);
            rotate(v);
        }
        else // zig-zag
        {
            rotate(v);
            rotate(v);
        }
    }
}




 void access(int v)
{
    if (v == -1) return;
    splay(v);
    if (Link_cut[v].Right != -1)
    {
        Link_cut[Link_cut[v].Right].PP = v;
        Link_cut[Link_cut[v].Right].Parent = -1;
        Link_cut[v].Right = -1;
    }
    while (Link_cut[v].PP != -1)
    {
        int w = Link_cut[v].PP;
        splay(w);
        if (Link_cut[w].Right != -1)
        {
            Link_cut[Link_cut[w].Right].PP = w;
            Link_cut[Link_cut[w].Right].Parent = -1;
        }
        Link_cut[w].Right = v;
        Link_cut[v].Parent = w;
        splay(v);
    }
}




 int find_root(int v)
{
    if (v == -1) return -1;
    access(v);
    int ret = v;
    while (Link_cut[ret].Left != -1) ret = Link_cut[ret].Left;
    access(ret);
    return ret;
}




 void link(int v, int w) 
{
    if (v == -1 || w == -1) return;
    access(w);
    Link_cut[v].Left = w; 
    Link_cut[w].Parent = v;
    Link_cut[w].PP = -1;
}




 void cut(int v)
{
    if (v == -1) return;
    access(v);
    if (Link_cut[v].Left != -1)
    {
        Link_cut[Link_cut[v].Left].Parent = -1;
        Link_cut[Link_cut[v].Left].PP = -1;
        Link_cut[v].Left = -1;
    }
}




int LongestCommonAncestor(int p, int q)
{
    access(p);
    splay(q);
    if (Link_cut[q].Right != -1)
    {
        Link_cut[Link_cut[q].Right].PP = q;
        Link_cut[Link_cut[q].Right].Parent = -1;
        Link_cut[q].Right = -1;
    }
    
    int ret = q, t = q;
    while (Link_cut[t].PP != -1)
    {
        int w = Link_cut[t].PP;
        splay(w);
        if (Link_cut[w].PP == -1) ret = w;
        if (Link_cut[w].Right != -1)
        {
            Link_cut[Link_cut[w].Right].PP = w;
            Link_cut[Link_cut[w].Right].Parent = -1;
        }
        Link_cut[w].Right = t;
        Link_cut[t].Parent = w;
        Link_cut[t].PP = -1;
        t = w;
    }
    splay(q);
    
    return ret;
}
};
#endif