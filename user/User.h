#include <feedback/Feedback.h>
#include <actions/ActionType.h>

class User
{
public:
	Feedback feedback(ActionType actiontype) {return Feedback(actiontype);}
};


using UserPtr = std::shared_ptr<User>;
