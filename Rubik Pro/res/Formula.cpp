#include "Formula.h"

Operation& Operation::invert() {
	direction = direction == DOUBL ? direction : Dir(1 - int(direction));
	return *this;
}
