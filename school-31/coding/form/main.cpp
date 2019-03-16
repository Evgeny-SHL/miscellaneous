// L3FmiwqGvaBYCzD6
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cassert>

class DiodesSolver {

public:

	typedef struct tagResistor {
		int Node1;
		int Node2;
		double Resistance;
	} Resistor;

	typedef struct tagDiode {
		int NodeA;
		int NodeC;
		double ResDir;
		double ResRev;
	} Diode;

	struct CEdge {
		int To;
		double Capacity;
		int Index;
		double Flow;

		CEdge( int to, double capacity, int index, double flow = 0.0 ) :
			To( to ), Capacity( capacity ), Index( index ), Flow( flow )
		{
		}
	};

	struct Preqec {
		int From;
		int Edge;
		int Index;

		Preqec( int from = -1, int edge = -1, int index = -1 ) :
			From( from ), Edge( edge ), Index( index )
		{
		}
	};

	static double Solve( std::vector <Diode> diodes, std::vector <Resistor> resistors, int source, int drain )
	{

		std::vector < std::vector < CEdge» edges( 100 );
		for( int i = 0; i < static_cast<int>( resistors.size() ); ++i ) {
			edges[resistors[i].Node1].push_back(
				CEdge( resistors[i].Node2, 1.0 / resistors[i].Resistance, edges.size() ) );
			edges[resistors[i].Node2].push_back( CEdge( resistors[i].Node1, 0.0, edges.size() ) );
			edges[resistors[i].Node2].push_back(
				CEdge( resistors[i].Node1, 1.0 / resistors[i].Resistance, edges.size() ) );
			edges[resistors[i].Node1].push_back( CEdge( resistors[i].Node2, 0.0, edges.size() ) );
		}
		for( int i = 0; i < static_cast<int>( diodes.size() ); ++i ) {
			edges[diodes[i].NodeA].push_back( CEdge( diodes[i].NodeC, 1.0 / diodes[i].ResDir, edges.size() ) );
			edges[diodes[i].NodeC].push_back( CEdge( diodes[i].NodeA, 0.0, edges.size() ) );
			edges[diodes[i].NodeC].push_back( CEdge( diodes[i].NodeA, 1.0 / diodes[i].ResRev, edges.size() ) );
			edges[diodes[i].NodeA].push_back( CEdge( diodes[i].NodeC, 0.0, edges.size() ) );
		}

		double max = 0.0;

		for( int k = 0; k < 2; ++k ) {

			std::deque<int> queue;
			std::vector<bool> visited( 1001, false );
			std::vector <Preqec> pred( 1001 );
			queue.push_back( source );
			visited[source] = true;
			while( !queue.empty() ) {
				int from = queue.front();
				queue.pop_front();
				for( int i = 0; i < static_cast<int>( edges[from].size() ); ++i ) {
					int to = edges[from][i].To;
					if( !visited[to] && ( edges[from][i].Capacity > edges[from][i].Flow ) ) {
						pred[to] = Preqec( from, i, edges[from][i].Index );
						queue.push_back( to );
						visited[to] = true;
					}
				}
			}

			//assert(visited[drain] == true);

			if( pred[drain].From == -1 ) {
				break;
			}

			int cur = drain;
			double min = 1000.0;
			while( cur != source && cur != -1 ) {
				CEdge edge = edges[pred[cur].From][pred[cur].Edge];
				min = std::min( min, edge.Capacity - edge.Flow );
				cur = pred[cur].From;
			}

			cur = drain;
			while( cur != source && cur != -1 ) {
				int from = pred[cur].From;
				int index = pred[cur].Index ^1;
				edges[from][pred[cur].Edge].Flow += min;
				for( int i = 0; i < static_cast<int>( edges[cur].size() ); ++i ) {
					if( edges[cur][i].Index == index ) {
						edges[cur][i].Flow -= min;
					}
				}
				cur = pred[cur].From;
			}

			max += min;
		}

		if( max == 0.0 ) {
			max = 1.0;
		}

		return 1.0 / max;
	}
};