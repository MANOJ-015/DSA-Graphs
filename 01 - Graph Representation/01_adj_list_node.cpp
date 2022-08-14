#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

class Node{
public:
	string name;
	list<string> nbrs;
	
	Node(string &name){
		this->name = name;
	}	
};

class Graph{
	unordered_map<string,Node*> m;

public:
	
	Graph(vector<string> &cities){
		for(string city : cities){
			m[city] = new Node(city);
		}
	}	
	
	void addEdge(string city1,string city2,bool undir=false){
		m[city1]->nbrs.push_back(city2);
		if(undir)
			m[city2]->nbrs.push_back(city1);
	}
	
	void printAdjList(){
		for(auto cityPair : m){
			string city = cityPair.first;
			Node *node = cityPair.second;
			
			cout << city << " --> ";
			for(auto nbrs : node->nbrs){
				cout << nbrs << ",";
			}
			cout << endl;
		}
	}
};

int main()
{
	vector<string> cities = {"London","Delhi","Paris","newYork"};
	Graph g(cities);
	
	g.addEdge("newYork","London");
	g.addEdge("Delhi","London");
	g.addEdge("Paris","newYork");
	g.addEdge("Delhi","Paris");
	
	g.printAdjList();
	
	return 0;
}
