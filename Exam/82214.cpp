// 
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Обектно-ориентирано програмиране 2020/21
// Практически изпит
// 
// Име: Петър Станомиров Колев
// ФН: 82214
// Специалност: Компютърни науки
// Курс: 1
// Административна група: 4
// Ден, в който се явявате на изпита: 07.07.2021 г. 
// Начален час на изпита: 08:00 ч.
// Кой компилатор използвате: GCC
//

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Property
{
private:
    const std::string name;
    const int quantity;
    const double priceMnogitel;

public:
    Property(std::string name, int quantity, double priceMnogitel)
        : name(name), quantity(quantity), priceMnogitel(priceMnogitel)
    {}

    double price() const
    {
        return this->quantity * this->priceMnogitel;
    }

    std::string getName() const
    {
        return this->name;
    }

    int getQuantity() const
    {
        return this->quantity;
    }

    void print(std::ostream& out) const
    {
        out << "Name: " << this->name << std::endl;
        out << "Quantity: " << this->quantity << std::endl;
        out << "Price mnogitel: " << this->priceMnogitel << std::endl;
    }
};

class Component
{
protected:
    std::vector<Property> properties;

public:
    Component() = default;

    int getQuantity(std::string name) const
    {
        std::size_t size = this->properties.size();
        for (std::size_t i = 0; i < size; ++i)
        {
            if (name == this->properties[i].getName())
            {
                return this->properties[i].getQuantity();
            }
        }

        throw std::invalid_argument("There isn't a property with such name");
    }

    double price() const
    {
        double result = 0.0;
        std::size_t size = this->properties.size();
        for (std::size_t i = 0; i < size; ++i)
        {
            result += this->properties[i].price();
        }

        return result;
    }
    
    void print(std::ostream& out) const
    {
        std::size_t size = this->properties.size();
        for (std::size_t i = 0; i < size; ++i)
        {
            this->properties[i].print(out);
        }
    }
};

class CPU : public Component
{
public:
    CPU(unsigned int coresQuantity, double coresPriceMnogitel, int chestotaQuantity, double chestotaPriceMnogitel)
        : Component()
    {
        this->properties.push_back(Property("cores", coresQuantity, coresPriceMnogitel));
        this->properties.push_back(Property("chestota", chestotaQuantity, chestotaPriceMnogitel));
    }
};

class RAM : public Component
{
public:
    RAM(unsigned int gigabytesQuantity, double gigabytePriceMnogitel, unsigned int chipsQuantity, 
            double chipsPriceMnogitel, unsigned int colorsQuantity, double colorsPriceMnogitel)
        : Component()
    {
        this->properties.push_back(Property("gigabytes", gigabytesQuantity, gigabytePriceMnogitel));
        this->properties.push_back(Property("chips", chipsQuantity, chipsPriceMnogitel));
        this->properties.push_back(Property("colors", colorsQuantity, colorsPriceMnogitel));
    }
};

class HDD : public Component
{
public:
    HDD(unsigned int terabytesQuantity, double terabytePriceMnogitel, unsigned int readingSpeedQuantity, 
            double readingSpeedPriceMnogitel, unsigned int writingSpeedQuantity, double writingSpeedPriceMnogitel)
        : Component()
    {
        this->properties.push_back(Property("terabytes", terabytesQuantity, terabytePriceMnogitel));
        this->properties.push_back(Property("reading speed", readingSpeedQuantity, readingSpeedPriceMnogitel));
        this->properties.push_back(Property("writing speed", writingSpeedQuantity, writingSpeedPriceMnogitel));
    }
};

class Store
{
private:
    std::vector<Component*> components;

public:
    Store() = default;
    Store(const Store& other) = delete;
    Store& operator = (const Store& other) = delete;

    std::size_t size() const
    {
        return this->components.size();
    }

    ~Store()
    {
        std::size_t size = this->size();
        for (std::size_t i = 0; i < size; ++i)
        {
            if (this->components[i])
            {
                delete this->components[i];
            }
        }
    }

    void addComponent(Component* component)
    {
        this->components.push_back(component);
    }

    void removeComponent(Component* component)
    {
        std::size_t size = this->size();

        for (std::size_t i = 0; i < size; ++i)
        {
            if (component == this->components[i])
            {
                this->components[i] = nullptr;
                this->components.erase(this->components.begin() + i);
            }
        } 
    }

    Component* operator [] (std::size_t index) const
    {
        if (index >= this->size())
        {
            throw std::out_of_range("Invalid index");
        }

        return this->components[index];
    }

    void print(std::ostream& out) const
    {
        for (std::size_t i = 0; i < this->size(); ++i)
        {
            this->components[i]->print(out);
        }
    }
};

class Store_builder
{
private:
    int getNumberOfArguments(std::string line)
    {
        int counter = 0;
        std::size_t size = line.size();
        int index = 0;

        std::string current;
        while (index < size)
        {
            if (line[index] == ' ')
            {
                ++counter;
            }

            ++index;
        }

        ++counter;

        return counter;
    }

public:
    Store_builder() = default;

    Store* createStore(std::string path)
    {
        Store* result = nullptr;

        try
        {
            result = new Store();
        }
        catch(const std::bad_alloc& ba)
        {
            std::cerr << "Memory problem" << std::endl;;
            return nullptr;
        }
        

        std::ifstream file(path.c_str());
        if (!file.is_open())
        {
            throw std::invalid_argument("Problem while opening the file!");
        }

        std::size_t currentGetter = file.tellg();
        std::string currentLine;
        while(std::getline(file, currentLine))
        {
            file.seekg(currentGetter, std::ios::beg);
            Component* componentToAdd = nullptr;
            int numberOfArguments = this->getNumberOfArguments(currentLine);
            std::string nameOfComponent;
            file >> nameOfComponent;
            if (nameOfComponent == "cpu")
            {
                int coresQuantity, chestotaQuantity;
                double coresPriceMnogitel, chestotaPriceMnogitel;
                file >> coresQuantity >> coresPriceMnogitel >> chestotaQuantity >> chestotaPriceMnogitel; 
                try
                {
                    componentToAdd = new CPU(coresQuantity, coresPriceMnogitel, chestotaQuantity, chestotaPriceMnogitel);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                }
                
            }
            else if (nameOfComponent == "ram")
            {
                int gigabytesQuantity, chipsQuantity, colorsQuantity;
                double gigabytesPriceMnogitel, chipsPriceMnogitel, colorsPriceMnogitel;
                file >> gigabytesQuantity >> gigabytesPriceMnogitel >> chipsQuantity >> chipsPriceMnogitel >> colorsQuantity >> colorsPriceMnogitel;
                
                try
                {
                    componentToAdd = new RAM(gigabytesQuantity, gigabytesPriceMnogitel, chipsQuantity, chipsPriceMnogitel, colorsQuantity, colorsPriceMnogitel);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                }
            }
            else if (nameOfComponent == "hdd")
            {
                int terabytesQuantity, readingSpeedQuantity, writingSpeedQuantity;
                double terabytesPriceMnogitel, readingSpeedPriceMnogitel, writingSpeedPriceMnogitel;
                file >> terabytesQuantity >> terabytesPriceMnogitel >> readingSpeedQuantity >> readingSpeedPriceMnogitel >> writingSpeedQuantity >> writingSpeedPriceMnogitel;
                try
                {
                    componentToAdd = new HDD(terabytesQuantity, terabytesPriceMnogitel, readingSpeedQuantity, readingSpeedPriceMnogitel, writingSpeedQuantity, writingSpeedPriceMnogitel);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                }
            }

            currentGetter = file.tellg();

            if (componentToAdd)
            {
                result->addComponent(componentToAdd);
            }
            else
            {
                std::cout << "Problem while reading the component" << std::endl;
            }
        }

        file.close();

        return result;
    }

};

class Configuration_Requirement
{
protected:
    std::vector<Component*> components;

public:
    Configuration_Requirement() = default;
    Configuration_Requirement(const Configuration_Requirement& other) = delete;
    Configuration_Requirement& operator = (const Configuration_Requirement& other) = delete;
    ~Configuration_Requirement()
    {
        std::size_t size = this->size();
        for (std::size_t i = 0; i < size; ++i)
        {
            if (this->components[i])
            {
                delete this->components[i];
            }
        }
    }

    void addComponent(Component* component)
    {
        std::size_t size = this->size();
        for (std::size_t i = 0; i < size; ++i)
        {
            if (typeid(*this->components[i]) == typeid(*component))
            {
                throw std::invalid_argument("There is already a component from the same type");
            }
        }

        this->components.push_back(component);
    }

    std::size_t size() const
    {
        return this->components.size();
    }

    Component* operator [] (std::size_t index) const
    {
        if (index >= this->size())
        {
            throw std::out_of_range("Invalid index");
        }

        return this->components[index];
    }
};

class Configuration : public Configuration_Requirement
{
private:
    static const double NADCENKA;

public:
    Configuration()
        : Configuration_Requirement()
    {}
    double price() 
    {
        double result = 0.0;
        std::size_t size = this->size();
        for (std::size_t i = 0; i < size; ++i)
        {
            result += this->components[i]->price();
        }

        result = result + result * NADCENKA / 100;

        return result;
    }
};

const double Configuration::NADCENKA = 7;

class Requirement : public Configuration_Requirement
{
public:
    Requirement()
        : Configuration_Requirement()
    {}
    /*bool minRequired(const Configuration& configuration)
    {
        std::size_t sizeRequirement = this->size();
        std::size_t sizeConfiguration = configuration.size();
        for (std::size_t i = 0; i < sizeRequirement; ++i)
        {
            std::string componentName = typeid(*this->components[i]).name();
            bool found = false;
            for (std::size_t j = 0; j < sizeConfiguration; ++j)
            {
                if (componentName == typeid(*configuration[j]).name())
                {
                    found = true;
                    
                }
            }
        }
    }*/ // mazalo
};

class Configurator
{
private:
    static bool componentIsBetterThan(Component* comp1, Component* comp2)
    {
        if (typeid(*comp1) != typeid(*comp2))
        {
            return false;
        }

        if (typeid(*comp1) == typeid(CPU))
        {
            if (comp1->getQuantity("cores") < comp2->getQuantity("cores"))
            {
                return false;
            }

            if (comp1->getQuantity("chestota") < comp2->getQuantity("chestota"))
            {
                return false;
            }
        }

        if (typeid(*comp1) == typeid(RAM))
        {
            if (comp1->getQuantity("gigabytes") < comp2->getQuantity("gigabytes"))
            {
                return false;
            }

            if (comp1->getQuantity("chips") < comp2->getQuantity("chips"))
            {
                return false;
            }

            if (comp1->getQuantity("colors") < comp2->getQuantity("colors"))
            {
                return false;
            }
        }

        if (typeid(*comp1) == typeid(HDD))
        {
            if (comp1->getQuantity("terabytes") < comp2->getQuantity("terabytes"))
            {
                return false;
            }

            if (comp1->getQuantity("reading speed") < comp2->getQuantity("reading speed"))
            {
                return false;
            }

            if (comp1->getQuantity("writing speed") < comp2->getQuantity("writing speed"))
            {
                return false;
            }
        }

        return true;
    }
public:
    static Configuration* createConfiguration(Store& store, const Requirement& requirement)
    {
        Configuration* result = nullptr;

        try
        {
            result = new Configuration();
        }
        catch(const std::bad_alloc& ba)
        {
            std::cerr << "Memory problem" << std::endl;
            return nullptr;
        }
        
        std::size_t sizeRequirement = requirement.size();
        for (std::size_t i = 0; i < sizeRequirement; ++i)
        {
            for (std::size_t j = 0; j < store.size(); ++j)
            if (Configurator::componentIsBetterThan(store[j], requirement[i]))
            {
                try
                {
                    result->addComponent(store[j]);
                    store.removeComponent(store[j]);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                }
                
            }
        }

        return result;
    }
};

class Utils
{
public:
    static void printMenu()
    {
        std::cout << "What kind of component do you want to add yo your requirement?" << std::endl;
        std::cout << "1. CPU" << std::endl;
        std::cout << "2. RAM" << std::endl;
        std::cout << "3. HDD" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Please enter here: ";
    }
};

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Invalid number of arguments!" << std::endl;
        return 1;
    }

    Store_builder sb;

    Store* store = sb.createStore(argv[1]);

    Requirement req;

    int choice;
    do
    {
        Utils::printMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            int coresQuantity, chestotaQuantity;
            double coresPriceMnogitel, chestotaPriceMnogitel;
            std::cout << "Enter number of cores: ";
            std::cin >> coresQuantity;
            std::cout << "Enter price mnogitel of a core: ";
            std::cin >> coresPriceMnogitel;
            std::cout << "Enter chestota (MHz): ";
            std::cin >> chestotaQuantity;
            std::cout << "Enter price mnogitel of chestota: ";
            std::cin >> chestotaPriceMnogitel;

            req.addComponent(new CPU(coresQuantity, coresPriceMnogitel, chestotaQuantity, chestotaPriceMnogitel));
            break;

        case 2:
            int gigabytesQuantity, chipsQuantity, colorsQuantity;
            double gigabytesPriceMnogitel, chipsPriceMnogitel, colorsPriceMnogitel;
            std::cout << "Enter number of gigabytes: ";
            std::cin >> gigabytesQuantity;
            std::cout << "Enter price mnogitel of a gigabyte: ";
            std::cin >> gigabytesPriceMnogitel;
            std::cout << "Enter number of chips: ";
            std::cin >> chipsQuantity;
            std::cout << "Enter price mnogitel of a chip: ";
            std::cin >> chipsPriceMnogitel;
            std::cout << "Enter number of colors: ";
            std::cin >> colorsQuantity;
            std::cout << "Enter price mnogitel of a color: ";
            std::cin >> colorsPriceMnogitel;

            req.addComponent(new RAM(gigabytesQuantity, gigabytesPriceMnogitel, chipsQuantity, chipsPriceMnogitel, colorsQuantity, colorsPriceMnogitel));
            break;

        case 3:
            int terabytesQuantity, readingSpeedQuantity, writingSpeedQuantity;
            double terabytesPriceMnogitel, readingSpeedPriceMnogitel, writingSpeedPriceMnogitel;
            
            // ...

            req.addComponent(new HDD(gigabytesQuantity, gigabytesPriceMnogitel, chipsQuantity, chipsPriceMnogitel, colorsQuantity, colorsPriceMnogitel));
            break;
        
        default:
            break;
        }

    } while (choice);
    
    //store->print(std::cout);

    Configuration* config = Configurator::createConfiguration(*store, req);

    delete store;
    delete config;

	return 0;
}