class foo
{
private:
        builtin<int> b;
};
     
void xyz(void)
{
        // invokes builtin<float>::builtin(), 
        // so x is initialized to 0.
        builtin<float> x;
     
        // the compiler-generated foo::foo() invokes builtin<int>::builtin(), 
        // so y.b is initialized to 0.
        foo y;
}

