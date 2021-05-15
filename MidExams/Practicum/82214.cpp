// 
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Обектно-ориентирано програмиране 2020/21
// Контролно по ООП-практикум
// 
// Име: Петър Станомиров Колев
// ФН: 82214
// Специалност: КН
// Курс: 1
// Административна група: 4
// Ден, в който се явявате на контролното: 15.05.2021 г. 
// Начален час на контролното: 09:00 ч.
// Кой компилатор използвате: GCC
//

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>

enum class MessageType
{
	UNKNOWN = -1,
	INFO,
	WARNING,
	ERROR,
	CRITICAL
};

class Message
{
private:
	MessageType type;
	std::string description;

	std::string enumToString(MessageType type)
	{
		switch (type)
		{
			case MessageType::INFO:
				return "INFO";

			case MessageType::WARNING:
				return "WARNING";

			case MessageType::ERROR:
				return "ERROR";

			case MessageType::CRITICAL:
				return "CRITICAL";	

			default:
				return "UNKNOWN";
		}

		return "UNKNOWN";
	}

public:
	Message(MessageType type, std::string description)
	{
		this->type = type;
		this->description = description;

		if (this->type == MessageType::UNKNOWN)
		{
			throw std::invalid_argument("Invalid type of message");
		}
	}

	MessageType getType() const
	{
		return this->type;
	}

	std::string getDescription() const
	{
		return this->description;
	}

	friend std::ostream& operator << (std::ostream& out, Message& message)
	{
		out << message.enumToString(message.type) << ": " << message.description << std::endl;

		return out;
	} 
};

class Logger
{
private:
	static std::size_t infoCounter;
	static std::size_t warningCounter;
	static std::size_t errorCounter;
	static std::size_t criticalCounter;

	std::string fileName;

	void readData(std::string fileName)
	{
		std::ifstream file(fileName.c_str());

		if (!file.is_open())
		{
			throw std::invalid_argument("Non-existing file!");
		}

		while (!file.eof())
		{
			std::string currentLine;
			int indexOfDvuetochie = -1;

			std::getline(file, currentLine);
			if (currentLine.empty())
			{
				break;
			}

			std::size_t length = currentLine.length();
			for (std::size_t i = 0; i < length; ++i)
			{
				if (currentLine[i] == ':')
				{
					indexOfDvuetochie = i;
					break;
				}
			}
			if (indexOfDvuetochie == -1)
			{
				break;
			}

			std::string typeOfMessage;
			for (int i = 0; i < indexOfDvuetochie; ++i)
			{
				typeOfMessage.push_back(currentLine[i]);
			}

			if (typeOfMessage == "INFO")
			{
				++Logger::infoCounter;
			}
			else if (typeOfMessage == "WARNING")
			{
				++Logger::warningCounter;
			}
			else if (typeOfMessage == "ERROR")
			{
				++Logger::errorCounter;
			}
			else if (typeOfMessage == "CRITICAL")
			{
				++Logger::criticalCounter;
			}
		}
	}

public:
	Logger()
	{
		this->fileName = "config.txt";
	}
	Logger(std::string fileName)
	{
		this->fileName = fileName;
		try
		{
			this->readData(fileName);
		}
		catch(const std::invalid_argument& ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}

	friend Logger& operator << (Logger& logger, Message& message)
	{
		if (message.getType() == MessageType::INFO)
		{
			++Logger::infoCounter;
		}
		else if (message.getType() == MessageType::WARNING)
		{
			++Logger::warningCounter;
		}
		else if (message.getType() == MessageType::ERROR)
		{
			++Logger::errorCounter;
		}
		else if (message.getType() == MessageType::CRITICAL)
		{
			++Logger::criticalCounter;
		}

		std::ofstream file(logger.fileName.c_str(), std::ios::app);

		if (!file.is_open())
		{
			throw std::invalid_argument("Problem while opening the file");
		}

		file << message;

		file.close();

		return logger;
	}

	static std::size_t getNumberOfInfos()
	{
		return Logger::infoCounter;
	}

	static std::size_t getNumberOfWarnings()
	{
		return Logger::warningCounter;
	}

	static std::size_t getNumberOfErrors()
	{
		return Logger::errorCounter;
	}

	static std::size_t getNumberOfCriticals()
	{
		return Logger::criticalCounter;
	}
};

std::size_t Logger::infoCounter = 0;
std::size_t Logger::warningCounter = 0;
std::size_t Logger::errorCounter = 0;
std::size_t Logger::criticalCounter = 0;

class Configuration
{
private:
	std::string fileName;
	Logger logger;

	Configuration()
	{
		this->fileName = "config.txt";
		this->loadLogger("config.txt");
	}

	void printMenu()
	{
		std::cout << "What kind of message do you mant to write?" << std::endl;
		std::cout << "1. Info" << std::endl;
		std::cout << "2. Warning" << std::endl;
		std::cout << "3. Error" << std::endl;
		std::cout << "4. Critical" << std::endl;
		std::cout << "0. Exit" << std::endl;
	}

public:

	Configuration(const Configuration& other) = delete;
	Configuration& operator = (const Configuration& other) = delete;

	void loadLogger(const char* fileName)
	{
		std::ifstream file(this->fileName);

		if (!file.is_open())
		{
			throw std::invalid_argument("Problem while opening the configuration file");
		}

		std::string loggerFileName;
		std::getline(file, loggerFileName);

		this->logger = Logger(loggerFileName);

		file.close();
	}

	static Configuration& getInstance()
	{
		static Configuration obj;
		return obj;
	}

	void start()
	{
		int choice;
		do
		{
			this->printMenu();
			std::cout << "Enter your option: ";
			do 
			{
				std::cin >> choice;
				std::cin.ignore();
				if (choice < 0 || choice > 4)
				{
					std::cout << "Invalid choice! Try again: ";
				}
			} while(choice < 0 || choice > 4);
			
			if (choice == 0)
			{
				return;
			}

			std::string description;
			std::cout << "Enter description: ";
			std::getline(std::cin, description);

			MessageType type;
			switch (choice)
			{
			case 1:
				type = MessageType::INFO;
				break;
			case 2:
				type = MessageType::WARNING;
				break;
			case 3:
				type = MessageType::ERROR;
				break;
			case 4:
				type = MessageType::CRITICAL;
				break;
			default:
				type = MessageType::UNKNOWN;
				break;
			}

			try
			{
				Message m(type, description);
				this->logger << m;
			}
			catch(const std::invalid_argument& ia)
			{
				std::cout << ia.what() << std::endl;
			}

		} while (choice);
		
	}
};

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		try
		{
			Configuration::getInstance().loadLogger(argv[1]);
		}
		catch(const std::invalid_argument& ia)
		{
			std::cout << ia.what() << std::endl;
			return 1;
		}
	}

	Configuration::getInstance().start();
	/*std::cout << Logger::getNumberOfInfos() << std::endl;
	std::cout << Logger::getNumberOfWarnings() << std::endl;
	std::cout << Logger::getNumberOfErrors() << std::endl;
	std::cout << Logger::getNumberOfCriticals() << std::endl;*/

	return 0;
}