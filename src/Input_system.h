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