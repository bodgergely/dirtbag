#include <models/Model.h>
#include <vector>

class VectorOfDoubles
{
public:
	void add(double val){_vals.push_back(val);}
private:
	std::vector<double> _vals;
};


template<class Input, class Label>
class LogisticRegression : public Model<Input, Label>
{
public:
	LogisticRegression() {}
	virtual ~LogisticRegression() {}
	virtual Label eval(const Input& in) const { return 0;}
	virtual void train(const Input& input, const Label& target) {}
};


using LogisticRegressionD = LogisticRegression<VectorOfDoubles, double>;


