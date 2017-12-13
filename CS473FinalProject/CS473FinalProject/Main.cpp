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

double TravelingJanitor(double Graph[15][15], bool visited[15], int start, int vertices, int edges)
{
	double min = 0;
	visited[start] = true; // set the current building to visited
	double minimum = 1000; // initialize minumum distance variable to 1000
	double total = 0; // initialize variable for total travel time
	int temp1 = 0;
	int temp2 = 0;

	for (int x = start; x < vertices; x++) {
		for (int i = 1; i <= vertices; i++)
		{
			if ((Graph[start][i] != 0) && (visited[i] == false))
				if (Graph[start][i] < minimum)
					minimum = Graph[start][i];
					temp1 = start;
					temp2 = i;
		}
		visited[temp2] = true;
		start =temp2;
		min = min + minimum;
		
	}
	return min;
}

int main()
{
	// Building object creation
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
	Building Facilities(14, "Facilities", 13);

	double Graph[15][15]; // two-dimensional array to store the graph
	bool visited[15]; // array to check whether a building has been visited
	int vertices = 14; // number of buildings
	int edges = 14; // max number of paths per building

	// initialize the graph
	for (int i = 0; i < vertices + 1; i++)
		for (int j = 0; j < edges; j++)
			Graph[i][j] = 0;

	// initialize the visited array to all false
	for (int i = 1; i < vertices + 1; i++)
		visited[i] = false;

	// add edges to the graph...manually
	// To/From Johnston
	Graph[2][3] = 0.621; // Johnston to Robinson
	Graph[3][2] = 0.621; // Robinson to Johnston
	Graph[2][4] = 1.088; // Johnston to the Library
	Graph[4][2] = 1.088; // Library to Johnston
	Graph[2][5] = 0.709; // Johnston to Hendricks
	Graph[5][2] = 0.709; // Hendricks to Johnston
	Graph[2][6] = 1.052; // Johnston to the HUB
	Graph[6][2] = 1.052; // The HUB to Johnston
	Graph[2][7] = 1.992; // Johnston to Lindaman
	Graph[7][2] = 1.992; // Lindaman to Johnston
	Graph[2][8] = 1.818; // Johnston to Weyerhaeuser
	Graph[8][2] = 1.818; // Weyerhaeuser to Johnston
	Graph[2][9] = 2.657; // Johnston to Dixon
	Graph[9][2] = 2.657; // Dixon to Johnston
	Graph[2][10] = 2.374; // Johnston to Cowles Auditorium
	Graph[10][2] = 2.374; // Cowles Auditorium to Johnston
	Graph[2][11] = 2.862; // Johnston to the Music Building
	Graph[11][2] = 2.862; // The Music Building to Johnston
	Graph[2][12] = 2.538; // Johnston to Westminster
	Graph[12][2] = 2.538; // Westminster to Johnston
	Graph[2][13] = 1.964; // Johnston to the Art Building
	Graph[13][2] = 1.964; // The Art Building to Johnston
	Graph[2][14] = 3.735; // Johnston to Hawthorne
	Graph[14][2] = 3.735; // Hawthorne to Johnston

	// To/From Robinson
	
	Graph[3][4] = 1.216; // Robinson to the Library
	Graph[4][3] = 1.216; // The Library to Robinson
	Graph[3][5] = 1.226; // Robinson to Hendricks
	Graph[5][3] = 1.226; // Hendricks to Robinson
	Graph[3][6] = 1.223; // Robinson to the HUB
	Graph[6][3] = 1.223; // The HUB to Robinson
	Graph[3][7] = 1.218; // Robinson to Lindaman
	Graph[7][3] = 1.218; // Lindaman to Robinson
	Graph[3][8] = 1.021; // Robinson to Weyerhaeuser
	Graph[8][3] = 1.021; // Weyerhaeuser to Robinson
	Graph[3][9] = 1.777; // Robinson to Dixon
	Graph[9][3] = 1.777; // Dixon to Robinson
	Graph[3][10] = 2.184; // Robinson to Cowles Auditorium
	Graph[10][3] = 2.184; // Cowles Auditorium to Robinson
	Graph[3][11] = 2.621; // Robinson to the Music Building
	Graph[11][3] = 2.621; // The Music Building to Robinson
	Graph[3][12] = 1.831; // Robinson to Westminster
	Graph[12][3] = 1.831; // Westminster to Robinson
	Graph[3][13] = 1.281; // Robinson to the Art Building
	Graph[13][3] = 1.281; // The Art Building to Robinson
	Graph[3][14] = 4.200; // Robinson to Hawthorne
	Graph[14][3] = 4.200; // Hawthorne to Robinson
	
	// To/From the Library
	Graph[4][5] = 1.644; // The Library to Hendricks
	Graph[5][4] = 1.644; // Hendricks to the Library
	Graph[4][6] = 1.052; // The Library to the HUB
	Graph[6][4] = 1.052; // The HUB to the Library
	Graph[4][7] = 1.192; // The Library to Lindaman
	Graph[7][4] = 1.192; // Lindaman to the Library
	Graph[4][8] = 1.512; // The Library to Weyerhaeuser
	Graph[8][4] = 1.512; // Weyerhaeuser to the Library
	Graph[4][9] = 1.286; // The Library to Dixon
	Graph[9][4] = 1.286; // Dixon to the Library
	Graph[4][10] = 1.566; // The Library to Cowles Auditorium
	Graph[10][4] = 1.566; // Cowles Auditorium to the Library
	Graph[4][11] = 2.031; // The Library to the Music Building
	Graph[11][4] = 2.031; // The Music Building to the Library
	Graph[4][12] = 2.764; // The Library to Westminster
	Graph[12][4] = 2.764; // Westminster to the Library
	Graph[4][13] = 2.255; // The Library to the Art Building
	Graph[13][4] = 2.255; // The Art Building to the Library
	Graph[4][14] = 3.683; // The Library to Hawthorne
	Graph[14][4] = 3.683; // Hawthorne to the Library
	
	// To/From Hendricks
	Graph[5][6] = 1.130; // Hendricks to the HUB
	Graph[6][5] = 1.130; // The HUB to Hendricks
	Graph[5][7] = 1.748; // Hendricks to Lindaman
	Graph[7][5] = 1.748; // Lindaman to Hendricks
	Graph[5][8] = 1.766; // Hendricks to Weyerhaeuser
	Graph[8][5] = 1.766; // Weyerhaeuser to Hendricks
	Graph[5][9] = 2.652; // Hendricks to Dixon
	Graph[9][5] = 2.652; // Dixon to Hendricks
	Graph[5][10] = 2.647; // Hendricks to Cowles Auditorium
	Graph[10][5] = 2.647; // Cowles Auditorium to Hendricks
	Graph[5][11] = 3.262; // Hendricks to the Music Building
	Graph[11][5] = 3.262; // The Music Building to Hendricks
	Graph[5][12] = 3.234; // Hendricks to Westminster
	Graph[12][5] = 3.234; // Westminster to Hendricks
	Graph[5][13] = 2.704; // Hendricks to the Art Building
	Graph[13][5] = 2.704; // The Art Building to Hendricks
	Graph[5][14] = 2.943; // Hendricks to Hawthorne
	Graph[14][3] = 2.943; // Hawthorne to Hendricks
	
	// To/From the HUB
	Graph[6][7] = 1.953; // The HUB to Lindaman
	Graph[7][6] = 1.953; // Lindaman to the HUB
	Graph[6][8] = 2.481; // The HUB to Weyerhaeuser
	Graph[8][6] = 2.481; // Weyerhaeuser to the HUB
	Graph[6][9] = 1.855; // The HUB to Dixon
	Graph[9][6] = 1.855; // Dixon to the HUB
	Graph[6][10] = 1.426; // The HUB to Cowles Auditorium
	Graph[10][6] = 1.426; // Cowles Auditorium to the HUB
	Graph[6][11] = 2.260; // The HUB to the Music Building
	Graph[11][6] = 2.260; // The Music Building to the HUB
	Graph[6][12] = 3.390; // The HUB to Westminster
	Graph[12][6] = 3.390; // Westminster to the HUB
	Graph[6][13] = 2.927; // The HUB to the Art Building
	Graph[13][6] = 2.927; // The Art Building to the HUB
	Graph[6][14] = 2.597; // The HUB to Hawthorne
	Graph[14][6] = 2.597; // Hawthorne to the HUB
	
	// To/From Lindaman
	Graph[7][8] = 0.553; // Lindaman to Weyerhaeuser
	Graph[8][7] = 0.553; // Weyerhaeuser to Lindaman
	Graph[7][9] = 1.548; // Lindaman to Dixon
	Graph[9][7] = 1.548; // Dixon to Lindaman
	Graph[7][10] = 1.847; // Lindaman to Cowles Auditorium
	Graph[10][7] = 1.847; // Cowles Auditorium to Lindaman
	Graph[7][11] = 2.371; // Lindaman to the Music Building
	Graph[11][7] = 2.371; // The Music Building to Lindaman
	Graph[7][12] = 2.319; // Lindaman to Westminster
	Graph[12][7] = 2.319; // Westminster to Lindaman
	Graph[7][13] = 1.919; // Lindaman to the Art Building
	Graph[13][7] = 1.919; // The Art Building to Lindaman
	Graph[7][14] = 4.657; // Lindaman to Hawthorne
	Graph[14][7] = 4.657; // Hawthorne to Lindaman
	
	// To/From Weyerhaeuser
	Graph[8][9] = 1.714; // Weyerhaeuser to Dixon
	Graph[9][8] = 1.714; // Dixon to Weyerhaeuser
	Graph[8][10] = 2.408; // Weyerhaeuser to Cowles Auditorium
	Graph[10][8] = 2.408; // Cowles Auditorium to Weyerhaeuser
	Graph[8][11] = 2.649; // Weyerhaeuser to the Music Building
	Graph[11][8] = 2.649; // The Music Building to Weyerhaeuser
	Graph[8][12] = 0.787; // Weyerhaeuser to Westminster
	Graph[12][8] = 0.787; // Westminster to Weyerhaeuser
	Graph[8][13] = 0.844; // Weyerhaeuser to the Art Building
	Graph[13][8] = 0.844; // The Art Building to Weyerhaeuser
	Graph[8][14] = 4.935; // Weyerhaeuser to Hawthorne
	Graph[14][8] = 4.935; // Hawthorne to Weyerhaeuser
	
	// To/From Dixon
	Graph[9][10] = 0.709; // Dixon to Cowles Auditorium
	Graph[10][9] = 0.709; // Cowles Auditorium to Dixon
	Graph[9][11] = 0.984; // Dixon to the Music Building
	Graph[11][9] = 0.984; // The Music Building to Dixon
	Graph[9][12] = 2.706; // Dixon to Westminster
	Graph[12][9] = 2.706; // Westminster to Dixon
	Graph[9][13] = 2.799; // Dixon to the Art Building
	Graph[13][9] = 2.799; // The Art Building to Dixon
	Graph[9][14] = 4.127; // Dixon to Hawthorne
	Graph[14][9] = 4.127; // Hawthorne to Dixon
	
	// To/From Cowles Auditorium
	Graph[10][11] = 0.701; // Cowles Auditorium to the Music Building
	Graph[11][10] = 0.701; // The Music Building to Cowles Auditorium
	Graph[10][12] = 3.455; // Cowles Auditorium to Westminster
	Graph[12][10] = 3.455; // Westminster to Cowles Auditorium
	Graph[10][13] = 3.062; // Cowles Auditorium to the Art Building
	Graph[13][10] = 3.062; // The Art Building to Cowles Auditorium
	Graph[10][14] = 3.831; // Cowles Auditorium to Hawthorne
	Graph[14][10] = 3.831; // Hawthorne to Cowles Auditorium
	
	// To/From the Music Building
	Graph[11][12] = 4.296; // The Music Building to Westminster
	Graph[12][11] = 4.296; // Westminster to the Music Building
	Graph[11][13] = 3.712; // The Music Building to the Art Building
	Graph[13][11] = 3.712; // The Art Building to the Music Building
	Graph[11][14] = 4.462; // The Music Building to Hawthorne
	Graph[14][11] = 4.462; // Hawthorne to the Music Building
	
	// To/From Westminster
	Graph[12][13] = 0.771; // Westminster to the Art Building
	Graph[13][12] = 0.771; // The Art Building to Westminster
	Graph[12][14] = 5.745; // Westminster to Hawthorne
	Graph[14][12] = 5.745; // Hawthorne to Westminster

	// To/From the Art Building
	Graph[13][14] = 5.351; // The Art Building to Hawthorne
	Graph[14][13] = 5.351; // Hawthorne to the Art Building

	// To/From Facilities
	Graph[1][2] = 1.496; // Facilities to Johnston
	Graph[2][1] = 1.496; // Johnston to Facilities
	Graph[1][3] = 1.200; // Facilities to Robinson
	Graph[3][1] = 1.200; // Robinson to Facilities
	Graph[1][4] = 2.174; // Facilities to the Library
	Graph[4][1] = 2.174; // The Library to Facilities
	Graph[1][5] = 2.018; // Facilities to Hendricks
	Graph[5][1] = 2.018; // Hendricks to Facilities
	Graph[1][6] = 3.003; // Facilities to the HUB
	Graph[6][1] = 3.003; // The HUB to Facilities
	Graph[1][7] = 2.153; // Facilities to Lindaman
	Graph[7][1] = 2.153; // Lindaman to Facilities
	Graph[1][8] = 1.948; // Facilities to Weyerhaeuser
	Graph[8][1] = 1.948; // Weyerhaeuser to Facilities
	Graph[1][9] = 2.696; // Facilities to Dixon
	Graph[9][1] = 2.696; // Dixon to Facilities
	Graph[1][10] = 3.005; // Facilities to Cowles Auditorium
	Graph[10][1] = 3.005; // Cowles Auditorium to Facilities
	Graph[1][11] = 3.660; // Facilities to the Music Building
	Graph[11][1] = 3.660; // The Music Building to Facilities
	Graph[1][12] = 1.540; // Facilities to Westminster
	Graph[12][1] = 1.540; // Westminster to Facilities
	Graph[1][13] = 0.901; // Facilities to the Art Building
	Graph[13][1] = 0.901; // The Art Building to Facilities
	Graph[1][14] = 4.634; // Facilities to Hawthorne
	Graph[14][1] = 4.634; // Hawthorne to Facilities

	double total = TravelingJanitor(Graph, visited, 1, vertices, edges);

	cout << "The fastest travel time from facilities to every other academic building is: " << total << " minutes." << endl;

	cout << endl; // endline for formatting
	system("PAUSE"); // pauses the program so that the user can see any information on the screen before the probram exits
	return 0;
}