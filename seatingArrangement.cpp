#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    int i,weeks,j,totalPeople,groupSize,p,numberOfGroups,group;
    cout<<"Enter Strength";
    cin>>totalPeople;
    cout<<"Enter group Size";
    cin>>groupSize;
    numberOfGroups=totalPeople/groupSize;
    int FactorCount = 0;
	for (i=numberOfGroups; i>=2; --i)
	{
		for (j=2; j<i; ++j)
		{
			if (i % j == 0)
			{
				++FactorCount;
			}
		}
		if (FactorCount == 0)
		{
			p=i;
			break;
		}
		FactorCount = 0;
	}
	int c=0;
	char arr[groupSize][numberOfGroups];
	for(i=0;i<groupSize;i++)
    {
        for(j=0;j<numberOfGroups;j++)
        {
            arr[i][j]= 65 + c;
            c++;
        }
    }
    cout<<endl;
    int temp;
    string weeksArrangement[p][p];
    for(weeks=0;weeks<p;weeks++)
    {
    for(group=0;group<p;group++)
        {
            string x;
      for(j=0;j<groupSize;j++)
           {
               temp = ((weeks*j) + group)%p;
               char d;
               d = arr[j][temp];
               x = x+d;
            }
            weeksArrangement[weeks][group] = weeksArrangement[weeks][group]+x;
        }
    }
    for(i=0;i<p;i++)
    {
        cout<<endl;
        for(j=0;j<p;j++)
        {
            cout<<weeksArrangement[i][j]<<"  ";
        }
    }
    return 0;
}
