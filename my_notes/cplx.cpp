

class cplx
{
    private:
        double real;
        double imag;
    public:
        cplx(double r=0, double i=0)
        {
            real = r;
            imag = i;
        }
        
};

int main()
{
    cplx x(4,3);
    cplx y;

    return 0;
}
//run -> g++ file.cpp -o filename