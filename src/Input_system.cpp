#include <iostream>
#include <functional>
#include <unordered_map>
#include <GLFW/glfw3.h>

class InputSystem {
public:
    InputSystem(GLFWwindow* window)
        : window(window)
    {
        glfwSetWindowUserPointer(window, this);
        glfwSetKeyCallback(window, keyCallback);
    }

    void update()
    {
        glfwPollEvents();
    }

    void registerKeyAction(int key, std::function<void(int, int)> action, bool active = true)
    {
        keyActions[key] = { std::move(action), active };
    }

    void setActiveKeyAction(int key, bool active)
    {
        auto it = keyActions.find(key);
        if (it != keyActions.end())
        {
            it->second.active = active;
        }
    }

private:
    struct KeyAction {
        std::function<void(int, int)> action;
        bool active;
    };

    GLFWwindow* window;
    std::unordered_map<int, KeyAction> keyActions;

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        InputSystem* inputSystem = static_cast<InputSystem*>(glfwGetWindowUserPointer(window));
        if (inputSystem)
        {
            auto it = inputSystem->keyActions.find(key);
            if (it != inputSystem->keyActions.end() && it->second.active)
            {
                it->second.action(key, action);
            }
        }
    }
};

void KeyBehavior(int key, int action)
{
    if (action == GLFW_PRESS)
    {
        std::cout << "Key Pressed: " << key << std::endl;
        // Add your desired behavior for key press event
    }
    else if (action == GLFW_RELEASE)
    {
        std::cout << "Key Released: " << key << std::endl;
        // Add your desired behavior for key release event
    }
    else
    {
        std::cout << "Key Repeat: " << key << std::endl;
    }
}

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Input System Example", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Create an instance of the InputSystem class
    InputSystem inputSystem(window);

    // Register key actions with onKeyPressed function
    inputSystem.registerKeyAction(GLFW_KEY_A, KeyBehavior, true);
    inputSystem.registerKeyAction(GLFW_KEY_D, KeyBehavior, true);
    inputSystem.registerKeyAction(GLFW_KEY_W, KeyBehavior, true);
    inputSystem.registerKeyAction(GLFW_KEY_S, KeyBehavior, true);
    inputSystem.registerKeyAction(GLFW_KEY_SPACE, KeyBehavior, true);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        inputSystem.update();
    }

    // Clean up GLFW
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
