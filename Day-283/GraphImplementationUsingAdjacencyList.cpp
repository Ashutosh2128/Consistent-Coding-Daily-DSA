#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph {
    public:
        unordered_map<int, list<pair<int, int>>> adjacent;

        void addEdges(int u, int v, int w, bool direction) {
            adjacent[u].push_back({v, w});
            if(!direction) adjacent[v].push_back({u, w});
        }

        void printAdjacent(int n) {
            for(int i = 0; i < n; i++) {
                cout << i << ": {";
                for(pair<int, int> p : adjacent[i]) cout << "(" << p.first << ", " << p.second << "), ";
                cout << "}" << endl;
            }
        }
};

int main() {
    Graph g;
    
    g.addEdges(0, 1, 3, 1);
    g.addEdges(0, 2, 4, 1);
    g.addEdges(1, 2, 1, 1);
    g.addEdges(2, 3, 16, 1);

    g.printAdjacent(4);

    return 0;
}









// class Graph {
//     public:
//         unordered_map<int, list<int>> adjacent;

//         void addEdges(int u, int v, bool direction) {
//             // direction - 0: undirected
//             // direction - 1: directed
//             if(direction) adjacent[u].push_back(v);
//             else {
//                 adjacent[u].push_back(v);
//                 adjacent[v].push_back(u);
//             }
//         }

//         void printAdjacent(int n) {
//             for(int i = 0; i < n; i++) {
//                 cout << i << ": {";
//                 for(int it : adjacent[i]) cout << it << ", ";
//                 cout << "}" << endl;
//             }

//             // for(auto it : adjacent) {
//             //     cout << it.first << ": {";
//             //     for(auto i : it.second) cout << i << ", ";
//             //     cout << "}" << endl;
//             // }
//         }
// };

// int main() {
//     Graph g;

//     g.addEdges(0, 1, 1);
//     g.addEdges(0, 2, 1);
//     g.addEdges(1, 2, 1);
//     g.addEdges(2, 3, 1);

//     g.printAdjacent(4);

//     return 0;
// }