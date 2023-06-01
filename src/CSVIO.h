#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class CSVIO {
public:
    // Read CSV file and return a vector of rows
    static std::vector<std::vector<std::string>> ReadCSV(const std::string& filename)
    {
        std::vector<std::vector<std::string>> rows;
        std::ifstream file(filename);

        if (!file.is_open())
        {
            std::cerr << "Failed to open CSV file: " << filename << std::endl;
            return rows;
        }

        std::string line;
        while (std::getline(file, line))
        {
            std::vector<std::string> row;
            std::stringstream ss(line);
            std::string cell;

            while (std::getline(ss, cell, ','))
            {
                row.push_back(cell);
            }

            rows.push_back(row);
        }

        file.close();
        return rows;
    }

    // Write vector of rows to CSV file
    static void WriteCSV(const std::string& filename, const std::vector<std::vector<std::string>>& rows)
    {
        std::ofstream file(filename);

        if (!file.is_open())
        {
            std::cerr << "Failed to open CSV file: " << filename << std::endl;
            return;
        }

        for (const auto& row : rows)
        {
            for (size_t i = 0; i < row.size(); ++i)
            {
                file << row[i];

                if (i != row.size() - 1)
                {
                    file << ",";
                }
            }

            file << std::endl;
        }

        file.close();
    }
};
/*
int main()
{
    // Read CSV file
    std::vector<std::vector<std::string>> data = CSVIO::ReadCSV("data.csv");

    // Print the data
    for (const auto& row : data)
    {
        for (const auto& cell : row)
        {
            std::cout << cell << "\t";
        }
        std::cout << std::endl;
    }

    // Create a new CSV file and write data
    std::vector<std::vector<std::string>> newData = {{"John", "Doe", "25"}, {"Jane", "Smith", "30"}};
    CSVIO::WriteCSV("new_data.csv", newData);

    return 0;
}
*/