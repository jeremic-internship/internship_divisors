#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
	vector< vector< vector< int > > > primefactors;
	string line;
	ifstream infile;
	infile.open("primefactor.res");
	while(!infile.eof()) {
		getline(infile, line);
		cout << line << endl;\
	
		std::stringstream test(line);
		std::string segment;
		vector < vector < int > > seglist;

		while(std::getline(test, segment, '='))
		{	
			vector < int > tempvector;
			string newSegment = segment;
			newSegment.erase(std::remove(newSegment.begin(),newSegment.end(),' '),newSegment.end());
			std::string starsegment;
			std::stringstream newSegmentStream(newSegment);
			while(std::getline(newSegmentStream, starsegment, '*')){
				tempvector.push_back(atoi(starsegment.c_str()));
			}
			
			seglist.push_back(tempvector);

		}

			primefactors.push_back(seglist);
	
	}
	

	

}