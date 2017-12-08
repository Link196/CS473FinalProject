///////////////////////////////////////////////////////////////////////
// Group Members: Andrew Hutson, McKenna Galle, Vina Le
// Assignment and Course: CS 473 Final Project
// Date Modified: 11/29/2017
///////////////////////////////////////////////////////////////////////

// Graph adapted from https://quickgrid.wordpress.com/2015/05/30/inputting-directed-undirected-weighted-and-unweighted-graph-in-c-c-adjacency-matrix/

#include <iostream>
#include "Building.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	//int num_classes = 0; // variable to store the number of classes the student is taking
	//cout << "How many buildings will be in your route? ";
	//cin >> num_classes;

	//cout << "You entered " << num_classes << " building(s)." << endl; // for debugging

	//cout << endl; // endline for formatting

	// Building object creation
	Building Johnston(1, "Johnston", 35);
	Building Robinson(2, "Robinson", 24);
	Building Library(3, "Library", 24);
	Building Hendricks(4, "Hendricks", 25);
	Building HUB(5, "The HUB", 26);
	Building Lindaman(6, "Lindaman", 26);
	Building Weyerhaeuser(7, "Weyerhaeuser", 22);
	Building Dixon(8, "Dixon", 23);
	Building Cowles(9, "Cowles Auditorium", 23);
	Building Music(10, "Music Building", 22);
	Building Westminster(11, "Westminster", 22);
	Building Art(12, "Art Building", 23);
	Building Hawthorne(13, "Hawthorne", 22);
	Building Stewart(14, "Stewart", 16); 
	Building Arend(15, "Arend", 14);
	Building BJ(16, "Baldwin-Jenkins", 14);
	Building Oliver(17, "Oliver", 17);
	Building Duvall(18, "Duvall", 14);
	Building Boppell(19, "Boppell", 14);
	Building Warren(20, "Warren", 14);
	Building Mac(21, "McMillan", 14);
	Building Ballard(22, "Ballard", 14);

	double Graph[23][23]; // two-dimensional array to store the graph
	int vertices = 23; // number of buildings
	int edges = 23; //number of paths per building

	// initialize the graph
	for (int i = 0; i < vertices; i++)
		for (int j = 0; j < edges; j++)
			Graph[i][j] = 0;

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
	Graph[1][14] = 1.052; // Johnston to Stewart
	Graph[14][1] = 1.052; // Stewart to Johnston
	Graph[1][15] = 0.971; // Johnston to Arend
	Graph[15][1] = 0.971; // Arend to Johnston
	Graph[1][16] = 0.901; // Johnston to BJ
	Graph[16][1] = 0.901; // BJ to Johnston
	Graph[1][17] = 2.145; // Johnston to Oliver
	Graph[17][1] = 2.145; // Oliver to Johnston
	Graph[1][18] = 2.821; // Johnston to Duvall
	Graph[18][1] = 2.821; // Duvall to Johnston
	Graph[1][19] = 2.379; // Johnston to Boppell
	Graph[19][1] = 2.379; // Boppell to Johnston
	Graph[1][20] = 2.966; // Johnston to Warren
	Graph[20][1] = 2.966; // Warren to Johnston
	Graph[1][21] = 2.379; // Johnston to Mac
	Graph[21][1] = 2.379; // Mac to Johnston
	Graph[1][22] = 2.639; // Johnston to Ballard
	Graph[22][1] = 2.639; // Ballard to Johnston

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
	Graph[2][14] = 1.306; // Robinson to Stewart
	Graph[14][2] = 1.306; // Stewart to Robinson
	Graph[2][15] = 1.745; // Robinson to Arend
	Graph[15][2] = 1.745; // Arend to Robinson
	Graph[2][16] = 1.091; // Robinson to BJ
	Graph[16][2] = 1.091; // BJ to Robinson
	Graph[2][17] = 2.361; // Robinson to Oliver
	Graph[17][2] = 2.361; // Oliver to Robinson
	Graph[2][18] = 2.805; // Robinson to Duvall
	Graph[18][2] = 2.805; // Duvall to Robinson
	Graph[2][19] = 2.922; // Robinson to Boppell
	Graph[19][2] = 2.922; // Boppell to Robinson
	Graph[2][20] = 1.891; // Robinson to Warren
	Graph[20][2] = 1.891; // Warren to Robinson
	Graph[2][21] = 1.532; // Robinson to Mac
	Graph[21][2] = 1.532; // Mac to Robinson
	Graph[2][22] = 1.930; // Robinson to Ballard
	Graph[22][2] = 1.930; // Ballard to Robinson

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
	Graph[3][14] = 2.431; // The Library to Stewart
	Graph[14][3] = 2.431; // Stewart to the Library
	Graph[3][15] = 1.127; // The Library to Arend
	Graph[15][3] = 1.127; // Arend to the Library
	Graph[3][16] = 2.704; // The Library to BJ
	Graph[16][3] = 2.704; // BJ to the Library
	Graph[3][17] = 3.187; // The Library to Oliver
	Graph[17][3] = 3.187; // Oliver to the Library
	Graph[3][18] = 3.005; // The Library to Duvall
	Graph[18][3] = 3.005; // Duvall to the Library
	Graph[3][19] = 2.457; // The Library to Boppell
	Graph[19][3] = 2.457; // Boppell to the Library
	Graph[3][20] = 1.423; // The Library to Warren
	Graph[20][3] = 1.423; // Warren to the Library
	Graph[3][21] = 2.047; // The Library to Mac
	Graph[21][3] = 2.047; // Mac to the Library
	Graph[3][22] = 2.374; // The Library to Ballard
	Graph[22][3] = 2.374; // Ballard to the Library

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
	Graph[4][14] = 0.392; // Hendricks to Stewart
	Graph[14][4] = 0.392; // Stewart to Hendricks
	Graph[4][15] = 0.917; // Hendricks to Arend
	Graph[15][4] = 0.917; // Arend to Hendricks
	Graph[4][16] = 0.901; // Hendricks to BJ
	Graph[16][4] = 0.901; // BJ to Hendricks
	Graph[4][17] = 1.662; // Hendricks to Oliver
	Graph[17][4] = 1.662; // Oliver to Hendricks
	Graph[4][18] = 2.034; // Hendricks to Duvall
	Graph[18][4] = 2.034; // Duvall to Hendricks
	Graph[4][19] = 1.416; // Hendricks to Boppell
	Graph[19][4] = 1.416; // Boppell to Hendricks
	Graph[4][20] = 2.636; // Hendricks to Warren
	Graph[20][4] = 2.636; // Warren to Hendricks
	Graph[4][21] = 2.439; // Hendricks to Mac
	Graph[21][4] = 2.439; // Mac to Hendricks
	Graph[4][22] = 2.745; // Hendricks to Ballard
	Graph[22][4] = 2.745; // Ballard to Hendricks

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
	Graph[5][14] = 1.486; // The HUB to Stewart
	Graph[14][5] = 1.486; // Stewart to the HUB
	Graph[5][15] = 0.364; // The HUB to Arend
	Graph[15][5] = 0.364; // Arend to the HUB
	Graph[5][16] = 1.930; // The HUB to BJ
	Graph[16][5] = 1.930; // BJ to the HUB
	Graph[5][17] = 2.182; // The HUB to Oliver
	Graph[17][5] = 2.182; // Oliver to the HUB
	Graph[5][18] = 2.047; // The HUB to Duvall
	Graph[18][5] = 2.047; // Duvall to the HUB
	Graph[5][19] = 1.431; // The HUB to Boppell
	Graph[19][5] = 1.431; // Boppell to the HUB
	Graph[5][20] = 2.299; // The HUB to Warren
	Graph[20][5] = 2.299; // Warren to the HUB
	Graph[5][21] = 2.940; // The HUB to Mac
	Graph[21][5] = 2.940; // Mac to the HUB
	Graph[5][22] = 3.447; // The HUB to Ballard
	Graph[22][5] = 3.447; // Ballard to the HUB

	// To/From Lindaman
	Graph[6][7] = 0.553; // Lindaman to Weyerhaeuser
	Graph[7][6] = 0.553; // Weyerhaeuser to Lindaman
	Graph[6][8] = 1.548; // Lindaman to Dixon
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
	Graph[6][14] = 3.442; // Lindaman to Stewart
	Graph[14][6] = 3.442; // Stewart to Lindaman
	Graph[6][15] = 2.057; // Lindaman to Arend
	Graph[15][6] = 2.057; // Arend to Lindaman
	Graph[6][16] = 2.834; // Lindaman to BJ
	Graph[16][6] = 2.834; // BJ to Lindaman
	Graph[6][17] = 4.042; // Lindaman to Oliver
	Graph[17][6] = 4.042; // Oliver to Lindaman
	Graph[6][18] = 3.891; // Lindaman to Duvall
	Graph[18][6] = 3.891; // Duvall to Lindaman
	Graph[6][19] = 3.306; // Lindaman to Boppell
	Graph[19][6] = 3.306; // Boppell to Lindaman
	Graph[6][20] = 1.616; // Lindaman to Warren
	Graph[20][6] = 1.616; // Warren to Lindaman
	Graph[6][21] = 1.265; // Lindaman to Mac
	Graph[21][6] = 1.265; // Mac to Lindaman
	Graph[6][22] = 1.512; // Lindaman to Ballard
	Graph[22][6] = 1.512; // Ballard to Lindaman

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
	Graph[7][14] = 4.008; // Weyerhaeuser to Stewart
	Graph[14][7] = 4.008; // Stewart to Weyerhaeuser
	Graph[7][15] = 2.904; // Weyerhaeuser to Arend
	Graph[15][7] = 2.904; // Arend to Weyerhaeuser
	Graph[7][16] = 2.665; // Weyerhaeuser to BJ
	Graph[16][7] = 2.665; // BJ to Weyerhaeuser
	Graph[7][17] = 4.026; // Weyerhaeuser to Oliver
	Graph[17][7] = 4.026; // Oliver to Weyerhaeuser
	Graph[7][18] = 4.364; // Weyerhaeuser to Duvall
	Graph[18][7] = 4.364; // Duvall to Weyerhaeuser
	Graph[7][19] = 3.743; // Weyerhaeuser to Boppell
	Graph[19][7] = 3.743; // Boppell to Weyerhaeuser
	Graph[7][20] = 1.343; // Weyerhaeuser to Warren
	Graph[20][7] = 1.343; // Warren to Weyerhaeuser
	Graph[7][21] = 0.642; // Weyerhaeuser to Mac
	Graph[21][7] = 0.642; // Mac to Weyerhaeuser
	Graph[7][22] = 0.938; // Weyerhaeuser to Ballard
	Graph[22][7] = 0.938; // Ballard to Weyerhaeuser

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
	Graph[8][14] = 3.714; // Dixon to Stewart
	Graph[14][8] = 3.714; // Stewart to Dixon
	Graph[8][15] = 2.283; // Dixon to Arend
	Graph[15][8] = 2.283; // Arend to Dixon
	Graph[8][16] = 3.055; // Dixon to BJ
	Graph[16][8] = 3.055; // BJ to Dixon
	Graph[8][17] = 4.460; // Dixon to Oliver
	Graph[17][8] = 4.460; // Oliver to Dixon
	Graph[8][18] = 4.216; // Dixon to Duvall
	Graph[18][8] = 4.216; // Duvall to Dixon
	Graph[8][19] = 3.855; // Dixon to Boppell
	Graph[19][8] = 3.855; // Boppell to Dixon
	Graph[8][20] = 0.805; // Dixon to Warren
	Graph[20][8] = 0.805; // Warren to Dixon
	Graph[8][21] = 2.231; // Dixon to Mac
	Graph[21][8] = 2.231; // Mac to Dixon
	Graph[8][22] = 1.865; // Dixon to Ballard
	Graph[22][8] = 1.865; // Ballard to Dixon

	// To/From Cowles Auditorium
	Graph[9][10] = 0.701; // Cowles Auditorium to the Music Building
	Graph[10][9] = 0.701; // The Music Building to Cowles Auditorium
	Graph[9][11] = 3.455; // Cowles Auditorium to Westminster
	Graph[11][9] = 3.455; // Westminster to Cowles Auditorium
	Graph[9][12] = 3.062; // Cowles Auditorium to the Art Building
	Graph[12][9] = 3.062; // The Art Building to Cowles Auditorium
	Graph[9][13] = 3.831; // Cowles Auditorium to Hawthorne
	Graph[13][9] = 3.831; // Hawthorne to Cowles Auditorium
	Graph[9][14] = 3.273; // Cowles Auditorium to Stewart
	Graph[14][9] = 3.273; // Stewart to Cowles Auditorium
	Graph[9][15] = 2.584; // Cowles Auditorium to Arend
	Graph[15][9] = 2.584; // Arend to Cowles Auditorium
	Graph[9][16] = 3.325; // Cowles Auditorium to BJ
	Graph[16][9] = 3.325; // BJ to Cowles Auditorium
	Graph[9][17] = 4.270; // Cowles auditorium to Oliver
	Graph[17][9] = 4.270; // Oliver to Cowles Auditorium
	Graph[9][18] = 4.065; // Cowles Auditorium to Duvall
	Graph[18][9] = 4.065; // Duvall to Cowles Auditorium
	Graph[9][19] = 3.478; // Cowles Auditorium to Boppell
	Graph[19][9] = 3.478; // Boppell to Cowles Auditorium
	Graph[9][20] = 1.322; // Cowles Auditorium to Warren
	Graph[20][9] = 1.322; // Warrenn to Cowles Auditorium
	Graph[9][21] = 2.857; // Cowles Auditorium to Mac
	Graph[21][9] = 2.857; // Mac to Cowles Auditorium
	Graph[9][22] = 2.569; // Cowles Auditorium to Ballard
	Graph[22][9] = 2.569; // Ballard to Cowles Auditorium

	// To/From the Music Building
	Graph[10][11] = 4.296; // The Music Building to Westminster
	Graph[11][10] = 4.296; // Westminster to the Music Building
	Graph[10][12] = 3.712; // The Music Building to the Art Building
	Graph[12][10] = 3.712; // The Art Building to the Music Building
	Graph[10][13] = 4.462; // The Music Building to Hawthorne
	Graph[13][10] = 4.462; // Hawthorne to the Music Building
	Graph[10][14] = 4.590; // The Music Building to Stewart
	Graph[14][10] = 4.590; // Stewart to the Music Building
	Graph[10][15] = 2.943; // The Music Building to Arend
	Graph[15][10] = 2.943; // Arend to the Music Building
	Graph[10][16] = 3.792; // The Music Building to BJ
	Graph[16][10] = 3.792; // BJ to the Music Building
	Graph[10][17] = 4.977; // The Music Building to Oliver
	Graph[17][10] = 4.977; // Oliver to the Music Building
	Graph[10][18] = 4.909; // The Music Building to Duvall
	Graph[18][10] = 4.909; // Duvall to the Music Building
	Graph[10][19] = 4.171; // The Music Building to Boppell
	Graph[19][10] = 4.171; // Boppell to the Music Building
	Graph[10][20] = 1.540; // The Music Building to Warren
	Graph[20][10] = 1.540; // Warren to the Music Building
	Graph[10][21] = 2.301; // The Music Building to Mac
	Graph[21][10] = 2.301; // Mac to the Music Building
	Graph[10][22] = 2.068; // The Music Building to Ballard
	Graph[22][10] = 2.068; // ballard to the Music Building
	
	// To/From Westminster
	Graph[11][12] = 0.771; // Westminster to the Art Building
	Graph[12][11] = 0.771; // The Art Building to Westminster
	Graph[11][13] = 5.745; // Westminster to Hawthorne
	Graph[13][11] = 5.745; // Hawthorne to Westminster
	Graph[11][14] = 3.088; // Westminster to Stewart
	Graph[14][11] = 3.088; // Stewart to Westminster
	Graph[11][15] = 3.070; // Westminster to Arend
	Graph[15][11] = 3.070; // Arend to Westminster
	Graph[11][16] = 2.987; // Westminster to BJ
	Graph[16][11] = 2.987; // BJ to Westminster
	Graph[11][17] = 4.218; // Westminster to Oliver
	Graph[17][11] = 4.218; // Oliver to Westminster
	Graph[11][18] = 4.735; // Westminster to Duvall
	Graph[18][11] = 4.735; // Duvall to Westminster
	Graph[11][19] = 4.595; // Westminster to Boppell
	Graph[19][11] = 4.595; // Boppell to Westminster
	Graph[11][20] = 2.535; // Westminster to Warren
	Graph[20][11] = 2.535; // Warren to Westminster
	Graph[11][21] = 1.535; // Westminster to Mac
	Graph[21][11] = 1.535; // Mac to Westminster
	Graph[11][22] = 1.823; // Westminster to Ballard
	Graph[22][11] = 1.823; // Ballard to Westminster
	
	// To/From the Art Building
	Graph[12][13] = 5.351; // The Art Building to Hawthorne
	Graph[13][12] = 5.351; // Hawthorne to the Art Building
	Graph[12][14] = 2.478; // The Art Building to Stewart
	Graph[14][12] = 2.478; // Stewart to the Art Building
	Graph[12][15] = 3.044; // The Art Building to Arend
	Graph[15][12] = 3.044; // Arend to the Art Building
	Graph[12][16] = 2.470; // The Art Building to BJ
	Graph[16][12] = 2.470; // BJ to the Art Building
	Graph[12][17] = 3.613; // The Art Building to Oliver
	Graph[17][12] = 3.613; // Oliver to the Art Building
	Graph[12][18] = 4.249; // The Art Building to Duvall
	Graph[18][12] = 4.249; // Duvall to the Art Building
	Graph[12][19] = 3.818; // The Art Building to Boppell
	Graph[19][12] = 3.818; // Boppell to the Art Building
	Graph[12][20] = 2.494; // The Art Building to Warren
	Graph[20][12] = 2.494; // Warren to the Art Building
	Graph[12][21] = 1.382; // The Art Building to Mac
	Graph[21][12] = 1.382; // Mac to the Art Building
	Graph[12][22] = 1.727; // The Art Building to Ballard
	Graph[22][12] = 1.727; // Ballard to the Art Building

	// To/From Hawthorne
	Graph[13][14] = 2.852; // Hawthorne to Stewart
	Graph[14][13] = 2.852; // Stewart to Hawthorne
	Graph[13][15] = 2.740; // Hawthorne to Arend
	Graph[15][13] = 2.740; // Arend to Hawthorne
	Graph[13][16] = 3.579; // Hawthorne to BJ
	Graph[16][13] = 3.579; // BJ to Hawthorne
	Graph[13][17] = 3.374; // Hawthorne to Oliver
	Graph[17][13] = 3.374; // Oliver to Hawthorne
	Graph[13][18] = 2.844; // Hawthorne to Duvall
	Graph[18][13] = 2.844; // Duvall to Hawthorne
	Graph[13][19] = 2.151; // Hawthorne to Boppell
	Graph[19][13] = 2.151; // Boppell to Hawthorne
	Graph[13][20] = 4.935; // Hawthorne to Warren
	Graph[20][13] = 4.935; // Warren to Hawthorne
	Graph[13][21] = 5.688; // Hawthorne to Mac
	Graph[21][13] = 5.688; // Mac to Hawthorne
	Graph[13][22] = 5.969; // Hawthorne to Ballard
	Graph[22][13] = 5.969; // Ballard to Hawthorne

	// output the graph for debugging purposes
	for (int i = 1; i < vertices; i++)
		for (int j = 1; j < edges; j++)
		{
			if (Graph[i][j] != 0)
				cout << "Graph[" << i << "][" << j << "] = " << Graph[i][j] << endl;
			else
				cout << "Graph[" << i << "][" << j << "] = N/A" << endl;
		}

	cout << endl; // endline for formatting
	system("PAUSE"); // pauses the program so that the user can see any information on the screen before the probram exits
	return 0;
}