
#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string.h>
#include <sstream>
#include <unistd.h>
#include <errno.h>



/**
 * This defines an interface for an smart object. Every smart object must to be able to communicates
 * with the other. To accomplish that they also need to use the same communication interface
 * compatible technology as the TCP/IP or the ARM MC13224V built-in 2.4 GHz 802.15.4 RF Radio.
 */
class Interface
{
public:
    
    /**
     * 
     * 
     * @param 
     */
    virtual void sendMessage( const char* ) = 0;
};




