#include <level.h>
#include <iostream>
#include <fstream>
#include <CSVIO.h>
class level1 : level
{
  public:
    int level1(const std::string level_path)
    {
        CSVIO levelfile;
        level_data.insert(levelfile.ReadCSV(level_path));
        for(int i = 0; i<=level_data.size();i++)
        {
            for(int n = 0; n<=level_data[i].size();n++)
            {
                if ((level_data[i].size() == 1)&&level_data[i][0]=="#player"){i++;}
            }
        }
    }
    vertual int level_loop override(GLFWwindow* window)
    {
        while(!glfwWindowShouldClose(window))
        {
            level(GLFWwindow* window);
            glfwSwapBuffers(window);
            glfwPollEvents();    
        }
    }
    int ~level1();
}
  private:
    static std::vector<std::vector<std::string>> level_data;
    int level(GLFWwindow* window)
    {
        
    }
};