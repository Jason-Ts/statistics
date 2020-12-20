import ctypes

conflation=ctypes.CDLL('\\'.join(__file__.split('\\')[:-1])+'\\conflation algorithm.dll')

def mdc_array(dimension,lis,types=ctypes.c_double):
    if isinstance(dimension,(list,tuple)) and len(dimension)>1:
        n=dimension[0]
        turn=(types*dimension[-1])
        for i in dimension[-2::-1]:
            turn=(turn*i)
        turn=turn()
        for i in range(n):
            turn[i]=mdc_array(dimension[1:],lis[i],types=types)
        return turn
    elif isinstance(dimension,(list,tuple)) and len(dimension)==1:
        return mdc_array(dimension[0],lis,types=types)
    elif isinstance(dimension,int):
        turn=(types*dimension)()
        for i in range(dimension):
            turn[i]=types(lis[i])
        return turn

def mdc_alloc(dimension,types=ctypes.c_double):
    if type(dimension)==int:
        return (types*dimension)()
    elif type(dimension) in (list,tuple):
        turn=types
        for i in dimension[::-1]:
            turn*=i
        return turn()

def conflation_sort(lis,ascend=True):
    n=len(lis)
    array=mdc_array(n,lis)
    output=mdc_alloc(n)
    conflation.conflation(n,array,output,ascend)
    return list(output)
