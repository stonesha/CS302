#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	string line;

	while(line != ".exit"){
		cout << "> ";
		getline(cin, line);

	}

	return 0;
}
