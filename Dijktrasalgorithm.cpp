#include <fstream>
#include <ctime> 
#include <iostream> 
#include <vector>
#include <iterator>
#include <set>
#include <list>
#include <utility>
#define INF 10000

using namespace std;
class Graph {
private:
    //Vertices
    int V;
    //Pointer to list.
    list<pair<int, int> >* adj;
public:
    // Constructor Prototype
    Graph(int v);
    //Method to add an edge/weight pair
    void addEdge(int v1, int v2, int weight);
    //Method for shortest path
    void shortestPath(int s);

};
Graph::Graph(int v) {
    V = v;

    adj = new list<pair<int, int> >[v];
}
void Graph::addEdge(int v1, int v2, int weight) {
    adj[v1].push_back(make_pair(v2, weight));
}

void Graph::shortestPath(int s) {
    // Create vertices

    set <pair <int, int> > extract_set;

    std::vector<int> distances(V, INF);

    ///INITALIZE DISTANCE TO 0
    extract_set.insert(make_pair(0, s));
    distances[s] = 0;
    while (!extract_set.empty()) {
        pair <int, int> tmp = *(extract_set.begin());
        extract_set.erase(extract_set.begin());

        int u = tmp.second;
        list<pair <int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = (*i).first;
            int weight = (*i).second;
            int q = distances[u] + weight;
            ///SHORTEST PATH
            if (distances[v] > q) {
                if (distances[v] != INF) {
                    extract_set.erase(extract_set.find(make_pair(distances[v], v)));
                }
                distances[v] = distances[u] + weight;
                extract_set.insert(make_pair(distances[v], v));
            }
        }
    }
    std::cout << "Minimum distances from vertex: " << s << std::endl;
    for (int i = 0; i < V; i++) {
        std::cout << "Vertex: " << i << "\tDistance: " << distances[i] << std::endl;
    }
}
int main()
{
    Graph g(9);

    g.addEdge(8, 3, 90);
    g.addEdge(8, 2, 140);
    g.addEdge(8, 1, 190);

    g.addEdge(3, 5, 380);
    g.addEdge(3, 9, 900);
    g.addEdge(2, 3, 43);
    g.addEdge(1, 4, 23);
    g.addEdge(1, 5, 89);
    g.addEdge(2, 5, 100);
    g.addEdge(2, 8, 400);
    g.addEdge(4, 2, 350);
    g.addEdge(4, 6, 100);
    g.addEdge(5, 6, 210);
    g.addEdge(5, 8, 490);
    g.addEdge(6, 7, 345);
    g.addEdge(6, 4, 210);
    g.addEdge(7, 1, 910);
    g.addEdge(7, 2, 610);

    g.shortestPath(6);
    return 0;
}
