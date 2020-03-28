#include <iostream>
#include <fstream>
#include <string.h>

int main()
{
    char line[512];
    char ip[512];
    int i, j;

    std::ifstream ipfile("ip");

    while(!ipfile.eof())
    {
        ipfile.getline(line, 512, '\n');

        if(strstr(line, "Temporary IPv6 Address. . . . . . :"))
        {
            break;
        }
    }
    for (i = 0; line[i] != ':'; i++);
    i++;
    i++;

    for (j = 0; line[i] != '\0'; j++, i++)
    {
        ip[j] = line[i];
    }
    ip[j] = '\0';

    std::cout << ip;
    ipfile.close();

    std::ofstream htfile("index.html");

    htfile << "<!DOCTYPE html>\n"
    "<html>\n"
    "<head>\n"
    "    <meta http-equiv=\"refresh\" content=\"1; URL=http://[" << ip << "]/\">\n"
    "</head>\n"
    "<body>\n"
    "</body>\n"
    "</html>\n";

    htfile.close();
    return 1;
}
