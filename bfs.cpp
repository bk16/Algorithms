#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;

struct node
{
	int value;
	struct node * next;
};

struct vertex
{
	int value;
	bool visited;
	struct node * head;
};

void addEdge(int u,int v,struct vertex ** graph)
{
	if( graph[u]->head == NULL )
	{
		graph[u]->head = (struct node *)malloc(sizeof(struct node ));
		graph[u]->head->next = NULL;
		graph[u]->head->value = v;
	}
	else
	{
		struct node * temp = graph[u]->head;
		while( temp->next != NULL )
			temp = temp->next;

		struct node * newn = (struct node *)malloc(sizeof(struct node ));
		newn->value = v;
		newn->next = NULL;
		temp->next = newn;
	}

	if( graph[v]->head == NULL )
	{
		graph[v]->head = (struct node *)malloc(sizeof(struct node ));
		graph[v]->head->next = NULL;
		graph[v]->head->value = u;
	}
	else
	{
		struct node * temp = graph[v]->head;
		while( temp->next != NULL )
			temp = temp->next;

		struct node * newn = (struct node *)malloc(sizeof(struct node ));
		newn->value = u;
		newn->next = NULL;
		temp->next = newn;
	}
}

void bfs(struct vertex ** graph ,int v)
{
	queue<int> q;
	q.push(v);
	graph[v]->visited = true;

	cout << "visited : " << v << endl;
	while( !q.empty() )
	{
		int u = q.front();
		q.pop();

		struct node * head = graph[u]->head;
	
		while( head )
		{
			if( !graph[head->value]->visited )
			{
				q.push(head->value);
				graph[head->value]->visited = true;
				cout << "visited : " << head->value << endl;
			}
			head = head->next;
		}
	}
}
int main()
{

	struct vertex ** graph;

	int v = 10;

	graph = (struct vertex **)malloc(v*sizeof(struct vertex *));

	for( int i=0; i<v ;i++)
	{
		graph[i] = (struct vertex *)malloc(sizeof(struct vertex));
		graph[i]->value = i+1;
		graph[i]->head = NULL;
		graph[i]->visited = false;
	}

	addEdge(1,2,graph);
	addEdge(1,3,graph);
	addEdge(3,4,graph);
	addEdge(4,5,graph);
	addEdge(5,6,graph);
	addEdge(6,7,graph);
	addEdge(8,9,graph);

	for( int i=0; i<v ;i++)
	{
		struct node * head = graph[i]->head;
		cout << i << " : ";
		while( head )
		{		
			cout << head->value << " ";
			head = head->next;
		}
		cout << endl;
		//cout << "graph[i]->value : " << graph[i]->value << endl;
	}

	//dfs(graph,0);
	//dfs(graph,8);
	//dfs(graph,4);
		

	bfs(graph,4);
	
}
