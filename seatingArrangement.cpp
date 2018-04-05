#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;
int
main ()
{
  int i, weeks, j, totalPeople, groupSize, p, m, group, noOfGroups;
  cout << "Enter Strength";
  cin >> totalPeople;
  cout << "Enter group Size";
  cin >> groupSize;
  m = totalPeople / groupSize;
  int FactorCount = 0;
  for (i = m; i >= 2; --i)
    {
      for (j = 2; j < i; ++j)
	{
	  if (i % j == 0)
	    {
	      ++FactorCount;
	    }
	}
      if (FactorCount == 0)
	{
	  noOfGroups = i;
	  break;
	}
      FactorCount = 0;
    }
  int c = 0;
  char arr[groupSize][m];
  for (i = 0; i < groupSize; i++)
    {
      for (j = 0; j < m; j++)
	{
	  arr[i][j] = 65 + c;
	  c++;
	}
    }
  cout << endl;
  int temp;
  string weeksArrangement[noOfGroups][noOfGroups];
  for (weeks = 0; weeks < noOfGroups; weeks++)
    {
      for (group = 0; group < noOfGroups; group++)
	{
	  string x;
	  for (j = 0; j < groupSize; j++)
	    {
	      temp = ((weeks * j) + group) % noOfGroups;
	      x = x + arr[j][temp];
	    }
	  weeksArrangement[weeks][group] = weeksArrangement[weeks][group] + x;
	}
    }
  for (i = 0; i < noOfGroups; i++)
    {
      cout << endl;
      for (j = 0; j < noOfGroups; j++)
	{
	  cout << weeksArrangement[i][j] << "  ";
	}
    }
  return 0;
}
