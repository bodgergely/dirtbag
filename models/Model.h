#include <memory>



template<class Input, class Label>
class Model
{
public:
	Model() : _numOfData{0} {}
	virtual ~Model() {}

	virtual Label eval(const Input& input) const { return Label;};
	virtual void train(const Input& input, const Label& target){};

	uint numOfDataPoints() const {return _numOfData;}

protected:
	uint _numOfData;

};

