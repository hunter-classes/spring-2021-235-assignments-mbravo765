#include <iostream>



int stepPerms(int n)
{
	if(n == 1)
	{
		return 1;
	}

	if(n == 2)
	{
		return 2;
	}

	if(n == 3)
	{
		return 4;
	}

	return stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3);

}

int main()
{
/*
there are 13 possible ways he can take these 5 steps
the first staircase only has n = 1 step, so there is only one way
for him to climb it
the second staircase has n = 3 steps and he can climb it in any of the four following ways:
1. 1-> 1 -> 1
2. 1 -> 2
3. 2 -> 1
4. 3
*/

	std::cout << stepPerms(5) << "\n";
	std::cout << stepPerms(3) << "\n";
	std::cout << stepPerms(1) << "\n";

}
