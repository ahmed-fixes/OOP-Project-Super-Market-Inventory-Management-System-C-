#include <iostream>
#include <fstream>
#include "TextFileHandler.h"
#include "SystemController.h"
using namespace std;

int main() {
    TextFileHandler handler;
    SystemController controller(&handler);
    controller.run();
    return 0;
}
