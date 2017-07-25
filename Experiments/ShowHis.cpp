#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "../CImg.h"

using namespace std;
using namespace cimg_library;

int main(int argc, char ** argv){
	if(argc  != 5){
		cout<<"Faltan Argumentos <stegoFile1> <outstegoFile1> <stegoFile2> <outstegoFile2>"<<endl;
		return 0;
	}
	string stegoFile1(argv[1]);
	string outstegoFile1(argv[2]);
	string stegoFile2(argv[3]);
	string outstegoFile2(argv[4]);
	CImg<int> stegoImg1(stegoFile1.c_str());
	CImg<int> outstegoImg1(outstegoFile1.c_str());
	CImg<int> stegoImg2(stegoFile2.c_str());
	CImg<int> outstegoImg2(outstegoFile2.c_str());
	CImg<int> h11 = stegoImg1.get_histogram(256);
	CImg<int> h12 = outstegoImg1.get_histogram(256);
	CImg<int> h21 = stegoImg2.get_histogram(256);
	CImg<int> h22 = outstegoImg2.get_histogram(256);
	(h11,h12).get_append('c').display_graph();
	(h21,h22).get_append('c').display_graph();
}