#include <iostream>
#include <vector>

//Luca Burlacu
std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
  int i = 0; 
  int j = 0;
  std::vector<int> merged;
  while(i < left.size() && j < right.size())
  {
    if(left[i] <= right[j])
    {
      merged.push_back(left[i]);
      i++;
    }
    else 
    {
      merged.push_back(right[j]);
      j++;
    }
  }
  if(i == left.size())
  {
    while(j != right.size())
    {
      merged.push_back(right[j]);
      j++;
    }
  }
  if(j == right.size())
  {
    while(i != left.size())
    {
      merged.push_back(left[i]);
      i++;
    }
  }

  return merged;
}

//Alexandros Aidonis

std::vector<int> msort(std::vector<int> unsorted){
  if(unsorted.size() <= 1){
    return unsorted;
  }

  std::vector<int> sorted;
  std::vector<int> left;
  std::vector<int> right;
  int middle = unsorted.size()/2;

  for(int i = 0; i < middle; i++){
    left.push_back(unsorted[i]);
  }

  for(int j = middle; j < unsorted.size(); j++){
    right.push_back(unsorted[j]);
  }

  sorted = merge(msort(left), msort(right));
  return sorted;
}

int main()
{
	std::vector<int> unsorted = {13,8,21,4,144,9,17};
	std::vector<int> sorted = msort(unsorted);
	for(int i = 0; i<sorted.size(); i++)
	{
		std::cout << sorted.at(i) << ", ";
	}
	std::cout << "\n";
}


