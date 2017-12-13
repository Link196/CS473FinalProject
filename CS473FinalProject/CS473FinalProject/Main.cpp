///////////////////////////////////////////////////////////////////////
// Group Members: Andrew Hutson, McKenna Galle, Vina Le
// Assignment and Course: CS 473 Final Project
///////////////////////////////////////////////////////////////////////

// Graph adapted from https://quickgrid.wordpress.com/2015/05/30/inputting-directed-undirected-weighted-and-unweighted-graph-in-c-c-adjacency-matrix/
// Travelling Salesman Algorithm adapted from https://www.thecrazyprogrammer.com/2017/05/travelling-salesman-problem.html

#include <iostream>
#include "Building.h"

using std::cin;
using std::cout;
using std::endl;
using namespace std;

double cost = 0;

int least(int start, bool visit[15], double Graph[14][14]) {
	int	num = 50;
	int min = 50;
	double costmin = 0;

	for (int i = 0; i < 14; i++) {
		if ((Graph[start][i] != 0) && (visit[i] == 0))
			if (Graph[start][i] + Graph[i][start] < min)
			{
				min = Graph[i][0] + Graph[start][i];
				costmin = Graph[start][i];
				num = i;
			}
	}
	if (min != 50)
		cost += costmin;
	return num;
}
int mincost(int start, bool visit[15], double Graph[14][14]) {
	int i;
	int num = 0;
	visit[start] = 1;
	num += least(start, visit, Graph);
	if (num == 50)
	{
		num = 0;
		cost += Graph[start][num];
		return 0;
	}
	mincost(num, visit, Graph);

}

int main()
{
	// Building object creation
	Building Facilities(0, "Facilities", 13);
	Building Johnston(1, "Johnston", 13);
	Building Robinson(2, "Robinson", 13);
	Building Library(3, "Library", 13);
	Building Hendricks(4, "Hendricks", 13);
	Building HUB(5, "The HUB", 13);
	Building Lindaman(6, "Lindaman", 13);
	Building Weyerhaeuser(7, "Weyerhaeuser", 13);
	Building Dixon(8, "Dixon", 13);
	Building Cowles(9, "Cowles Auditorium", 13);
	Building Music(10, "Music Building", 13);
	Building Westminster(11, "Westminster", 13);
	Building Art(12, "Art Building", 13);
	Building Hawthorne(13, "Hawthorne", 13);

	Building Buildings[14]; // array to store buildings

	Buildings[0] = Facilities;
	Buildings[1] = Johnston;
	Buildings[2] = Robinson;
	Buildings[3] = Library;
	Buildings[4] = Hendricks;
	Buildings[5] = HUB;
	Buildings[6] = Lindaman;
	Buildings[7] = Weyerhaeuser;
	Buildings[8] = Dixon;
	Buildings[9] = Cowles;
	Buildings[10] = Music;
	Buildings[11] = Westminster;
	Buildings[12] = Art;
	Buildings[13] = Hawthorne;

	double Graph[14][14]; // two-dimensional array to store the graph
	bool visited[15]; // array to check whether a building has been visited

					  // add edges to the graph...manually
					  // To/From Johnston
	Graph[1][2] = 0.621; // Johnston to Robinson
	Graph[2][1] = 0.621; // Robinson to Johnston
	Graph[1][3] = 1.088; // Johnston to the Library
	Graph[3][1] = 1.088; // Library to Johnston
	Graph[1][4] = 0.709; // Johnston to Hendricks
	Graph[4][1] = 0.709; // Hendricks to Johnston
	Graph[1][5] = 1.052; // Johnston to the HUB
	Graph[5][1] = 1.052; // The HUB to Johnston
	Graph[1][6] = 1.992; // Johnston to Lindaman
	Graph[6][1] = 1.992; // Lindaman to Johnston
	Graph[1][7] = 1.818; // Johnston to Weyerhaeuser
	Graph[7][1] = 1.818; // Weyerhaeuser to Johnston
	Graph[1][8] = 2.657; // Johnston to Dixon
	Graph[8][1] = 2.657; // Dixon to Johnston
	Graph[1][9] = 2.374; // Johnston to Cowles Auditorium
	Graph[9][1] = 2.374; // Cowles Auditorium to Johnston
	Graph[1][10] = 2.862; // Johnston to the Music Building
	Graph[10][1] = 2.862; // The Music Building to Johnston
	Graph[1][11] = 2.538; // Johnston to Westminster
	Graph[11][1] = 2.538; // Westminster to Johnston
	Graph[1][12] = 1.964; // Johnston to the Art Building
	Graph[12][1] = 1.964; // The Art Building to Johnston
	Graph[1][13] = 3.735; // Johnston to Hawthorne
	Graph[13][1] = 3.735; // Hawthorne to Johnston

						  // To/From Robinson

	Graph[2][3] = 1.216; // Robinson to the Library
	Graph[3][2] = 1.216; // The Library to Robinson
	Graph[2][4] = 1.226; // Robinson to Hendricks
	Graph[4][2] = 1.226; // Hendricks to Robinson
	Graph[2][5] = 1.223; // Robinson to the HUB
	Graph[5][2] = 1.223; // The HUB to Robinson
	Graph[2][6] = 1.218; // Robinson to Lindaman
	Graph[6][2] = 1.218; // Lindaman to Robinson
	Graph[2][7] = 1.021; // Robinson to Weyerhaeuser
	Graph[7][2] = 1.021; // Weyerhaeuser to Robinson
	Graph[2][8] = 1.777; // Robinson to Dixon
	Graph[8][2] = 1.777; // Dixon to Robinson
	Graph[2][9] = 2.184; // Robinson to Cowles Auditorium
	Graph[9][2] = 2.184; // Cowles Auditorium to Robinson
	Graph[2][10] = 2.621; // Robinson to the Music Building
	Graph[10][2] = 2.621; // The Music Building to Robinson
	Graph[2][11] = 1.831; // Robinson to Westminster
	Graph[11][2] = 1.831; // Westminster to Robinson
	Graph[2][12] = 1.281; // Robinson to the Art Building
	Graph[12][2] = 1.281; // The Art Building to Robinson
	Graph[2][13] = 4.200; // Robinson to Hawthorne
	Graph[13][2] = 4.200; // Hawthorne to Robinson

						  // To/From the Library
	Graph[3][4] = 1.644; // The Library to Hendricks
	Graph[4][3] = 1.644; // Hendricks to the Library
	Graph[3][5] = 1.052; // The Library to the HUB
	Graph[5][3] = 1.052; // The HUB to the Library
	Graph[3][6] = 1.192; // The Library to Lindaman
	Graph[6][3] = 1.192; // Lindaman to the Library
	Graph[3][7] = 1.512; // The Library to Weyerhaeuser
	Graph[7][3] = 1.512; // Weyerhaeuser to the Library
	Graph[3][8] = 1.286; // The Library to Dixon
	Graph[8][3] = 1.286; // Dixon to the Library
	Graph[3][9] = 1.566; // The Library to Cowles Auditorium
	Graph[9][3] = 1.566; // Cowles Auditorium to the Library
	Graph[3][10] = 2.031; // The Library to the Music Building
	Graph[10][3] = 2.031; // The Music Building to the Library
	Graph[3][11] = 2.764; // The Library to Westminster
	Graph[11][3] = 2.764; // Westminster to the Library
	Graph[3][12] = 2.255; // The Library to the Art Building
	Graph[12][3] = 2.255; // The Art Building to the Library
	Graph[3][13] = 3.683; // The Library to Hawthorne
	Graph[13][3] = 3.683; // Hawthorne to the Library

						  // To/From Hendricks
	Graph[4][5] = 1.130; // Hendricks to the HUB
	Graph[5][4] = 1.130; // The HUB to Hendricks
	Graph[4][6] = 1.748; // Hendricks to Lindaman
	Graph[6][4] = 1.748; // Lindaman to Hendricks
	Graph[4][7] = 1.766; // Hendricks to Weyerhaeuser
	Graph[7][4] = 1.766; // Weyerhaeuser to Hendricks
	Graph[4][8] = 2.652; // Hendricks to Dixon
	Graph[8][4] = 2.652; // Dixon to Hendricks
	Graph[4][9] = 2.647; // Hendricks to Cowles Auditorium
	Graph[9][4] = 2.647; // Cowles Auditorium to Hendricks
	Graph[4][10] = 3.262; // Hendricks to the Music Building
	Graph[10][4] = 3.262; // The Music Building to Hendricks
	Graph[4][11] = 3.234; // Hendricks to Westminster
	Graph[11][4] = 3.234; // Westminster to Hendricks
	Graph[4][12] = 2.704; // Hendricks to the Art Building
	Graph[12][4] = 2.704; // The Art Building to Hendricks
	Graph[4][13] = 2.943; // Hendricks to Hawthorne
	Graph[13][4] = 2.943; // Hawthorne to Hendricks

						  // To/From the HUB
	Graph[5][6] = 1.953; // The HUB to Lindaman
	Graph[6][5] = 1.953; // Lindaman to the HUB
	Graph[5][7] = 2.481; // The HUB to Weyerhaeuser
	Graph[7][5] = 2.481; // Weyerhaeuser to the HUB
	Graph[5][8] = 1.855; // The HUB to Dixon
	Graph[8][5] = 1.855; // Dixon to the HUB
	Graph[5][9] = 1.426; // The HUB to Cowles Auditorium
	Graph[9][5] = 1.426; // Cowles Auditorium to the HUB
	Graph[5][10] = 2.260; // The HUB to the Music Building
	Graph[10][5] = 2.260; // The Music Building to the HUB
	Graph[5][11] = 3.390; // The HUB to Westminster
	Graph[11][5] = 3.390; // Westminster to the HUB
	Graph[5][12] = 2.927; // The HUB to the Art Building
	Graph[12][5] = 2.927; // The Art Building to the HUB
	Graph[5][13] = 2.597; // The HUB to Hawthorne
	Graph[13][5] = 2.597; // Hawthorne to the HUB

						  // To/From Lindaman
	Graph[6][7] = 0.553; // Lindaman to Weyerhaeuser
	Graph[7][6] = 0.553; // Weyerhaeuser to Lindaman
	Graph[5][8] = 1.548; // Lindaman to Dixon
	Graph[8][6] = 1.548; // Dixon to Lindaman
	Graph[6][9] = 1.847; // Lindaman to Cowles Auditorium
	Graph[9][6] = 1.847; // Cowles Auditorium to Lindaman
	Graph[6][10] = 2.371; // Lindaman to the Music Building
	Graph[10][6] = 2.371; // The Music Building to Lindaman
	Graph[6][11] = 2.319; // Lindaman to Westminster
	Graph[11][6] = 2.319; // Westminster to Lindaman
	Graph[6][12] = 1.919; // Lindaman to the Art Building
	Graph[12][6] = 1.919; // The Art Building to Lindaman
	Graph[6][13] = 4.657; // Lindaman to Hawthorne
	Graph[13][6] = 4.657; // Hawthorne to Lindaman

						  // To/From Weyerhaeuser
	Graph[7][8] = 1.714; // Weyerhaeuser to Dixon
	Graph[8][7] = 1.714; // Dixon to Weyerhaeuser
	Graph[7][9] = 2.408; // Weyerhaeuser to Cowles Auditorium
	Graph[9][7] = 2.408; // Cowles Auditorium to Weyerhaeuser
	Graph[7][10] = 2.649; // Weyerhaeuser to the Music Building
	Graph[10][7] = 2.649; // The Music Building to Weyerhaeuser
	Graph[7][11] = 0.787; // Weyerhaeuser to Westminster
	Graph[11][7] = 0.787; // Westminster to Weyerhaeuser
	Graph[7][12] = 0.844; // Weyerhaeuser to the Art Building
	Graph[12][7] = 0.844; // The Art Building to Weyerhaeuser
	Graph[7][13] = 4.935; // Weyerhaeuser to Hawthorne
	Graph[13][7] = 4.935; // Hawthorne to Weyerhaeuser

						  // To/From Dixon
	Graph[8][9] = 0.709; // Dixon to Cowles Auditorium
	Graph[9][8] = 0.709; // Cowles Auditorium to Dixon
	Graph[8][10] = 0.984; // Dixon to the Music Building
	Graph[10][8] = 0.984; // The Music Building to Dixon
	Graph[8][11] = 2.706; // Dixon to Westminster
	Graph[11][8] = 2.706; // Westminster to Dixon
	Graph[8][12] = 2.799; // Dixon to the Art Building
	Graph[12][8] = 2.799; // The Art Building to Dixon
	Graph[8][13] = 4.127; // Dixon to Hawthorne
	Graph[13][8] = 4.127; // Hawthorne to Dixon

						  // To/From Cowles Auditorium
	Graph[9][10] = 0.701; // Cowles Auditorium to the Music Building
	Graph[10][9] = 0.701; // The Music Building to Cowles Auditorium
	Graph[9][11] = 3.455; // Cowles Auditorium to Westminster
	Graph[11][9] = 3.455; // Westminster to Cowles Auditorium
	Graph[9][12] = 3.062; // Cowles Auditorium to the Art Building
	Graph[12][9] = 3.062; // The Art Building to Cowles Auditorium
	Graph[9][13] = 3.831; // Cowles Auditorium to Hawthorne
	Graph[13][9] = 3.831; // Hawthorne to Cowles Auditorium

						  // To/From the Music Building
	Graph[10][11] = 4.296; // The Music Building to Westminster
	Graph[11][10] = 4.296; // Westminster to the Music Building
	Graph[10][12] = 3.712; // The Music Building to the Art Building
	Graph[12][10] = 3.712; // The Art Building to the Music Building
	Graph[10][13] = 4.462; // The Music Building to Hawthorne
	Graph[13][10] = 4.462; // Hawthorne to the Music Building

						   // To/From Westminster
	Graph[11][12] = 0.771; // Westminster to the Art Building
	Graph[12][11] = 0.771; // The Art Building to Westminster
	Graph[11][13] = 5.745; // Westminster to Hawthorne
	Graph[13][11] = 5.745; // Hawthorne to Westminster

						   // To/From the Art Building
	Graph[12][13] = 5.351; // The Art Building to Hawthorne
	Graph[13][12] = 5.351; // Hawthorne to the Art Building

						   // To/From Facilities
	Graph[0][1] = 1.496; // Facilities to Johnston
	Graph[1][0] = 1.496; // Johnston to Facilities
	Graph[0][2] = 1.200; // Facilities to Robinson
	Graph[2][0] = 1.200; // Robinson to Facilities
	Graph[0][3] = 2.174; // Facilities to the Library
	Graph[3][0] = 2.174; // The Library to Facilities
	Graph[0][4] = 2.018; // Facilities to Hendricks
	Graph[4][0] = 2.018; // Hendricks to Facilities
	Graph[0][5] = 3.003; // Facilities to the HUB
	Graph[5][0] = 3.003; // The HUB to Facilities
	Graph[0][6] = 2.153; // Facilities to Lindaman
	Graph[6][0] = 2.153; // Lindaman to Facilities
	Graph[0][7] = 1.948; // Facilities to Weyerhaeuser
	Graph[7][0] = 1.948; // Weyerhaeuser to Facilities
	Graph[0][8] = 2.696; // Facilities to Dixon
	Graph[8][0] = 2.696; // Dixon to Facilities
	Graph[0][9] = 3.005; // Facilities to Cowles Auditorium
	Graph[9][0] = 3.005; // Cowles Auditorium to Facilities
	Graph[0][10] = 3.660; // Facilities to the Music Building
	Graph[10][0] = 3.660; // The Music Building to Facilities
	Graph[0][11] = 1.540; // Facilities to Westminster
	Graph[11][0] = 1.540; // Westminster to Facilities
	Graph[0][12] = 0.901; // Facilities to the Art Building
	Graph[12][0] = 0.901; // The Art Building to Facilities
	Graph[0][13] = 4.634; // Facilities to Hawthorne
	Graph[13][0] = 4.634; // Hawthorne to Facilities
						  // One of the billion attempts
						  //double  dp[15][15];
						  //double  ans;
						  //int i, j, p, k;
						  //int n = 13;

						  //	memset(dp, -1, sizeof(dp));
						  //	// TSP solution here,bitmask and DP
						  //	for (i = 1; i<(1 << n); i++) {// the current state
						  //		for (j = 0; j<n; j++) {// during the current state,the last station is j
						  //			
						  //			for (k = 1; k<n; k++) {//the next state is k
						  //				if ((i & (1 << k)) != 0) 
						  //					continue;
						  //				p = (i | (1 << k));// the new state(join k)
						  //				if (dp[p][k] == -1) 
						  //					dp[p][k] = dp[i][j] + Graph[j][k];
						  //				dp[p][k] = min(dp[p][k], dp[i][j] + Graph[j][k]);
						  //			}
						  //		}
						  //	}
						  //	// get answer
						  //	for (i = 1; i<n; i++) {
						  //		if (dp[(1 << n) - 1][i]>0) ans = min(ans, dp[(1 << n) - 1][i] + Graph[i][0]);
						  //	}
						  //	printf("%d\n", ans);
						  //}
	mincost(0, visited, Graph);
	cout << cost;
	system("PAUSE");
}
