#if !defined(CONFLATION_ALGORITHM)
#define CONFLATION_ALGORITHM
/*
conflatioin algorithm
n:  length of the array
array:
output:
ascend: ascending order or not
*/
void conflation(long int n,double array[n],double output[n],int ascend)
{
    long int i=0,i1=0,i2=0,n1=n/2,n2=n-n1;
    double *a1,*a2,o1[n1],o2[n2];
    // sort
    if (n==1) output[0]=array[0];
    else{
        a1=&array[0];a2=&array[n1];
        conflation(n1,a1,o1,ascend);
        conflation(n2,a2,o2,ascend);
        for (i=0;i<n;i++){
            if (ascend){
                if (o1[i1]<o2[i2]){
                    output[i]=o1[i1++];
                    if (i1==n1) break;
                }
                else{
                    output[i]=o2[i2++];
                    if (i2==n2) break;
                }
            }
            else{
                if (o1[i1]>o2[i2]){
                    output[i]=o1[i1++];
                    if (i1==n1) break;
                }
                else{
                    output[i]=o2[i2++];
                    if (i2==n2) break;
                }
            }
        }
        i++;
        if (i1==n1)
            for (;i2<n2;i++,i2++)
                output[i]=o2[i2];
        if (i2==n2)
            for (;i1<n1;i++,i1++)
                output[i]=o1[i1];
    }
}

#endif // CONFLATION_ALGORITHM
