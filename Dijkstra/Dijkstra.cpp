// Dijkstra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 0x3fffffff
void addEdge(vector < vector<pair<int, int>>> &adjList, int source, int end, int weight) {
    
    adjList[source].push_back(make_pair(end, weight));
    adjList[end].push_back(make_pair(source, weight));

}

vector<int> dijkstra(vector < vector<pair<int, int>>> adjList, int source) {
    vector<int> distances(adjList.size(), INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push(make_pair(0, source));
    //distances[source] = 0;

    while (!pq.empty()) {
        auto shortest = pq.top();
        int distance = shortest.first;
        int vertex = shortest.second;
        pq.pop();

        if (distance < distances[vertex]) {
            distances[vertex] = distance;
            for (auto edge : adjList[vertex]) {
                pq.push(make_pair(distance + edge.second, edge.first));
            }
        }
    }

    return distances;
}

int main()
{
    int V = 6;
    vector < vector<pair<int, int>>> adjList(V);
    addEdge(adjList, 0, 1, 10);
    addEdge(adjList, 0, 2, 5);
    addEdge(adjList, 1, 3, 7);
    addEdge(adjList, 1, 4, 8);
    addEdge(adjList, 2, 4, 6);
    addEdge(adjList, 4, 5, 5);

    vector<int> shortestPaths = dijkstra(adjList, 3);





}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
