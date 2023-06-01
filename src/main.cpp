#include <iostream>
#include <stdio.h>
#include <window.h>
int win(bool on);
int main(void)
{
    Window WIN("game",800,600);
    printf("[%s][%s]: %s at %p \n","window","info","creat window",WIN.window);
    while(WIN.are_not_closed())
    {
        WIN.Update();
    }
    
    return 0;
}
