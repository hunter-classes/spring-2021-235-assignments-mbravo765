/*
 *
can only move one disc at a time
discs must be either in transit or on a tower (never on the ground)
you can never place a larger disc on a smaller disc


 */

#include <iostream>
#include <string>


void hanoi(int n, char src, char dst, char tmp)
{

//1. Base case -> when you just know the answer without recurring 
//base case is when n = 1 - just print out the move
//otherwise, figure out the recursive call part


if(n == 1)
{

	std::cout << "Moving ring " << n << " from " << src << " to " << dst << std::endl;
}


//2. reduction -> recursive call that will eventually get to the base case

else
{
	hanoi(n-1, src, tmp, dst);
	std::cout << "moving ring " << n << " from " << src << " to " << dst << std::endl;
	hanoi(n-1, tmp, dst, src);
}


}


int main()
{

	hanoi(4, 'a', 'b', 'c');

	return 0;
}
