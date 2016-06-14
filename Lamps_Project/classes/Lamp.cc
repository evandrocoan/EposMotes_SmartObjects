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


#include <headers/lamps_project_debugger.h>
#include <headers/array_operations.h>


/**
 * DO NOT MODIFIY IT!
 * 
 * @see The Class LampBoard main include declaration/explanation.
 */
#include <classes/Radio.cc>



/**
 * This class is the class to the Lamp's objects.
 */
class Lamp
{
public:
    
    /**
     * This is to what lamp this configuration to apply. Example: blueLed, redLed, partyColors.
     */
    const char* const lampType;
    
    /**
     * The lamp pin connected into the processor register.
     */
    const int lampPin;
    
    /**
     * To create a new lamp.
     * 
     * @param lampType            see Lamp::lampType member class public atribute.
     * @param configuration       see Lamp::configuration member class public atribute.
     */
    Lamp( const char* lampType, const int lampPin, LampConfiguration* configuration ) :
            lampType( lampType ),
            lampPin( lampPin )
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE Lamp::Lamp(0) THE CONSTRUCTOR! lampType: " << this->lampType );
        this->setNewUserSetting( configuration );
    }
    
    /**
     * Adds a new lamp into the controlling system.
     * 
     * @param setting        an LampConfiguration configuration object.
     */
    bool setNewUserSetting( LampConfiguration* newSetting )
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE LedBlue::setNewUserSetting(1)" );
        
        if( this->configuration == NULL )
        {
            this->configuration = newSetting;
            
            DEBUGGERLN( 1, "    ( setNewUserSetting ) Returning true." );
            return true;
        }
        else if( newSetting != NULL )
        {
            delete configuration;
            this->configuration = newSetting;
            
            DEBUGGERLN( 1, "    ( setNewUserSetting ) Returning true." );
            return true;
        }
        
        DEBUGGERLN( 1, "    ( setNewUserSetting ) Returning false." );
        return false;
    }
    
    /**
     * Gets whether is to fade out when the user runaway its proximities.
     * 
     * @return a boolean value.
     * @see LampConfiguration::isToFadeOut member class public atribute.
     */
    bool getIsToFadeOut()
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE LedBlue::getCurrentBright()" );
        return this->configuration->isToFadeOut;
    }
    
    /**
     * Gets whether is to fade in when the lamp is started at the first time by the user proximity.
     * 
     * @return a boolean value.
     * @see LampConfiguration::isToFadeIn member class public atribute.
     */
    bool getIsToFadeIn()
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE LedBlue::getCurrentBright()" );
        return this->configuration->isToFadeIn;
    }
    
    /**
     * Reads the lamp configuration and get it current desired bright.
     * 
     * @return an int as the current lamp bright.
     */
    int getCurrentBright()
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE LedBlue::getCurrentBright()" );
        return this->configuration->getBright();
    }
    
    /**
     * Reads the lamp configuration and get it current lamp special flags. Example: "use_light_sensor".
     * 
     * @return an const char* as the current lamp special flags.
     */
    const char* getSpecialFlags()
    {
        return this->configuration->specialFlags;
    }
    
    
protected:
    
    /**
     * Contains this lamp configuration.
     */
    LampConfiguration* configuration;
    
};







