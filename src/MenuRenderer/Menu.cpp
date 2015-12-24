#include <iostream>
#include <vector>
#include <functional>
#include "Option.cpp"
using namespace std;

class Menu{
	protected:
		vector<reference_wrapper<Option>> *options;

	public:
		Menu()
		{
			options = new vector<reference_wrapper<Option>>();
		}

		void AddOption(string option, std::function<void()> action)
		{
			Option *opt = new Option(option, action);
			options->push_back(*opt);
		}

		void Render()
		{
			for(vector<reference_wrapper<Option>>::iterator it = options->begin(); it != options->end(); ++it) {
				cout << it->get().Name() << endl;
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
					return (*options)[selectedOption - 1].get().Name();
				}
				else
				{
					return "Option not found";
				}
			}
			catch (std::exception& e){
				return "Option not found";
			}
		}
};
