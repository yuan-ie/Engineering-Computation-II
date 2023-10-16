class cplx:

    # constructor
    def __init__(self,r=0,i=0):
        self._real = r
        self._imag = i

    def disp(self):
        print( "(" , self._real , "," , self._imag , ")" )

    def set_real(self,r):
        self._real = r
    
    def set_imag(self,i):
        self._image = i

    def mag(self):
        return sqrt(self._real**2 + self._imag**2)
    
    def __add__(self,op2):
        tmp = cplx()
        tmp.set_real(self._real + op2._real)
        tmp.set_imag(self._imag + op2._imag)
        return tmp

def main():
    x = cplx()
    y = cplx()

    x.set_real(4)
    x.set_imag(5)

    x.disp()
    print(x.mag())

    print("\n")
    y = cplx(-4,3)
    z = x + y
    z.disp()
    
    if __name__=="__main__":
        main()