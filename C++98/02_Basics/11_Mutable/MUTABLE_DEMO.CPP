#include <iostream> 

class TestClass 
{
	public: 
		TestClass () : i_num (0), c_ans ('\0'), f_num (0.0), mt_int(0) {} 
		TestClass (int i_num, char c_ans, float f_num) : mt_int (0) 
		{
			this->i_num = i_num; 
			this->c_ans = c_ans; 
			this->f_num = f_num; 
		}

		int get_int () const; 
		char get_char () const; 
		float get_float () const; 
		void set_int (int new_int); 
		void set_char (char new_char); 
		void set_float (float new_float); 
		void display () const; 
	
	private:
		int i_num; 
		char c_ans; 
		float f_num; 
		mutable int mt_int; 
}; 

int TestClass::get_int (void) const 
{
	++mt_int; 
	return (this->i_num); 
}

char TestClass::get_char (void) const 
{
	++mt_int; 
	return (this->c_ans); 
}

float TestClass::get_float (void) const 
{
	++mt_int; 
	return (this->f_num); 
}

void TestClass::set_int (int new_int) 
{
	++mt_int; 
	this->i_num = new_int; 
}

void TestClass::set_char (char new_char) 
{
	++mt_int; 
	this->c_ans = new_char; 
}

void TestClass::set_float (float new_float) 
{
	++mt_int; 
	this->f_num = new_float; 
}

void TestClass::display (void) const 
{
	std::cout << "i_num:" << i_num << std::endl 
		  << "c_ans:" << c_ans << std::endl 
		  << "f_num:" << f_num << std::endl
		  << "mt_num:" << mt_int << std::endl; 
}

int main (void) 
{
	TestClass *ptr1 = new TestClass (10, 'A', 3.14f); 
	const TestClass *ptr2 = new TestClass (20, 'B', 6.28f); 

	std::cout << "ptr1:i_num:" << ptr1->get_int () << std::endl; 
	std::cout << "ptr2:c_ans:" << ptr2->get_char () << std::endl; 

	ptr1->display (); 
	ptr2->display (); 

	return (0); 
}
