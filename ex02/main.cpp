#include <iostream>

class Base { public: virtual ~Base(){}; };

class A : public Base {};
class B : public Base {};
class C : public Base {};


Base*	generate() {
	// Generate a random number between 0 and 2
    int random = std::rand() % 3;

    switch (random) {
        case 0:
			std::cout << "Generated A" << std::endl;
            return new A();
        case 1:
			std::cout << "Generated B" << std::endl;
            return new B();
        case 2:
			std::cout << "Generated C" << std::endl;
            return new C();
        default:
            return nullptr; // Should never happen
    }
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The type of the ptr is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The type of the ptr is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The type of the ptr is C" << std::endl;
	else
		std::cerr << "Unrecognized type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "The type of the ref is A" << std::endl;
	}
	catch (std::bad_cast& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "The type of the ref is B" << std::endl;
		}
		catch (std::bad_cast& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "The type of the ref is C" << std::endl;
			}	
			catch (std::bad_cast& e)
			{
				std::cerr << "Unrecognized type" << std::endl;
			}
		}
	}
}



int main()
{
	Base* based = generate();
	std::cout << "And the type info is: " << std::endl;
	identify(based);
	std::cout << "And the type from ref is: " << std::endl;
	identify(*based);
}
