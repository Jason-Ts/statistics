import ctypes
def least_square_method(x,y): # return b,a,r
    curpath='\\'.join(__file__.split('\\')[:-1])
    n=len(x)
    lsm=ctypes.CDLL(curpath+'\\lsm.dll')
    bar=(ctypes.c_double*3)()
    x_=(ctypes.c_double*n)()
    y_=(ctypes.c_double*n)()
    for i in range(n):
        x_[i]=x[i];y_[i]=y[i]
    n=ctypes.c_long(n)
    lsm.lsm(n,x_,y_,bar)
    return tuple(float(i) for i in tuple(bar))
