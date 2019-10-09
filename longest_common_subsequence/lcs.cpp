#include<iostream>
#include<cstring>
using namespace std;

void lcs(string a, string b, int m, int n) //function to find longest common subsequence of strings a and b
{	
	int i, j;
 	int LCS[m+1][n+1];  //used to find length of longest common subsequence
    char seq[m+1][n+1]; //stores directions to follow while traversing LCS array to find longest common subsequence 
 
 	for(i=0;i<=m;i++)
        LCS[i][0]=0;    
 
    for(j=0;j<=n;j++)
        LCS[0][j]=0;   
 

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
          
            if(a[i-1]==b[j-1])
            {
                LCS[i][j]=1+LCS[i-1][j-1];
                seq[i][j]='d'; //d = diagonal
            }
            else if(LCS[i-1][j]>LCS[i][j-1])
            {
            	LCS[i][j]=LCS[i-1][j];
            	seq[i][j]='u'; //u = up
            }
            else
            {
            	LCS[i][j]=LCS[i][j-1];
            	seq[i][j]='l'; // l = left
            }
               
        }
    }

    cout<<"\nResulting matrices are: "<<endl;
    for(i=0;i<=m;i++)
    {
    	for(int j=0;j<=n;j++)
    		cout<<LCS[i][j]<<"\t";
    	cout<<endl;
    }
    cout<<endl<<endl;
    
    for(i=0;i<=m;i++)
    {
    	for(int j=0;j<=n;j++)
    	{
    		if(seq[i][j]!='\0')
    			cout<<seq[i][j]<<"\t";
    		else
    			cout<<"-\t";
    	}
    	cout<<endl;
    }

	int length = LCS[m][n];
    cout<<"\nLength of longest common subsequence is: "<<length<<endl;
    
    //code to print longest common subsequence
    i = m;
    j = n;
    
    int x = length;;
    char sequence[x+1];
    sequence[x]='\0';
    while(i>0 && j>0)
    {
    	if(seq[i][j]=='d')
    	{	
    		sequence[x-1]=a[i-1];
    		x--;
    		i--;
    		j--;
    	}
    	else if(seq[i][j]=='u')
    		i--;
    	else
    		j--;

	}
	cout<<"The sequence is: "<<sequence<<endl;
 
}
 
 
int main()
{
    string str1,str2;
 
    cout<<"\nEnter first string: ";
    getline(cin, str1);
 
    cout<<"Enter second string: ";
    getline(cin, str2);
 
   	int len1=str1.length();  
    int len2=str2.length();  
   	lcs(str1,str2,len1,len2);
  	cout<<endl;
    return 0;
}