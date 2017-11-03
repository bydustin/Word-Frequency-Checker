#include "SetList.h"
#include "MapArray.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	ifstream og("sample_doc.txt");
	ifstream exclist("stopwords.txt");
	ofstream out("frequency.txt");
	SetList<string> mySet;
	map<string, int> M;
	vector<string> V;
	for_each(istream_iterator<string>(exclist), // start of source
		istream_iterator<string>(), // end of source, EOF
		[&](string str1) {
		mySet.insert(str1); });

	for_each(istream_iterator<string>(og), // start of source
		istream_iterator<string>(), // end of source, EOF
		[&](string str1) {
		transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
		if (mySet.find(str1) == mySet.end()) {
			M[str1]++;
		}});
	for (auto E : M) {
		cout << E.first << " is " << E.second << endl;
		out << E.first << " is " << E.second << endl;
	}
	return 0;
}