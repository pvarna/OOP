// 
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Обектно-ориентирано програмиране 2020/21
// Контролно 1
// 
// Име: Петър Станомиров Колев
// ФН: 82214
// Специалност: Компютърни науки, 1 поток
// Курс: 1
// Административна група: 4
// Ден, в който се явявате на контролното: 17.04.2021 г.
// Начален час на контролното: 10:30 ч.
// Кой компилатор използвате: GCC
//

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstddef>
#include <cstdint>

const int NUMBER_OF_MONTHS = 12;

bool isYearLeap(unsigned int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool isDateValid(unsigned int day, unsigned int month, unsigned int year)
{
	int daysPerMonth[NUMBER_OF_MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isYearLeap(year))
	{
		daysPerMonth[1] = 29;
	}

	if (month < 1 || month > 12)
	{
		return false;
	}
	if (day > daysPerMonth[month - 1] || day == 0)
	{
		return false;
	}

	return true;
}

class Date
{
private:
	std::uint8_t day;
	std::uint8_t month;
	std::uint16_t year;

public:
	Date(unsigned int day, unsigned int month, unsigned int year)
	{
		if (!isDateValid(day, month, year))
		{
			throw std::invalid_argument("Wrong date!");
		}
		this->day = day;
		this->month = month;
		this->year = year;
	}

	unsigned int getDay() const
	{
		return this->day;
	}

	unsigned int getMonth() const
	{
		return this->month;
	}

	unsigned int getYear() const
	{
		return this->year;
	}

	bool operator==(const Date& rhs) const
	{
		return ((this->day == rhs.day) && (this->month == rhs.month) && (this->year == rhs.year));
	}

	bool operator<(const Date& rhs) const
	{
		return ((this->year < rhs.year) || (this->month < rhs.month) || (this->day < rhs.day));
	}

	friend std::ostream& operator << (std::ostream& out, const Date& date)
	{
		out << (unsigned int)date.day << "." << (unsigned int)date.month << "." << (unsigned int)date.year;

		return out; 
	}
};

class Registration
{
private:
	std::string id;
	Date date;

public:
	Registration(const std::string& id, const Date& date) : id(id), date(date) {}

	bool operator==(const Registration& rhs) const
	{
		return this->id == rhs.id;
	}

	bool operator<(const Registration& rhs) const
	{
		return ((this->date < rhs.date) || (this->date == rhs.date && this->id < rhs.id));
	}

	friend std::ostream& operator << (std::ostream& out, const Registration& registration)
	{
		out << registration.id << ", " << registration.date;

		return out;
	}
};

class RegistrationList
{
private:
	Registration** registrations;
	std::size_t capacity;
	std::size_t size;

	void copy(const RegistrationList& other)
	{
		Registration** buffer = nullptr;
		try
		{
			buffer = new Registration*[other.capacity];
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return;
		}

		for (std::size_t i = 0; i < other.capacity; ++i)
		{
			if (i < other.size)
			{
				try
				{
					buffer[i] = new Registration(*(other.registrations[i]));
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					for (std::size_t j = 0; j < i; ++j)
					{
						delete buffer[j];
					}
					delete[] buffer;

					return;
				}
			}
			else
			{
				buffer[i] = nullptr;
			}
		}

		this->registrations = buffer;
		this->capacity = other.capacity;
		this->size = other.size;	
	}

	void deallocate()
	{
		for (std::size_t i = 0; i < this->size; ++i)
		{
			delete this->registrations[i];
		}
		delete[] this->registrations;
	}

public:
	RegistrationList(std::size_t capacity) : capacity(capacity), size(0)
	{
		this->registrations = new Registration*[capacity];
		for (std::size_t i = 0; i < capacity; ++i)
		{
			this->registrations[i] = nullptr;
		}
	}

	RegistrationList (const RegistrationList& other)
	{
		this->copy(other);
	}
	
	RegistrationList& operator = (const RegistrationList& other)
	{
		if (this != &other)
		{
			this->deallocate();
			this->copy(other);
		}

		return *this;
	}

	~RegistrationList()
	{
		this->deallocate();
	}

	void insert(const std::string& id, const Date& date)
	{
		if (this->size == this->capacity)
		{
			throw std::exception();
		}

		if (this->size == 0)
		{
			this->registrations[this->size++] = new Registration(id, date);
			return;
		}

		Registration tempRegistration(id, date);

		bool doesOccurre = false;
		for (std::size_t i = 0; i < this->size; ++i)
		{
			if (tempRegistration == *(this->registrations[i]))
			{
				doesOccurre = true;
				break;
			}
		}

		if (doesOccurre)
		{
			throw std::invalid_argument("This registration is already added to the list!");
		}

		std::size_t searchedIndex = this->size;
		for (std::size_t i = 0; i < this->size; ++i)
		{
			if (tempRegistration < *(this->registrations[i]))
			{
				searchedIndex = i;
			}
		}

		Registration** buffer = new Registration*[this->capacity];

		for (std::size_t i = 0; i < this->capacity; ++i)
		{
			try
			{
				if (i < searchedIndex)
				{
					buffer[i] = new Registration(*(this->registrations[i]));
				}
				else if (i == searchedIndex)
				{
					buffer[i] = new Registration(tempRegistration);
				}
				else if (i > searchedIndex && i <= this->size)
				{
					buffer[i] = new Registration(*(this->registrations[i - 1]));
				}
				else
				{
					buffer[i] = nullptr;
				}
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				for (std::size_t j = 0; j < i; ++j)
				{
					delete buffer[j];
				}
				delete[] buffer;

				return;
			}
		}

		this->deallocate();
		this->registrations = buffer;
		++this->size;		
	}

	const Registration& at(std::size_t index) const
	{
		if (index >= this->size)
		{
			throw std::out_of_range("Invalid index!");
		}

		return *(this->registrations[index]);
	}

	const Registration& operator[](std::size_t index) const
	{
		assert (index < this->size);

		return *(this->registrations[index]);
	}

	bool empty() const
	{
		return this->size == 0;
	}

	std::size_t getCapacity() const
	{
		return this->capacity;
	}

	std::size_t getSize() const
	{
		return this->size;
	}
};

int main()
{
	std::size_t n;

	std::cout << "Emter number of registrations: ";
	std::cin >> n;

	RegistrationList myRegistrationList(n);

	for (std::size_t i = 0; i < n; ++i)
	{
		bool exceptionIsThrown = false;

		Date date(1, 1, 1);

		do
		{
			exceptionIsThrown = false;

			unsigned int tempDay, tempMonth, tempYear;
			std::cout << "Enter day: ";
			std::cin >> tempDay;
			std::cout << "Enter month: ";
			std::cin >> tempMonth;
			std::cout << "Enter year: ";
			std::cin >> tempYear;

			try
			{
				Date tempDate(tempDay, tempMonth, tempYear);
				date = tempDate;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				std::cout << "Please enter new date!" << std::endl;
				exceptionIsThrown = true;
			}
			
		} while (exceptionIsThrown);
		
		std::string id;

		std::cout << "Enter id: ";
		std::cin >> id;

		exceptionIsThrown = false;		

		do
		{
			if (exceptionIsThrown)
			{
				std::cout << "Enter id: ";
				std::cin >> id;
			}

			exceptionIsThrown = false;

			try
			{
				myRegistrationList.insert(id, date);
			}
			catch(const std::invalid_argument& e)
			{
				std::cerr << e.what() << '\n';
				exceptionIsThrown = true;
				std::cout << "Please enter new id!" << std::endl;
			}
		
		} while (exceptionIsThrown);
	}

	for (size_t i = 0; i < myRegistrationList.getSize(); ++i)
	{
		std::cout << myRegistrationList[i] << std::endl;
	}

	return 0;
}