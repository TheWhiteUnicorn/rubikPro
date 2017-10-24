#include "res.hpp"

Dir operator++(Dir& d) {
	d = Dir(int(d) + 1);
	if (d == 3)
		d = Dir(0);
	return d;
}

Dir operator--(Dir& d) {
	d = Dir(int(d) - 1);
	if (d == -1)
		d = Dir(2);
	return d;
}