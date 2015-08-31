// Reference: http://tech-wonderland.net/blog/summary-of-ksum-problems.html

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <sstream>
#include <set>

using namespace std;


bool Sum2(set<int> &inputs, int target)
{
	set<int>::iterator itBeg;
	set<int>::iterator itEnd;

	itBeg = inputs.begin();
	itEnd = inputs.end();
	itEnd--;

	int sum;
	bool result = false;
	while(itBeg != itEnd) 
	{
		sum = *itBeg + *itEnd;
		if (sum == target)
		{
			result = true;
			break;
		}
		else if (sum < target)
		{
			itBeg++;
		}else{
			itEnd--;
		}
	}


	return result;
}


int main()
{
	ifstream infile;
	infile.open("algo1-programming_prob-2sum.txt");

	set<int> inputSet;
	int input;
	while(!infile.eof())
	{
		infile >> input;
		inputSet.insert(input);
	}

	int sum =0;
	for (int i=-10000; i<10001; i++)
	{
		if (Sum2(inputSet, i))
		{
			sum++;
		}
        cout << " completed for t " <<  i << endl;
	}
	
	cout << "The number is " << sum << endl;
	infile.close();
	return 0;
}
