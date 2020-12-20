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
    double a1[n1],a2[n2],o1[n1],o2[n2];
    // divide
    for (;i<n1;i++)
        a1[i]=array[i];
    for (i=0;i<n2;i++)
        a2[i]=array[i+n1];
    // sort
    if (n==1) output[0]=array[0];
    else if (n==2){
        if (ascend){
            output[0]=(array[0]<array[1]) ? array[0] : array[1];
            output[1]=(array[0]>array[1]) ? array[0] : array[1];
        }
        else{
            output[0]=(array[0]>array[1]) ? array[0] : array[1];
            output[1]=(array[0]<array[1]) ? array[0] : array[1];
        }
    }
    else{
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
