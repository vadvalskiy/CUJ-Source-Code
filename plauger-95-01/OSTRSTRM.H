class ostrstream : public ostream {
public:
        ostrstream();
        ostrstream(char* s, int n, openmode mode = out);
        virtual ~ostrstream();
        strstreambuf* rdbuf() const;
        void freeze(int freezefl = 1);
        char* str();
        int pcount() const;
private:
//      strstreambuf sb;	exposition only
};

