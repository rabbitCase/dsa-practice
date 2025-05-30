#include <iostream>
 struct sparse{
    int row;
    int col;
    int value;
};
void read(struct sparse a[]){
    int i=0;
    std::cout<<"Enter <row,col,val> metadata: ";
    std::cin>>a[0].row>>a[0].col>>a[0].value;
    std::cout<<"Start entering <row,col,val>:\n";
    for(i=1;i<=a[0].value;i++){
        std::cin>>a[i].row>>a[i].col>>a[i].value;
    }
}

void fastTranspose(struct sparse a[],struct sparse b[]){
   
    int i,j,freq[10],pos[10]={0},n=a[0].col;
    for(i=1;i<=a[0].value;i++){
            freq[a[i].col]++;//contains the no of non zero elements in                  
                            //each coloumn
    }
    //transpose metadata
    b[0].row=a[0].col; b[0].col=a[0].row;
    b[0].value=a[0].value;
    pos[0]=1;
    for(i=1;i<n;i++){
        pos[i]=(pos[i-1]+freq[i-1]);//pos to insert transposed element
    }
    for(i=1;i<=n;i++){
        j=pos[a[i].col];
        j++;
        b[j].row=a[i].col; b[j].col=a[i].row;
        b[j].value=a[i].value;
    }
    for(int i=0;i<a[0].row;i++){
        std::cout<<"<"<<a[i].row<<","<<a[i].col<<","<<a[i].value<<">";
        std::cout<<"\n";
    }
}
void display(struct sparse a[]){
    std::cout<<"Sparse Matrix is:\n";
    for(int i=0;i<a[0].row;i++){
        std::cout<<"<"<<a[i].row<<","<<a[i].col<<","<<a[i].value<<">";
        std::cout<<"\n";
    }
}
int main(){
    struct sparse a[10]; struct sparse b[10];
    read(a);
    fastTranspose(a,b);
    display(b);
}