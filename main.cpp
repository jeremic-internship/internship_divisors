#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

vector< vector< vector< int > > > primefactors;
vector <int> combination;
std::vector<int> divisors;


vector < int > addObjectToVector(vector <int> startVector, int num){
	if(std::find(startVector.begin(), startVector.end(), num) == startVector.end()){
		startVector.push_back(num);
	}
	return startVector;
}

void go(vector <int> factors,int offset, int k) {
	if (k == 0) {
		int total = 1;
		for (int i = 0; i < combination.size(); i++){
			total *= combination[i];
		}
		divisors = addObjectToVector(divisors, total);
		return;
	}
	for (int i = offset; i <= factors.size() - k; ++i) {
		combination.push_back(factors[i]);
		go(factors, i+1, k-1);
		combination.pop_back();
	}
}


int main(){
	string line;
	ifstream infile;
	infile.open("primefactor.res");
	while(!infile.eof()) {
		getline(infile, line);
		cout << line << endl;
	
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

	for(int i = 0; i < primefactors.size()-1; i++){
		divisors.push_back(1);
		
		for(int z = 1; z < primefactors[i][0].size(); z++){
			go(primefactors[i][0], 0, z);
		}

		divisors.push_back(primefactors[i][1][0]);

		for(int i = 0; i < divisors.size(); i++){
			cout << divisors[i] << " ";
		}
		cout << "\n";
		divisors.clear();
	}

}
	