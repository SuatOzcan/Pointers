#include <cstdio>


struct College
{
	char name[256];

};

/*void print_name(College* college_ptr) {
	printf("%s College\n", college_ptr->name);
}*/

void print_names(College* colleges, size_t n_colleges)
{
	for (size_t i = 0; i < n_colleges; i++) {
		printf("%s College\n", colleges[i].name);
	}
}

//Forward Linked List
struct Element
{
	Element* next{};
	void insert_after(Element* new_element) {
		new_element->next = next;
		next = new_element;
	}
	char prefix[2];
	short operating_number;
};

/*void petruchio(const char* shrew) {
	printf("Fear not, sweet wench, they shall not touch thee, %s.", shrew);
	shrew[0] = "K";  // Compiler error! The shrew cannot be tamed.
}*/

struct ClockOfTheLongNow
{
	ClockOfTheLongNow() {
		year = 2019;
	}
	ClockOfTheLongNow(int year_in) {
		if (!set_year(year_in))
		{
			year = 2020;
		}
	}
	void add_year() {
		year++;
	}

	bool set_year(int new_year) {
		if (new_year < 2020)
		{
			return false;
		}
		year = new_year;
		return true;
	}

	int get_year() const {
		return year;
	}


	bool is_leap_year(const ClockOfTheLongNow& clock) {
		if (clock.get_year() % 4 > 0) return false;                //this compiles becaus get year is marked as constant.
		if (clock.get_year() % 100 > 0) return true;
		if (clock.get_year() % 400 > 0) return false;
		return true;
	}

private:
	int year;
};


struct Avout {
	Avout(const char* name, long year_of_apert) : name{ name }, apert{ year_of_apert }{}
		void announce() const {
			printf("My name is %s and my apert is %d.\n", name,apert.get_year());
		};
		ClockOfTheLongNow apert;
		const char* name;
};


int main() {
	int gettysburg{};
	printf("gettysburg: %d\n", gettysburg);
	int* gettysburg_address = &gettysburg;
	printf("&gettysburg: %p\n", gettysburg_address);
	*gettysburg_address = 17777;
	printf("gettysburg's value is: %d\n", gettysburg);
	printf("&gettysburg: %p\n", gettysburg_address);

	struct ClockOfTheLongNow
	{
		ClockOfTheLongNow() {
			year = 2019;
		}
		ClockOfTheLongNow(int year_in) {
			if (!set_year(year_in))
			{
				year = 2020;
			}
		}
		void add_year() {
			year++;
		}

		bool set_year(int new_year) {
			if (new_year < 2020)
			{
				return false;
			}
			year = new_year;
			return true;
		}

		int get_year() const{
			return year;
		}


		bool is_leap_year(const ClockOfTheLongNow& clock) {   
			if (clock.get_year() % 4 > 0) return false;                //this compiles becaus get year is marked as constant.
			if (clock.get_year() % 100 > 0) return true;
			if (clock.get_year() % 400 > 0) return false;
			return true;
		}

	private:
		int year;
	};

	ClockOfTheLongNow clock;
	ClockOfTheLongNow* clock_ptr = &clock;
	clock_ptr->set_year(2020);
	printf("Address of clock: %p\n", clock_ptr);
    printf("Value of clock's year: %d\n", clock_ptr->get_year());
	printf("Value of clock's year: %d\n", (*clock_ptr).get_year());
	int key_to_the_universe[]{ 3, 6, 9 };
	int* key_ptr = key_to_the_universe;
	printf("The pointer of arrays first element: %p\n", key_ptr);

	//College best_collages[] = { "Magdalen", "Nuffield", "Kellogg" };
	College oxford[] = { "Magdalen", "Nuffield", "Kellogg" ,"asd"};
	//print_name(best_collages);
	print_names(oxford,sizeof(oxford)/sizeof(College));
	College* first_college_ptr = &oxford[0];
	College* second_college_ptr = &oxford[1];
	College* third_college_ptr = &oxford[2];
	College* fourth_college_ptr = &oxford[3];
	printf("%p\n", first_college_ptr);
	printf("%p\n", second_college_ptr);
	printf("%p\n", third_college_ptr);
	printf("%p\n", fourth_college_ptr);

/*	char lower[] = "abc?e";
	char upper[] = "ABC?E";
	char* upper_ptr = upper;  // Equivalent: &upper[0]
    lower[3] = 'd';  // lower now contains a b c d e \0
    upper_ptr[3] = 'D'; // upper now contains A B C D E \0
	char letter_d = lower[3];  // letter_d equals 'd'
    char letter_D = upper_ptr[3]; // letter_D equals 'D' */

	char lower[] = "abc?e";
	char upper[] = "ABC?E";
	char* upper_ptr = &upper[0];
	*(lower + 3) = 'd';
	*(upper_ptr+3) = 'D';
	printf("lower: %s\nupper: %s\n", lower, upper);

	//ForwardLink List
	Element trooper1, trooper2, trooper3; 
	trooper1.prefix[0] = 'T';
	trooper1.prefix[1] = 'K';
	trooper1.operating_number = 421;
	trooper1.insert_after(&trooper2); 
	trooper2.prefix[0] = 'F';
	trooper2.prefix[1] = 'N';
	trooper2.operating_number = 2187;
	trooper2.insert_after(&trooper3); 
	trooper3.prefix[0] = 'L';
	trooper3.prefix[1] = 'S';
	trooper3.operating_number = 005; 
	for (Element* cursor = &trooper1; cursor; cursor = cursor->next) {
		printf("stormtrooper %c%c-%d\n",
			cursor->prefix[0],
			cursor->prefix[1],
			cursor->operating_number);
	}

	//constants
	struct clockoftheverylongnow
	{
		int get_year() const {
			return year;
		}
	private:
		int year;
	};
	Avout Raz{ "Erasmus", 3030 };
	Raz.announce();
}
