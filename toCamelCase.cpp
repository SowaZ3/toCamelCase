#include <iostream>

std::string to_camel_case(std::string text) // transforms snake_case to camelCase (first letter depends on user)
{   
    int markfinder;
    bool breaker = false;

    for (int i = 1; i < text.size(); i++) text[i] = tolower(text[i]);  // tolower transformation (without first letter)

    while(1)
    {
        while(text[0] == '_' || text[0] == '-') text.erase(0,1); // cleans - _

        if (text.find("_") < text.find("-")) markfinder = text.find("_");   // chooses the lowest out of an underscore or a dash
        else if (text.find("-") < text.find("_")) markfinder = text.find("-");
        else break;

        text.erase(markfinder,1);   // erases - _

        text[markfinder] = toupper(text[markfinder]);   // makes upper thw first letter of word
    }

    return text;
}

int main()
{   
    std::string text;
    
    std::cin >> text;
    
    text = to_camel_case(text);

    std::cout << text << std::endl;

    system("pause");    // if the console closes automatically
    return 0;
}
