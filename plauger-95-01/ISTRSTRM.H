class istrstream : public istream {
public:
       istrstream(const char* s);
        istrstream(const char* s, int n);
        istrstream(char* s);
        istrstream(char* s, int n);
        virtual ~istrstream();
        strstreambuf* rdbuf() const;
        char *str();
private:
//      strstreambuf sb;       exposition only
};

