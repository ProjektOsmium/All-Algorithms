#include<iostream>
using namespace std; 
void sop(int i, int j, int n, int *s) // function to print optimal parenthesisation 
{ 
    if (i == j) 
    { 
        cout <<"A"<<i; 
        return; 
    } 
    cout << "("; 

    //recursive calls
    sop(i, *((s+i*n)+j), n, s); 
    sop(*((s+i*n)+j) + 1, j, n, s); 
    cout << ")"; 
}
void mcm(int p[], int n) 
{ 

    int m[n][n]; // stores number of multiplications
    int s[n][n]; // stores values of k at which closing brace is placed
    for (int i=1; i<n; i++) //set diagonals to zero as they correspond to multiplication of a single matrix
        m[i][i] = 0; 
   
    for (int L=2; L<n; L++) // L corresponds to chain length
    { 
        for (int i=1; i<n-L+1; i++) //i corresponds to start index and j to end index; k corresponds to matrix after which closing brace is placed
        { 
            int j = i+L-1; 
            m[i][j] = INT_MAX; 
            for (int k=i; k<=j-1; k++) 
            { 
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (q < m[i][j]) 
                { 
                    m[i][j] = q; 
                    s[i][j] = k; 
                } 
            } 
        } 
    } 

    cout<<"\nThe matrices m and s are: "<<endl; //print matrices m and s
     for(int x=1;x<n;x++)
    {
        for(int y=1;y<n;y++)
        {   
            if(x==y || m[x][y]!=0) 
                cout<<m[x][y]<<"\t";
            else
                cout<<"-"<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
     for(int x=1;x<n;x++)
    {
        for(int y=1;y<n;y++)
        {    
            if(s[x][y]!=0)
                cout<<s[x][y]<<"\t";
            else
                cout<<"-"<<"\t";
        }
        cout<<endl;
    }
    cout <<"\nMinimum number of multiplications required = " << m[1][n-1]<<" for multiplication in the order: ";
    sop(1, n-1, n, (int *)s); 
    cout<<endl;
} 
  
int main() 
{ 
    int arr[] = {30,35,15,5,10,20,25}; // set matrix orders here
    int n = sizeof(arr)/sizeof(arr[0]); 
    mcm(arr, n); 
    return 0; 
} 