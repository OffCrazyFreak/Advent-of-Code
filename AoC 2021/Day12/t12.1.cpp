#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct vertex {
    // string pointName;
    vector<string> connections;
};

void recursiveSearchAll(int *paths){

    /* if you arrive at a vertex where the only other vertex is small cave where you came from, it's a dead end
    // two big caves are NEVER going to be connected (infinite loop)
    // if i model each vertex as a vector that containes all of their connections
        start
        /   \
    c--A-----b--d
        \   /
         end
    vertex<string> start = {A, b}
    vertex<string> A = {c, b, end}
    vertex<string> c = {A}
    vertex<string> b = {A, d, end}
    vertex<string> d = {b} // invalid
    // no vertex can contain start
    // end does not need to be modeled as you cannot go to another vertex when end is reached

    */
    return;
}

int main(void){
    /*
    vector<string> start = {"A", "b"};
    vertices.push_back(start);
    vector<string> A = {"c", "d", "end"};
    vertices.push_back(A);

    for(vector<string> vertex : vertices)
        for(string connection : vertex)
            if(vertex == start)
                cout << "start->" << connection << endl;
            else if (vertex == A)
                cout << "A->" << connection << endl;
            // etc
    */

    int inputs = 2; // 23
    vector<string> vertices; // will be calculated on input
    vector<vertex> graph; // vertices
    bool hasVertex;
    string str;

    for (int i = 0; i < inputs; i++){
        cin >> str;

        vertices.push_back(str.substr(0, str.find("-")));
        vertices.push_back(str.substr(str.find("-") + 1, string::npos));


        vertex ver = vertices[i];
        ver.connections.push_back(vertices[i+1])
        if(find(graph.begin(), graph.end(), ver) == graph.end())
            graph.push_back(ver);


        if(find(graph.begin(), graph.end(), vertices[i+1]) == graph.end())
            graph.push_back(vertices[i+1]);
    }








    return 0;
}