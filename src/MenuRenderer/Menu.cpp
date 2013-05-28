#include <iostream>
#include <vector>
#include <malloc.h>
using namespace std;

class Menu{
	protected:
		vector<int> *options;

	public:
	Menu()
	{
		options = new vector<int>();
	}

	void AddOption(int option)
	{
		options->push_back(option);
	}

	void Render()
	{
		for(vector<int>::iterator it = options->begin(); it != options->end(); ++it) {
    		cout << *it << endl;
		}
		WaitForInput();
	}
	private:
	void WaitForInput()
	{
		int input;
		cin >> input;
		cout << OptionFor(input) << endl;
	}

	int OptionFor(int selectedOption)
	{
		for(vector<int>::iterator it = options->begin(); it != options->end(); ++it) {
    		if(*it == selectedOption)
    			return *it;
		}

		return -1;
	}
};
