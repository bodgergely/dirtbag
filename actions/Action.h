#include <infra/Daemon.h>
#include <feedback/Feedback.h>
#include <user/User.h>
#include <actions/ActionType.h>

using FeatureCB = std::function<double()>();

using UserSadnessCB = std::function<double()>;
using RainyDayCB = std::function<double()>;


using Array = VectorOfDoubles;



class Action : public Daemon
{
public:
	Action() : _actionType(ActionType::Invalid)  {}
	virtual ~Action() {}
	Feedback getUserFeedback()
	{
		return queryUser(_actionType);
	}
protected:
	virtual double doAction(double confidence, double salience) = 0;

	Feedback queryUser(ActionType actionType)
	{
		return _user->feedback(actionType);
	}
	virtual double _confidence(uint numOfData) = 0;

private:
	UserPtr _user;
	ActionType _actionType;
};
