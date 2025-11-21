#include <iostream>
#include <fstream>
#include <cstdlib>


int main(int ac, char **av)
{
    std::fstream infile;
    std::fstream outfile;

 	if(ac != 4){
        return(std::cerr << "\033[31mUsage: <file> <string> <string>\033[0m" << std::endl , EXIT_FAILURE);
    }
    else{

        std::string filename = av[1];
        std::string fileRep = filename + ".replace";;
        std::string instr = av[2];
        std::string repstr = av[3];

        infile.open(filename.c_str(), std::ios::in);
        if (infile.is_open()){
            std::cout << "File '" << filename << "' opened successfully.";

            /* Read - find - replace */
            std::string line;
            outfile.open(fileRep.c_str(), std::ios::out);
            while(getline(infile, line)){
                /*
                    1- replace in line
                    2- write to file.replace
                */
                size_t pos = 0;
                while((pos = line.find(instr, pos)) != std::string::npos)
                {
                    line.erase(pos, instr.length());
                    line.insert(pos, repstr);
                    
                    pos += repstr.length();
                }
                outfile << line << std::endl;
            }

        }
        else{
            std::cout << "Error: Could not open file '" << filename << "'." << std::endl;
        }

        infile.close(); /* Close the file when done */
        outfile.close();
        return (EXIT_FAILURE);
    }
}

