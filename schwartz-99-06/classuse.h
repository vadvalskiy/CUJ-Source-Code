// class without builtin<T> member
class aaa
{
public:
    // we are forced to write the constructor, 
    // so that we can initialize bbb.
    aaa(void) : bbb(0)
    {
    }
private:
    int bbb;
};
     
// class with builtin<T> member
class ccc
{
// the compiler-generated constructor looks 
// like this: 
//  ccc(void) 
//      : ddd() // which calls 
//              // builtin<int>::builtin(),
//              // which initializes ddd to 0.
//      {
//      }
private:
    builtin<int> ddd;
};

