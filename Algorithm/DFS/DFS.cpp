#include <iostream>
#include <list>
using namespace std;

class Graph
{
	int Vnum;
	list<int> *adj;
	void DFSUtil(int v,bool visited[]);
public:
	Graph(int Vnum);
	void addEdge(int v,int w);
	void DFS(int v);
};

Graph::Graph(int Vnum)
{
	this->Vnum=Vnum;
	adj=new list<int>[Vnum];
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v,bool visited[])
{
	visited[v]=true;
	cout<<v<<" ";

	list<int>::iterator i;

	for(i=adj[v].begin();i!=adj[v].end();++i)
		if(!visited[*i])
			DFSUtil(*i,visited);
}

void Graph::DFS(int v)
{
	bool *visited=new bool[Vnum];
	for(int i=0;i<Vnum;++i)
		visited[i]=false;

	DFSUtil(v,visited);

	// for(int i=0;i<Vnum;i++)
	// 	if(!visited[i])
	// 		DFSUtil(i,visited);

}

int main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);

	cout<<"Depth First Traversal (starting from vertex 2) \n";
	g.DFS(2);
	cout<<endl;

	return 0;
}