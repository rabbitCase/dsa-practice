#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float stdDev(float a[100], float n) //Make sure function's return type is float//
{
    int i;
    float sum=0,mean,dev[100],sq[100],sd,mean1,sum1=0;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
    }
    mean=sum/n;
    for(i=0;i<n;i++)
    {
        dev[i]=a[i]-mean;
    }
    for(i=0;i<n;i++)
    {
        sq[i]=dev[i]*dev[i];
    }
    for(i=0;i<n;i++)
    {
        sum1+=sq[i];
    }
    mean1=sum1/n;
    sd=sqrt(mean1);
    return sd;
}

int main()
{
    int i;
    float a[100],n,sum,mean,z,percentage,new[100],count=0;
    printf("Enter array size: ");
    scanf("%f",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }
    z=stdDev(a,n);
    printf("Standard Deviation is : %0.2f",z);
    for(i=0;i<n;i++)
    {
        sum+=a[i];
    }
    mean=sum/n;
    float upper=mean+0.25;
    float lower=mean-0.25;
    for(i=0;i<n;i++)
    {
        if(a[i]>lower && a[i]<upper)
        {
            new[i]=a[i];
            count++;
        }
    }
    percentage=(count/n)*100;
    printf("\nThe percentage of elements that lie within the range (%0.2f-%0.2f) and (%0.2f+%0.2f) is: %0.2f",mean,z,mean,z,percentage);
}
