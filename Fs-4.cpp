#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <string>

void initialize(int argc, char** argv) 
{
    
    if (argc != 2) 
    {
        std::cerr << "Использование: " << argv[0] << " <путь к файлу>" << std::endl;
        exit(1);
    }

    const char* filepath = argv[1];
 
    int file_descriptor = open(filepath, O_RDONLY);
    if (file_descriptor < 0) 
    {
        std::cerr << "Не удалось открыть файл: " << filepath << std::endl;
        exit(1);
    }

    if (dup2(file_descriptor, STDIN_FILENO) < 0) 
    {
        std::cerr << "Не удалось перенаправить стандартный ввод" << std::endl;
        exit(1);
    }

    close(file_descriptor);
}

int main(int argc, char** argv) 
{
    initialize(argc, argv);
    std::string input;
    std::getline(std::cin, input);

    std::string reversed(input.rbegin(), input.rend());

    std::cout << reversed << std::endl;

    return 0;
}
