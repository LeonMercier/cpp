#include <iostream>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
		std::cout << tmp[100] << " = " << numbers[100] << std::endl;
        Array<int> test(tmp);
		std::cout << tmp[100] << " = " << test[100] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
	
	std::cout << std::endl;
	std::cout << "### Array of one" << std::endl;
	Array<int> one(1);
	std::cout << one.size() << std::endl;
	one[0] = 42;
	std::cout << one[0] << std::endl;
	std::cout << std::endl;
	
	std::cout << "### Array of two" << std::endl;
	Array<int> two(2);
	std::cout << two.size() << std::endl;
	two[0] = 42;
	two[1] = 43;
	std::cout << two[0] << " ," << two[1] << std::endl;
	std::cout << std::endl;

	std::cout << "### Array of strings" << std::endl;
	Array<std::string> strarr(5);
	strarr[0] = "Hello ";
	strarr[1] = "there";
	strarr[2] = ", this ";
	strarr[3] = "is ";
	strarr[4] = "me.";
	for (size_t i = 0; i < strarr.size(); i++) {
		std::cout << strarr[i];
	}
	std::cout << std::endl;

	
    return 0;
}
