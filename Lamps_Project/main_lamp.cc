/**
 * Structured LED EposMotesII Controlling
 *
 * This work is licensed under the EPOS Software License v1.0.
 * A copy of this license is available at the EPOS system source tree root.
 * Note that EPOS Software License applies to both source code and executables.
 *
 *  You should have received a copy of the EPOS Software License v1.0 along
 *  with this program. If not, see
 *  <http://epos.lisha.ufsc.br/EPOS+Software+License+v1.0>.
 *
 * *****************************************************************************
 * 
 * 
*/


#include <headers/lamps_project_debugger.h>
#include <headers/array_operations.h>



/**
 * DO NOT MODIFIY IT!
 * 
 * @see The Class LampBoard main include declaration/explanation.
 */
#include <classes/LampBoard.cc>



/**
 * Main function entry point. To creates and configures the lamp smart object application.
 */
int main()
{
    const char* const PROGRAM_VERSION = "0.1";
    
    PRINTLN( 1, "EposMotesII app MAIN_LAMP initing..." );
    PRINTLN( 1, "Program version: " << PROGRAM_VERSION );
    
    PRINTLN( 1, "To send commands to the EPOSMotes2 by USB device, use:" );
    PRINTLN( 1, "echo :R100 > /dev/ttyUSB0" );
    PRINTLN( 1, "Try also :REN, :BEN, :GEN or :AEN" ); 
    
    LampBoard lampBoard( 1 );
    CommunicationSubject::getInstance().addObserver( &lampBoard );
    
    lampBoard.addNewLamp( new LedBlue( new LampConfiguration( "light_sensor", 100 ) ) );
    //lampBoard.addNewLamp( new LedRed( new LampConfiguration( "light_sensor", 100 ) ) );
    //lampBoard.addNewLamp( new LedGreen( new LampConfiguration( "light_sensor", 100 ) ) );
    
    DEBUGGERLN( 1, "lampBoard.getLampBoardId(): " << lampBoard.getLampBoardId() );
    lampBoard.waitForCommunications();
    
    PRINTLN( 1, "EposMotesII app finishing" );
    return 0;
}










