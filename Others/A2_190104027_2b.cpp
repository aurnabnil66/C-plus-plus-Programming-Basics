#include<bits/stdc++.h>

using namespace std;

vector<int>Graph[100];                                                                      // adjacency list
int State[100];
vector<int>Topological_sort;                                                          // topological sorted list


void GraphInput(int node_no,int node_edge)
{
    int n1,n2,value;
    for(int i=0;i<node_edge;i++)
    {
        cin>>n1>>n2;
        Graph[n1].push_back(n2);                                                        // enter the  connection       n1-----> n2 edge achey   1 bar as directed graph
    }
    for(int i=1;i<=node_no;i++)
    {
        printf("%d  --> ",i);
        for(int j=0;j <Graph[i].size();j++)                                          // adjacency list print
        {
            value = Graph[i][j];
            printf(" %d",value);
        }
        printf("\n");
    }
}

void DFS(int source)                                                             // node source hisabe jabe
{
    int next;
    State[source] = 1;                                                               //  visited
    printf("  %d  ",source);
    for(int i=0;i<Graph[source].size();i++)                    // neighbor node
    {
        next = Graph[source][i];                                            // assign every neighbor node to next
        if(State[next]==0)                                                          // now check  previously  visited or not
        {
            DFS(next);                                                                      // recursively call hobe  neighbor node
        }
    }                                                                                             // sobie  visited  and source ar kono unvisited child nai
    Topological_sort.push_back(source);                             // vector a source ta push back korbo
}

int main()
{
    int node,edge;

    printf("Enter The number of Node :\n");
    scanf("%d",&node);

    printf("Enter The number of Edge :\n");
    scanf("%d",&edge);

    printf("Enter the Connection :\n");
    GraphInput(node,edge);


    printf("\n After DFS : ");
    for(int i=1;i<=node;i++)
    {
        if(State[i]==0)                              // if unvisited then dfs wil call
            DFS(i);
    }
      printf("\n Before Topological Sort :");
    for(int i=0;i<Topological_sort.size();i++)
    {
        printf("  %d  ",Topological_sort[i]);
    }

    reverse(Topological_sort.begin(),Topological_sort.end());                                   //  reverse kore thn print  jate   prerequisite  node thik thake
    printf("\n After Topological Sort :");
    for(int i=0;i<Topological_sort.size();i++)
    {
        printf("  %d  ",Topological_sort[i]);
    }
}

