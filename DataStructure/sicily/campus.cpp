// Problem#: 19171
// Submission#: 4939579
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std ;

int adjacency[305][305] , distancee[305] ;
bool found[305] ;

void digastra(int start, int end , int count)
{
    int v , w ;
    for( v = 0 ; v < count ; v ++)
    {
        found[v] = false ;
        distancee[v] = adjacency[start][v] ;
    }
    found[start] = true ;
    distancee[start] = 0 ;
    for(int i = 0; i < count ; i ++)
    {
        int min =  999999999;
        for( w = 0 ; w < count ; w ++)
            if( !found[w] )
                if( distancee[w] < min )
                {
                    v = w ;
                    min = distancee[w] ;
                }

        if(v == end) break ;
        found[v] = true ;
        for( w = 0 ; w < count ; w ++)
            if( !found[w] )
                if( min + adjacency[v][w] < distancee[w] )
                    distancee[w] = min + adjacency[v][w] ;
    
    }
}

 

   

int main()
{
    int c ;
    cin >> c ;
    while(c--)
    {
        for(int i = 0 ; i< 305 ; i ++)
        {
            distancee[i] = 999999999 ;
            for(int j = 0 ; j < 305 ; j ++)
            {
                adjacency[i][j] = 999999999;
            }
        }

        int n ,dis ;
        cin >> n ;
        string place1 , place2 ;
        map<string,int> m ;
        int num = 0 ;
        for(int i = 0 ; i< n ; i ++)
        {
            cin >> place1 >> place2 >> dis ;
            if(m.find (place1) == m.end ())
            {
                m[place1] = num ++ ;
            }
            if(m.find(place2) == m.end() )
            {
                m[place2] = num ++ ;
            }
            adjacency[ m[place1] ][ m[place2] ] = dis ;
            adjacency[ m[place2] ][ m[place1] ] = dis ;
        }
        cin >> place1 >> place2 ;
        if(m.find (place1) == m.end ())
        {
            m[place1] = num ++ ;
        }
        if(m.find(place2) == m.end() )
        {
            m[place2] = num ++ ;
        }
        int start = m[place1] ;
        int end = m[place2] ;
        int count = m.size () ;

        digastra(start, end , count) ;
        if(distancee[end] < 999999999 )
            cout << distancee[end] << endl;
        else cout << -1 << endl;
    }
}                                 