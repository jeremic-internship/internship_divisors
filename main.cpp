#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

std::vector< std::vector< std::vector< int > > > primefactors;
std::vector <int> combination;
std::vector<int> divisors;


std::vector < int > addObjectToVector(std::vector <int> startVector, int num) {
	if (std::find(startVector.begin(), startVector.end(), num) == startVector.end()) {
		startVector.push_back(num);
	}
	return startVector;
}

void go(std::vector <int> factors, int offset, int k) {
	if (k == 0) {
		int total = 1;
		for (int i = 0; i < combination.size(); i++) {
			total *= combination[i];
		}
		divisors = addObjectToVector(divisors, total);
		return;
	}
	for (int i = offset; i <= factors.size() - k; ++i) {
		combination.push_back(factors[i]);
		go(factors, i + 1, k - 1);
		combination.pop_back();
	}
}

void writeDivisorsToFile(std::string filename) {
	std::ofstream divisorFile;
	divisorFile.open ("divisors.res");

	for (int i = 0; i < primefactors.size() - 1; i++) {
		divisors.push_back(1);

		for (int z = 1; z < primefactors[i][0].size(); z++) {
			go(primefactors[i][0], 0, z);
		}

		divisors.push_back(primefactors[i][1][0]);

		divisorFile << "All the divisors of " << primefactors[i][1][0] << " are ";

		for (int i = 0; i < divisors.size(); i++) {
			if (i != 0) {
				divisorFile << ", ";
			}
			divisorFile << divisors[i];
		}
		divisorFile << "\n";
		divisors.clear();
	}

	divisorFile.close();
}


int main() {
	std::string line;
	std::ifstream infile;
	infile.open("primefactor.res");

	while (!infile.eof()) {
		getline(infile, line);
		std::stringstream test(line);
		std::string segment;
		std::vector < std::vector < int > > seglist;
		while (std::getline(test, segment, '='))
		{
			std::vector < int > tempvector;
			std::string newSegment = segment;
			newSegment.erase(std::remove(newSegment.begin(), newSegment.end(), ' '), newSegment.end());
			std::string starsegment;
			std::stringstream newSegmentStream(newSegment);
			while (std::getline(newSegmentStream, starsegment, '*')) {
				tempvector.push_back(atoi(starsegment.c_str()));
			}
			seglist.push_back(tempvector);
		}
		primefactors.push_back(seglist);
	}
	writeDivisorsToFile("divisors.res");

	return 0;

}
