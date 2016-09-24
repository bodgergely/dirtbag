
#include <actions/Action.h>
#include <feedback/Feedback.h>

class MusicPlayer : public Action
{
public:

	MusicPlayer(std::vector<FeatureCB> featureCBs) : _featureCBs(featureCBs)
	{
	}

	void start()
	{
		while(true)
		{
			Array vals;
			for(auto f : _featureCBs)
				vals.add(f());

			double salience = _model.eval(vals);

			double confid = _confidence(_model.numOfDataPoints());
			if(doAction(confid, salience))
			{ // If robot is performing an action
				Feedback fb = getUserFeedback();
				_model.train(vals, fb.get());
			}


		}
	}
private:
	double confidence(uint numOfData)
	{
		return 0;
	}
	/*
	 * returns
	 * 		true: robot took some action (asked user and played music or just simply started playing music)
	 */
	bool doAction(double confidence, double salience)
	{
		if(salience > 0.5f)
		{
				if(confidence < 0.5f)
				{
					//Ask user if they like to listen to music
				}
				else
				{
					//Just play music
				}
				return true;
		}
		return false;
	}

private:
	std::vector<FeatureCB> _featureCBs;
	LogisticRegressionD	   _model;
};
