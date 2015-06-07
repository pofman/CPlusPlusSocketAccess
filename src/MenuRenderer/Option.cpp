#include <functional>
using namespace std;

class Option
{
	protected:
		string name;
		std::function<void()> action;
	public:
			Option(string pName, std::function<void()> pAction)
			{
				name = pName;
				action = pAction;
			}
};
