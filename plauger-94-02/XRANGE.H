Listing 6 -- class xrange

class xrange : public xruntime {
protected:
	virtual void do_raise();
public:
	xrange(const char *what_arg = 0, const char *where_arg 
= 0,
		const char *why_arg = 0);
	virtual ~xrange();
	}; 
