#include <iostream>
#include <string>
#include <cctype>

bool isValidSubchain(const std::string& subchain) {
    // Перевірка: починається і закінчується символом '^'
    if (subchain.size() < 2 || subchain.front() != '^' || subchain.back() != '^') {
        return false;
    }
    // Перевірка: символи між '^' належать діапазону 'A..Z'
    for (size_t i = 1; i < subchain.size() - 1; ++i) {
        if (!(subchain[i] >= 'A' && subchain[i] <= 'Z')) {
            return false;
        }
    }
    return true;
}

bool isValidChain(const std::string& chain) {
    size_t starPos = chain.find('*'); // Пошук символу '*'
    if (starPos == std::string::npos) {
        return false;
    }
    std::string firstSubchain = chain.substr(0, starPos);        // Перший підланцюжок
    std::string secondSubchain = chain.substr(starPos + 1);      // Другий підланцюжок
    return isValidSubchain(firstSubchain) && isValidSubchain(secondSubchain);
}

int main() {
    std::string input;
    std::cout << "Enter the chain: ";
    std::cin >> input;

    if (isValidChain(input)) {
        std::cout << "The chain is valid." << std::endl;
    }
    else {
        std::cout << "The chain is invalid." << std::endl;
    }

    return 0;
}

