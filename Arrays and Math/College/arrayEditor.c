//Very Basic Array editor to sort an array, compare magnitude of array elements, perform bubble sort and insert/delete arrary elemets
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[30],i,t,n,order;
    printf("\n\n------------------------------------------------------");
    printf("\n------------------------------------------------------");
    printf("\nWELCOME TO ARRAY EDITOR!\n");
    printf("\nTHIS EDITOR CAN:\n\n1. Find the smallest and greatest value in your array.\n2. Sort your array in ascending and descending order.\n3. Insert a value specified by you into your array.\n4. Delete an element from your array.");
    printf("\n------------------------------------------------------");
    printf("\nLets enter an Array to begin with");
    printf("\nEnter the number of elements you want in your array: ");
    scanf("%d",&n);
    printf("\nCOOL\n");
    for(i=0,t=1;i<n,t<=n;i++)
    {
        printf("Enter number %d: ",t);
        scanf("%d",&arr[i]);
        t++;
    }
    printf("\nOKAY, Let's start performing some operations.\n\n");
    printf("Press 1 to find the smallest and largest value in your array.\n");
    printf("Press 2 to sort your array in ascending order and 3 to sort it in descending order.\n");
    printf("Press 4 to insert a number into your array.\n");
    printf("Press 5 to delete something from your array.\n");
    printf("Press 6 if you want to exit the editor.\n");
    printf("\nYour current array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
        do
        {
            printf("\nEnter the number corrresponding to the action you want the editor to do: ");
        scanf("%d",&order);

        if(order==1)
        {
            printf("\nOkay, finding the smallest and the largest guys in your array...\n");
    //----------//
    int greatest,smallest;
    greatest=arr[0],smallest=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>greatest)
        {
            greatest=arr[i];
        }
        if(arr[i]<smallest)
        {
            smallest=arr[i];
        }    
    }
    printf("\nThe smallest number is: %d",smallest);
    printf("\nThe greatest number is: %d",greatest);
    //----------//
    }
    else if(order==2)
    {
        printf("\nOkay, sorting your array in ascending order...\n");
    //----------//
        int temp,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n-1;i++)
        {
        if(arr[i]>arr[i+1])
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        }
    }
    printf("\nSorted array in ascending order is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    //----------//
    }
    else if(order==3)
    {
        printf("\nOkay, sorting your array in descending order...\n");
    //----------//
        int temp,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    }
        printf("\nSorted array in descending order is: ");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
    
    //----------//
    }
    else if(order==4)
    {
        printf("\nOkay, let's insert a number into your array...\n");
    //----------//
    int j,pos;
    printf("\nEnter element to append: ");
    scanf("%d",&j);
    printf("At what position? ");
    scanf("%d",&pos);
    if(pos>n+1)
    {
        printf("\nNumber exceeds array range.\n");
    }
    else
    {
    n++;   //important to increase size of array first//
    for(i=n-1;i>=pos-1;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos-1]=j;
    printf("\nThe new array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    }
    //----------//
    }
    else if(order==5)
    {
        printf("\nOkay, let's delete something from your array...\n");
    //----------// 
    int num,found=0,k,flag=0,occur,posflag,temp;
    printf("\nEnter the number you want to delete: ");
    scanf("%d",&num);
    for(i=0;i<n;i++)
        {
        if(arr[i]==num)
            {
                temp=i;
                printf("Number found at position(s): ");
                break;
            }
        }
    for(i=0;i<n;i++)
        {
        if(arr[i]==num)
            {
                printf("%d ",i+1);
                flag++;
                found++;
            }
        }
    if(flag>1)
    {
        printf("\nNumber encounterd more than once in your array.\n");
        do
        {
            if(flag>1)
            {
                printf("\nFrom which position do you wish to delete the element?");
                printf("\nEnter your choice: ");
                scanf("%d",&occur);
            }
            
                if(arr[occur-1]==num)
                {
                    posflag=1;
                    for(;occur<=n;occur++)
                        {
                            arr[occur-1]=arr[occur];
                        }
                    n--; 
                    found++;
                    printf("\nNew array is: ");
                    for(i=0;i<n;i++)
                    {
                        printf("%d ",arr[i]);
                    }
                    printf("\n");
                    break;
                }
                else
                {
                        printf("\nNumber does not exist at the specified position. Try again!");
                        posflag=0;
                }
                
        } while (posflag==0);       
    }
    else if(found!=0)
    {
        for(;temp<n;temp++)
        {
            arr[temp]=arr[temp+1];
        }
            n--; 
        printf("\nNew array is: ");
        for(i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    else if(found==0) 
    {
        printf("Number not found.\n");
    }
    else
    {
        printf("\nError, incorrect parameter entered.\n");
    }
    
    //----------//
    }
    else if(order==6)
    {
        printf("\nPROGRAN HAS BEEN TERMINATED\n\nBYE!!\n");
    }
    else
    {
        printf("\nINCORRECT NUMBER, TRY AGAIN!\n");
    }
    } while (order!=6);
    return 0;   
}
