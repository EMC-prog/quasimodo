// Quasimodo program, main file
// Initially released by EMC-Prog, under the MIT License
#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>

//PRE: Valid year integer
//POST: Returns true if the year is a leap year, 
//      according to the following formula: https://learn.microsoft.com/en-us/troubleshoot/microsoft-365-apps/excel/determine-a-leap-year
bool is_leap_year(int year){
    if (year%4 == 0){
        if (year%100 == 0){
            if (year%400 == 0){
                return true;
            } else{
                return false;
            }
        } else{
            return true;
        }
    } else{
        return false;
    }
}

//PRE: Valid day, month and year integers
//POST: The following day is written
//WARNING: This function does NOT handle year transitions. 
//         If called on December 31st, month will become 13.
//         Ensure all dates remain within the given year.
void checkDate(int& day, int& month, int year){
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (is_leap_year(year)){
        daysInMonth[1] = 29;
    }

    day++;

    if (day > daysInMonth[month - 1]){
        day = 1;
        month++;
    }
}

int main(){
    //Data load
    std::cout << "Loading files..." << std::endl;
    int year;
    std::cin >> year;
    std::vector<std::string> content(365, "");
    if (is_leap_year(year)){
        content.push_back(""); // A day is added if leap year
    }
    std::string cont;
    int counter = 0;
    std::getline(std::cin, cont); //Skips the year in the first line
    while (std::getline(std::cin, cont) and counter < content.size()){
        content[counter] = cont;
        counter++;
    }
    // -----
    std::cout << "Files succesfully loaded." << std::endl;
    //Data saving
    //Folder creation
    namespace fs = std::filesystem;
    for (int i = 1; i <= 12; ++i){
        std::string path = "./" + std::to_string(year) + "/" + std::to_string(i);
        fs::create_directories(path);
    }
    //Files creation + day/month calculation with checkDate()
    std::cout << "Creating static pages..." << std::endl;
    int month = 1;
    int day = 1;
    int vectori = 0;
    while (vectori < content.size()){
        std::string path = "./" + std::to_string(year) + "/" + std::to_string(month) + "/" + std::to_string(day) + ".html";
        // Create and open a text file
        std::ofstream EditingFile(path);

        // Write to the file
        EditingFile << "<meta name=" << '"' << "viewport" << '"' << "content="<< '"' << "width=device-width, initial-scale=1.0" << '"' << "><h1>" << content[vectori] << "</h1>";

        // Close the file
        EditingFile.close();

        vectori++;

        checkDate(day, month, year);
    }

    std::cout << "Files succesfully created inside the folder named " << '"' << year << '"' << std::endl;
}
