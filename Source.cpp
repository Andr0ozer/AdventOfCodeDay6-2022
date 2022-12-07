#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string input;
	bool found = false, partII = false;
	vector<char> markers;
	int firstmarker = 0, siglength = 4;
	ifstream infile;
	if (partII)
	{
		siglength = 14;
	}
	infile.open("input.txt");
	getline(infile, input);
	infile.close();

	for (int i = 0; i < input.size(); i++)
	{
		markers.push_back(input[i]);
	}
	for (int j = siglength - 1; j < markers.size(); j++)
	{
		found = true;
		for (int k = 0; k < siglength; k++)
		{
			for (int l = 0; l < siglength; l++)
			{
				if (k != l)
				{
					if (markers[j - k] == markers[j - l])
					{
						found = false;
					}
				}
			}
		}
		if (found)
		{
			firstmarker = j + 1;
			j = markers.size();
		}
	}
	cout << firstmarker;
}