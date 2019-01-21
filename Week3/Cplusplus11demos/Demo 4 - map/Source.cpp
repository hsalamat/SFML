//std::map is a sorted associative container that contains key-value pairs with unique keys.
//std::pair is a struct template that provides a way to store two heterogeneous objects as a single unit. A pair is a specific case of a std::tuple with two elements.
#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<string, string> TStrStrMap;
typedef pair<string, string> TStrStrPair;

int main(int argc, char *argv[])
{
	TStrStrMap tMap;

	tMap.insert(TStrStrPair("yes", "no"));
	tMap.insert(TStrStrPair("up", "down"));
	tMap.insert(TStrStrPair("left", "right"));
	tMap.insert(TStrStrPair("good", "bad"));

	string s;

	cout << "Enter word: " << std::endl;;
	cin >> s;


	string strValue = tMap[s];
	if (strValue != "")
	{
		// Show value
		cout << "Opposite: " << strValue << endl;
	}
	else
	{
		TStrStrMap::iterator p;
		bool bFound = false;
		// Show key
		for (p = tMap.begin(); p != tMap.end(); ++p)
		{
			string strKey;
			strValue = s;
			strKey = p->second;
			if (strValue == strKey)
			{
				// Return key
				cout << "Opposite: " << p->first << endl;
				bFound = true;
			}
		}
		// If not found opposite word
		if (!bFound)
		{
			cout << "Word not in map." << endl;
		}
	}

	system("pause");
	return 0;
}
