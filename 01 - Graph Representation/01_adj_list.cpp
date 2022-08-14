#include<iostream>
#include<list>
using namespace std;

class Graph{
	int V;
	list<int> *l; // making a ptr for dyammic memory Allocation.
	
public:
	// simple constructor.
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}
	
	void addEdge(int i,int j,bool undir=true){
		l[i].push_back(j);
		if(undir)
			l[j].push_back(i);
	}
	// printing the Adjacency List
	void printAdjList(){
		for(int i=0 ; i<V ; ++i){
			cout << i << " --> ";
			for(int child : l[i]){
				cout << child << ",";
			}
			cout << endl;
		}
	}
	
};

int main()
{
	Graph g(7);
	// Example Graph
	g.addEdge(1,2);
	g.addEdge(1,0);
	g.addEdge(2,3);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(5,6);
	// printing the Graph
	g.printAdjList();
	return 0;
}
