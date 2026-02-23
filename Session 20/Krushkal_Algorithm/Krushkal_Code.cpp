class Solution {
  public:
    
    
    int findParent(int x, vector<int> &parent) {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x], parent);
    }
    
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        
        sort(edges.begin(), edges.end(),
             [](vector<int> &a, vector<int> &b) {
                 return a[2] < b[2];
             });
        
        
        vector<int> parent(V);
        for (int i = 0; i < V; i++)
            parent[i] = i;
        
        int mstCost = 0;
        int edgesUsed = 0;
        
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            int pu = findParent(u, parent);
            int pv = findParent(v, parent);
            
            
            if (pu != pv) {
                parent[pv] = pu;   
                mstCost += w;
                edgesUsed++;
                
                if (edgesUsed == V - 1)
                    break;
            }
        }
        
        return mstCost;
    }
};