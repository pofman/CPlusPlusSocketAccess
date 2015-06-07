#include <iostream>
#include <vector>
using namespace std;

class Menu{
	protected:
		vector<string> *options;

	public:
	Menu()
	{
		options = new vector<string>();
	}

	void AddOption(string option)
	{
		options->push_back(option);
	}

	void Render()
	{
		for(vector<string>::iterator it = options->begin(); it != options->end(); ++it) {
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

	string OptionFor(int selectedOption)
	{
		try
		{
			int option = selectedOption -1;
			if(option >= 0 && option < options->size())
			{
				return (*options)[selectedOption - 1];
			}
			else
			{
				return "Option not found";
			}
		}
		catch (std::exception& e){
			return "Option not found";
		}

		//if(options->size() < selectedOption)
		//for(vector<string>::iterator it = options->begin(); it != options->end(); ++it) {
    	//	if(*it == selectedOption)
    	//		return *it;
		//}
		//return "Option not found";
	}
};
