#include <iostream>
#include <utility>
#include <math.h>
using namespace std;
int main ()
{
  int i, weeks, j, totalPeople, groupSize, p, maxGroupStrength, group, noOfGroups;
  cout << "Enter Strength";
  cin >> totalPeople;
  cout << "Enter group Size";
  cin >> groupSize;
  maxGroupStrength = totalPeople / groupSize;
  int FactorCount = 0;
  //Find greatest prime less than total number divided by group size
  for (i = maxGroupStrength; i >= 2; --i)
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
  int peopleCounter = 0;
  char peopleList[groupSize][maxGroupStrength];
  for (i = 0; i < groupSize; i++)
    {
      for (j = 0; j < maxGroupStrength; j++)
	{
	  peopleList[i][j] = 65 + peopleCounter;
	  peopleCounter++;
	}
    }
  cout << endl;
  int temp;
  string weeksArrangement[noOfGroups][noOfGroups];
  //Compute sets of colleagues for each week
  for (weeks = 0; weeks < noOfGroups; weeks++)
    {
      for (group = 0; group < noOfGroups; group++)
	{
	  string groupString;
	  for (j = 0; j < groupSize; j++)
	    {
	      temp = ((weeks * j) + group) % noOfGroups;
	      groupString = groupString + peopleList[j][temp];
	    }
	  weeksArrangement[weeks][group] = weeksArrangement[weeks][group] + groupString;
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
