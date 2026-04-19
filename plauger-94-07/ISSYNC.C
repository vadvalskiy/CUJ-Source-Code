// issync -- istream::sync()
#include <istream>

int istream::sync()
	{	// synchronize buffer
	if (!good())
		return (EOF);
	else if (rdbuf()->pubsync() == EOF)
		{	// note sync failure
		setstate(badbit);
		return (EOF);
		}
	else
		return (0);
	}

