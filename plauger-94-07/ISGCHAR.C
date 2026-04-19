// isgchar -- istream::get(char&)
#include <istream>

istream& istream::get(char& c)
	{	// get a char
	int ch = get();
	if (ch != EOF)
		c = ch;
	return (*this);
	}
