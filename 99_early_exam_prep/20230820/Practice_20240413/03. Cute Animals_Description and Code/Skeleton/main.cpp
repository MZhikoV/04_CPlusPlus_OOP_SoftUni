#include <iostream>
#include <sstream>
#include "Noises.h"
#include <cctype>

int main() {
    Noises noises;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string time, noiseWord;
        iss >> time >> noiseWord;

        std::string check=noiseWord;
        for (size_t idx=0; idx<check.size();idx++) {
            check[idx]=tolower(check[idx]);
        }
        if (check== "theend") {
            break;
        };

        std::string result = noises.registerNoise(time, noiseWord);
        std::cout << result << std::endl;
    };

    std::ostringstream oss;
    noises.printStatistics(oss);
    std::cout << "----" << std::endl;
    std::cout << oss.str();


   // system ("pause");
    return 0;
}



/*

+0000 cuckoo
+0020 cock-a-doodle-doo
+0100 TheEnd


+0025 cock-a-doodle-doo
+0030 cock-a-doodle-doo
+0066 cuckoo
+0090 baaaah
+0090 cock-a-doodle-doo
+0090 baaaah
+0090 baaaah
+0095 squeak
+0100 TheEnd

*/