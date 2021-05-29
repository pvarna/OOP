// 
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Обектно-ориентирано програмиране 2020/21
// Контролно 2
// 
// Име: Петър Станомиров Колев
// ФН: 82214
// Специалност: КН
// Курс: 1
// Административна група: 4
// Ден, в който се явявате на контролното: 29.05.2021 г.
// Начален час на контролното: 09:00 ч.
// Кой компилатор използвате: GCC
//

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

const std::size_t MAX_ARGUMENTS = 3;

class Command
{
private:
    std::string line;
    std::string arguments[MAX_ARGUMENTS];
    std::size_t m_size;

public:
    Command(std::string text) : line(std::move(text))
    {
        this->m_size = 0;
        this->parseCommands();
    }

    void parseCommands()
    {
        std::size_t index = 0;
        std::size_t lineSize = line.size();

        while (line[index] == ' ')
        {
            ++index;
        }

        while (index != lineSize)
        {
            while (line[index] != ' ' && index != lineSize)
            {
                this->arguments[this->m_size].push_back(line[index++]);
            }

            ++this->m_size;

            if (index == lineSize)
            {
                break;
            }

            while (line[index] == ' ')
            {
                ++index;
            }
        }
    }

    std::size_t size() const
    {
        return this->m_size;
    }

    std::string& operator [] (std::size_t index)
    {
        if (index >= this->m_size)
        {
            throw std::out_of_range("Invalid index");
        }

        return this->arguments[index];
    }
};

class Editor
{
    std::fstream file;
    std::size_t fileSize;

    std::size_t getFileSize(std::fstream& file)
    {
        std::size_t current = file.tellg();
        file.seekg(0, std::ios::end);
        std::size_t result = file.tellg();
        file.seekg(current, std::ios::beg);

        return result;
    }

public:
    Editor(std::string path)
    {
        this->file.open(path.c_str(), std::ios::binary | std::ios::in | std::ios::out);

        if (!this->file.is_open())
        {
            throw std::invalid_argument("Invalid path");
        }

        this->fileSize = this->getFileSize(this->file);
    }

    Editor (const Editor& other) = delete;
    Editor& operator = (const Editor& other) = delete;
    
    void open(std::string path)
    {
        if (this->file)
        {
            this->file.close();
        }

        this->file.open(path.c_str(), std::ios::binary | std::ios::in | std::ios::out);

        if (!this->file.is_open())
        {
            throw std::invalid_argument("Invalid path");
        }
    }

    void close()
    {
        this->file.close();
    }

    std::size_t size() const
    {
        return this->fileSize;
    }

    void edit(std::size_t offset, std::uint8_t value)
    {
        if (offset > this->fileSize)
        {
            throw std::invalid_argument("ERROR: file size is " + this->fileSize);
        }

        this->file.seekp(offset);

        this->file.write(reinterpret_cast<const char *>(&value), sizeof(std::uint8_t));
    }

    void display(std::ostream& out, std::size_t offset, std::size_t limit)
    {
        if (offset > this->fileSize)
        {
            throw std::invalid_argument("ERROR: file size is " + this->fileSize);
        }

        this->file.seekg(offset);

        std::size_t counter = 0;
        for (std::size_t i = 0; i < limit; ++i)
        {
            if(this->file.eof() || this->file.tellg() == this->fileSize)
            {
                break;
            }

            if (counter % 16 == 0)
            {
                if (counter != 0)
                {
                    out << std::endl;
                }
                std::uint32_t data = this->file.tellg();
                out << std::setfill('0') << std::setw(8) << std::hex << data;
                out << " ";
            }
            std::uint8_t byte;
            this->file.read(reinterpret_cast<char *>(&byte), sizeof(std::uint8_t));
            out << std::setfill('0') << std::setw(2) << std::hex << (unsigned int)byte; 
            out << " ";
            ++counter;
        }

        out << std::endl;
    }

    ~Editor()
    {
        this->close();
    }
};

class Processor
{
private:
    Editor editor;
    bool stopProgram;

    bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    bool isNumber(std::string str)
    {
        std::size_t size = str.size();

        for (std::size_t i = 0; i < size; ++i)
        {
            if (!isDigit(str[i]))
            {
                return false;
            }
        }

        return true;
    }

    bool is_valid(Command cmd)
    {
        std::string mainCommand = cmd[0];
        if (mainCommand != "EXIT" && mainCommand != "SIZE" && mainCommand != "EDIT" && mainCommand != "SHOW")
        {
            return false;
        }
        if ((mainCommand == "EXIT" || mainCommand == "SIZE") && cmd.size() != 1)
        {
            return false;
        }
        if ((mainCommand == "EDIT" || mainCommand == "SHOW") && cmd.size() != 3)
        {
            return false;
        }

        if ((mainCommand == "EDIT" || mainCommand == "SHOW") && (!isNumber(cmd[1]) || !isNumber(cmd[2])))
        {
            return false;
        }

        return true;
    }

public:
    Processor(std::string path) : editor(path)
    {
        this->stopProgram = false;
    }

    bool programHasToStop() const
    {
        return this->stopProgram;
    }

    void execute(Command cmd)
    {
        if (!is_valid(cmd))
        {
            throw std::invalid_argument("Invalid command");
        }

        std::string mainCommand = cmd[0];
        if (mainCommand == "EXIT")
        {
            this->stopProgram = true;
        }
        else if (mainCommand == "SIZE")
        {
            std::cout << this->editor.size() << " byte(s)" << std::endl;
        }
        else if (mainCommand == "EDIT")
        {
            try
            {
                this->editor.edit(stoi(cmd[1]), stoi(cmd[2]));
            }
            catch(const std::exception& e)
            {
                std::cout << "Fail" << std::endl;
                std::cout << e.what() << std::endl;
                return;
            }

            std::cout << "OK" << std::endl;
        }
        else if (mainCommand == "SHOW")
        {
            try
            {
                this->editor.display(std::cout, stoi(cmd[1]), stoi(cmd[2]));
            }
            catch(const std::exception& e)
            {
                std::cout << "Fail" << std::endl;
                std::cout << e.what() << std::endl;
                return;
            }
        }
    }
};

int main(int argv, char** argc)
{
    if (argv != 2)
    {
        std::cout << "No path" << std::endl;
        return 1;
    }

    try
    {
        Processor processor(argc[1]);

        while (true)
        {
            std::string commandLine;
            std::getline(std::cin, commandLine);

            Command cmd(commandLine);

            processor.execute(cmd);

            if (processor.programHasToStop())
            {
                break;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    // does not have to stop the program when there is invalid command :'(

	return 0;
}