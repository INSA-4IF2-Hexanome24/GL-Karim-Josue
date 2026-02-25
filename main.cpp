#include <iostream>
#include "lexer.h"
#include "automate.h"

int main() {
    std::string chaine("1+3");
    Lexer lexer(chaine);
    Automate a(&lexer);
    a.Analyse();
    return 0;
}

