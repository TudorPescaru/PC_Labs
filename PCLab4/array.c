#include <stdio.h>

void read_array(int n, int v[]){
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&v[i]);
    }
}

void print_array(int n, int v[]){
    int i;
    for(i=1;i<=n;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

int sum_array(int n, int v[]){
    int i,s=0;
    for(i=1;i<=n;i++){
        s+=v[i];
    }
    return s;
}

int min_array(int n, int v[]){
    int i,mini=v[1];
    for(i=2;i<=n;i++){
        if(v[i]<mini){
            mini=v[i];
        }
    }
    return mini;
}

int pozmax_array(int n, int v[]){
    int i,maxi=v[1],poz=1;
    for(i=2;i<=n;i++){
        if(v[i]>maxi){
            maxi=v[i];
            poz=i;
        }
    }
    return poz;
}

double avg_array(int n, int v[]){
    return sum_array(n,v)/n;
}

void copy_array(int n, int v[], int a[]){
    int i;
    for(i=1;i<=n;i++){
        a[i]=v[i];
    }
}

void sort_array(int n,int v[]){
    int i,j,aux;
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++){
          if(v[i]>v[j]){
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
          }
        }
    }
}

int findi_array(int n, int x[],int k){
    int i,p;
    for(i=1;i<=n;i++){
        if(x[i]==k){
          p=i;
        }
    }
    return p;
}

int findb_array(int n, int v[], int k){
    int mij,st=1,dr=n,ok=0;
    while(st<=dr && !ok){
        mij=(st+dr)/2;
        if(k==v[mij]){
          return mij;
          ok=1;
        }
        else{
            if(k>v[mij]){
              st=mij+1;
            }
            else{
              dr=mij-1;
            }
        }
    }
    if(!ok){
      return -1;
    }
}

void read_matrix(int m, int n, int a[][100]){
    int i,j;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
          scanf("%d",&a[i][j]);
        }
    }
}

void print_matrix(int m, int n, int a[][100]){
    int i,j;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void multi_matrix(int m, int n, int p, int a[][100], int b[][100], int c[][100]){
    int i,j,k,l,x;
    for(i=1;i<=m;i++){
        for(j=1;j<=p;j++){
            c[i][j]=0;
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=p;j++){
            k=1;
            l=1;
            while(k<=n){
                x=a[i][l]*b[l][j];
                c[i][j]+=x;
                l++;
                k++;
            }
        }
    }
}

int main(){
    int v[100],k,x[100],m,n,p,a[100][100],b[100][100],c[100][100];
    printf("Input array size: ");
    scanf("%d",&n);
    printf("Input array:\n");
    read_array(n,v);
    printf("Your array is: ");
    print_array(n,v);
    printf("Sum of array is: %d\n",sum_array(n,v));
    printf("Minimum of array is: %d\n",min_array(n,v));
    printf("The position of the array's maximum is: %d\n",pozmax_array(n,v));
    printf("The average of the array is: %f\n",avg_array(n,v));
    copy_array(n,v,x);
    sort_array(n,v);
    printf("Sorted array is: ");
    print_array(n,v);
    printf("Input searched element: ");
    scanf("%d",&k);
    printf("Iterative(unsorted) position is: %d\n",findi_array(n,x,k));
    if(findb_array(n,v,k)!=-1){
      printf("Binary search position is: %d\n",findb_array(n,v,k));
    }
    else{
      printf("NOT FOUND\n");
    }
    printf("Input matrix sizes: ");
    scanf("%d %d %d",&m,&n,&p);
    printf("Input matrix a:\n");
    read_matrix(m,n,a);
    printf("Input matrix b:\n");
    read_matrix(n,p,b);
    multi_matrix(m,n,p,a,b,c);
    printf("The product of the matrixes, stored in matrix c is:\n");
    print_matrix(m,p,c);
    return 0;
}
