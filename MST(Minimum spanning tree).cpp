#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
int parent[MAXN], ranks[MAXN]; // parent stores the parent of each node in the disjoint-set forest, and ranks stores the rank or height of each node's subtree in the forest.

struct Edge {
    int u, v; // u and v represent the two endpoints of an undirected edge.
    int w; // w represents its weight.
    //  (u, v) is two vertex and w  is weight.
};

Edge edges[MAXN]; // The data type of each element in the array is Edge.

int find(int x) { // find the representative (root) of a set in a disjoint-set. x is not a root itself,
    // but x is a vertex whose parent is being found recursively until the root of the set containing x is reached.
    if (parent[x] != x) { // x is the element for which we want to find the representative (root) of its set in the disjoint-set.
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {
        //cout << "x and y are already in the same set\n";
        return;
    }
    if (ranks[x] < ranks[y]) {
        swap(x, y); // the value of x will be assigned to y, and the value of y will be assigned to x.
        parent[y] = x;
    }
    if (ranks[x] == ranks[y]) {
        ranks[x]++;
    }
}

int main() {
    int n, m; // n is the  and m is the size of edges.
    cout << "Enter size of vertexes vertex and size of edges edge: ";
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        cout << "Enter u and v vertexes and w weight: ";     //  (u, v) is two vertex and w  is weight.
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].u = u; // if i is 3 and u is 2, then the value of edges[3].u will be set to 2. This is used to store the endpoints and weight of each edge in the graph.
        edges[i].v = v;
        edges[i].w = w;
    }

    sort(edges+1, edges+m+1, [](Edge& a, Edge& b) {
        return a.w < b.w;
    });

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        Edge e = edges[i];
        if (find(e.u) != find(e.v)) {
            merge(e.u, e.v);
            ans += e.w;
        }
    }

    cout << "So the minimum spanning tree is: " << ans << endl;
    return 0;
}

/*
Enter size of vertexes vertex and size of edges edge: 5 7
Enter u and v vertexes and w weight: 1 2 1
Enter u and v vertexes and w weight: 1 3 2
Enter u and v vertexes and w weight: 1 4 3
Enter u and v vertexes and w weight: 2 4 4
Enter u and v vertexes and w weight: 2 5 5
Enter u and v vertexes and w weight: 3 4 6
Enter u and v vertexes and w weight: 4 5 7
*/
