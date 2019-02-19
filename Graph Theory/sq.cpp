#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <malloc.h>
using namespace std;

typedef struct Node
{
	string Name;
	vector<Node* > Next;
}Node;
int BreathFirstSearch(vector<Node* > Stations,Node* root,Node* target)
{
	//最短経路の距離
	int count = 0;
	queue<Node* > q;

	//木の根を指定
	q.push(root);

	while(true)
	{
		cout<<count<<endl;
		int queuesize = q.size();
		for(int i=0; i<queuesize; i++)
		{
			Node* parent = q.front();
			cout<<"Parent:"<<parent->Name<<endl;
			if(parent==target)
			{
				return count;
			}
			q.pop();
			for(int j=0; j<parent->Next.size(); j++)
			{
				cout<<"Child:"<<parent->Next[j]->Name<<endl;
				q.push(parent->Next[j]);
			}
		}
		count++;
	}
	
	return -1;
}
int main()
{
	vector<Node*> Stations;

	Node* Honcho = (Node*)malloc(sizeof(Node));
	Node* Shinsaibashi = (Node*)malloc(sizeof(Node));
	Node* SakaisujiHoncho = (Node*)malloc(sizeof(Node));
	Node* Awaza = (Node*)malloc(sizeof(Node));
	Node* Namba = (Node*)malloc(sizeof(Node));
	Node* Yodoyabashi = (Node*)malloc(sizeof(Node));
	Node* Kitahama = (Node*)malloc(sizeof(Node));
	
	Stations.push_back(Honcho);
	Stations.push_back(Shinsaibashi);
	Stations.push_back(SakaisujiHoncho);
	Stations.push_back(Awaza);
	Stations.push_back(Namba);
	Stations.push_back(Yodoyabashi);
	Stations.push_back(Kitahama);

	Honcho->Name = "本町";
	Shinsaibashi->Name = "心斎橋";
	SakaisujiHoncho->Name = "堺筋本町";
	Awaza->Name = "阿波座";
	Namba->Name = "難波";
	Yodoyabashi->Name = "淀屋橋";
	Kitahama->Name = "北浜";


	
	Honcho->Next.push_back(Shinsaibashi);
	Honcho->Next.push_back(SakaisujiHoncho);
	Honcho->Next.push_back(Awaza);
	Honcho->Next.push_back(Yodoyabashi);
	
	Shinsaibashi->Next.push_back(Honcho);
	Shinsaibashi->Next.push_back(Namba);

	SakaisujiHoncho->Next.push_back(Honcho);
	SakaisujiHoncho->Next.push_back(Kitahama);

	Awaza->Next.push_back(Honcho);

	Namba->Next.push_back(Shinsaibashi);

	Yodoyabashi->Next.push_back(Honcho);
	Yodoyabashi->Next.push_back(Kitahama);

	Kitahama->Next.push_back(SakaisujiHoncho);
	Kitahama->Next.push_back(Yodoyabashi);
	
	cout<<BreathFirstSearch(Stations,Honcho,Namba)<<endl;

	for(int i=0; i<Stations.size(); i++)
	{
		delete(Stations[i]);
	}
	
	return 0;
}