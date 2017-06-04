#include <iostream>
#include <string>
using namespace std;

#define INF 99999
class WDigraph
{
public:
	WDigraph( int size, int x );
	~WDigraph();
	bool exist( int i, int j ) const;
	int getEdge() const;
	int getVertex() const;
	bool add( int i, int j, const int weight );//���·��
	bool erase( int i, int j, int &get );//ɾ��·��
	int inDegree( int i ) const;
	int outDegree( int i ) const;

	void pinrtG() const;

	void prim( WDigraph &tree, int s );
private:
	int maxSize;			//��ǰ������������
	int a[100][100];		//����Ȩֵ��������unsigned int����������Ѹ�����ֵ������ʱ��������Ը���ȡ2^8��ģ�����縳ֵ-1������ֵ������255
	int n;					//������
	int e;					//����
	int no;					//���ֵ���ж��Ƿ��б�
};

WDigraph::WDigraph( int size, int x )
{
	no = x;
	n = 0;
	e = 0;
	maxSize = size;
	for( int i = 0; i < size; i++ )
		for( int j = 0; j < size; j++ )
			a[i][j] = x;
}

WDigraph::~WDigraph()
{
	for( int i = 0; i < 100; i++ )
		for( int j = 0; j < 100; j++ )
			a[i][j] = 0;
	n = 0;
	e = 0;
	no = 0;
	maxSize = 0;
}

bool WDigraph::exist( int i, int j ) const
{
	if( i < maxSize && j < maxSize && i >=0 && j >= 0 )
		return a[i][j] == no;
	return false;
}

int WDigraph::getEdge() const
{
	return e;
}

int WDigraph::getVertex() const
{
	return n;
}

bool WDigraph::add( int i, int j, const int weight )
{
	if( i < maxSize && j < maxSize && i >=0 && j >= 0 )
	{
		a[i][j] = weight;
		return true;
	}
	return false;
}

bool WDigraph::erase( int i, int j, int &get )
{
	if( i < maxSize && j < maxSize && i >=0 && j >= 0 )
	{
		get = a[i][j];
		a[i][j] = no;
		return true;
	}
	return false;
}

int WDigraph::inDegree( int i ) const
{
	int count = 0;
	if( i >= maxSize || i < 0 )
		return -1;
	for( int k = 0; k < maxSize; k++ )
	{
		if( a[i][k] != no )
			count++;
	}
	return count;
}



void WDigraph::prim(WDigraph &tree, int s)
{
	bool visited[tree.maxSize];
	int distance[tree.maxSize];
	int neightbour[tree.maxSize];
	int vtex;
	for( vtex = 0; vtex < tree.maxSize; vtex++ )
	{
		visited[vtex] = false;
		distance[vtex] = a[s][vtex];
		neightbour[vtex] = s;
	}
	visited[s] = true;
	for( int i = 1; i < tree.maxSize; i++ )
	{
		int min = INF;
		int to_insert;
		for( vtex = 0; vtex < tree.maxSize; vtex++ )
			if( distance[vtex] < min )
			{
				min = distance[vtex];
				to_insert = vtex;
			}
		if( min < INF )
		{
			visited[to_insert] = true;
			tree.add( )
		}
	}
}

int main()
{
	WDigraph graph( 6, 0 );
	graph.add( 0, 1, 6 );
	graph.add( 0, 2, 1 );
	graph.add( 0, 3, 5 );
	graph.add( 1, 2, 5 );
	graph.add( 1, 4, 5 );
	graph.add( 2, 3, 5 );
	graph.add( 2, 4, 6 );
	graph.add( 2, 5, 4 );
	graph.add( 3, 5, 2 );
	graph.add( 4, 5, 6 );
	graph.pinrtG();
	system("pause");
	return 0;
}