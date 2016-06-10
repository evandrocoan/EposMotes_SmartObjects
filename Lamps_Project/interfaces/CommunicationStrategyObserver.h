/**
* This work is licensed under the EPOS Software License v1.0.
* A copy of this license is available at the EPOS system source tree root.
* Note that EPOS Software License applies to both source code and executables.
*
*  You should have received a copy of the EPOS Software License v1.0 along
*  with this program. If not, see
*  <http://epos.lisha.ufsc.br/EPOS+Software+License+v1.0>.
*
******************************************************************************
*/


#include <classes/Radio.cc>
#include <classes/Usb.cc>
#include <headers/lamps_project_debugger.h>
#include <headers/array_operations.h>



/**
 * Preprocessor directive designed to cause the current source file to be included only once in a
 * single compilation. Thus, serves the same purpose as #include guards, but with several
 * advantages, including: less code, avoidance of name clashes, and sometimes improvement in
 * compilation speed. In main file this is enabled by default.
 */
#pragma once


/**
 * #define __SYS_NS	   System
 * #define __USING_SYS using namespace __SYS_NS
 */
__USING_SYS;



/**
 * This class is the interface used to allow the observers to be called when the observed object
 * is changed. The classes which want to be notified when the observed object changes, must to
 * extend this abstract class and implements its methods.
 */
class CommunicationStrategyObserver
{
public:
    
    /**
     * This defines the communication observer notifier function to be used by this project concrete
     * classes.
     * 
     * @see SmartObjectCommunication interface declaration.
     */
    virtual void receiveMessage( const char* ) = 0;
    
    
protected:
    
    /**
     * Handle all radio communications needed by this project.
     */
    Radio radio;
    
    /**
     * Handle all USB serial communications needed by this project.
     */
    Usb usb;
    
};




