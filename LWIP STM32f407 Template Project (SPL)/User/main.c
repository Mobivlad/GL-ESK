#include "system.h"
#include "lwip.h"

int main(void)
{   
    // Setup peiphery interrupts, clocks and system timer
    system_initialize();
    
    // Initialize lwip stack and memory buffer
    lwip_initialize();
    
   
    while (1) 
    {
        lwip_task();
    }
}


