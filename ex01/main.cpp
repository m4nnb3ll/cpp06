#include <cstdint>
#include <iostream>

struct Data
{
	Data(int ia, int ib) : m_a(ia), m_b(ib) {};
	int m_a;
	int m_b;
};

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	Data test(42, 69);
	(void)test;
	// get the uintptr_t;
	uintptr_t tst_ptr = Serializer::serialize(&test);
	std::cout << "the raw is: " << tst_ptr << std::endl;
	Data *data_ptr = Serializer::deserialize(tst_ptr);
	(void)data_ptr;
	std::cout << test.m_a << " " << test.m_b << std::endl;
	std::cout << "Hello world\n" << std::endl;

	std::cout << "the deserialized data ptr goes below: \n";
	std::cout << data_ptr->m_a << " " << data_ptr->m_b << std::endl;
}