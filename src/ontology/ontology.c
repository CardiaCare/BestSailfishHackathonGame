#include "ontology.h"



#if INCLUDE_CLASS_THING
sslog_class_t *CLASS_THING;
#endif
#if INCLUDE_CLASS_PARTICLE
sslog_class_t *CLASS_PARTICLE;
#endif
#if INCLUDE_CLASS_NOTHING
sslog_class_t *CLASS_NOTHING;
#endif
#if INCLUDE_CLASS_GAMER
sslog_class_t *CLASS_GAMER;
#endif
#if INCLUDE_CLASS_VIRUS
sslog_class_t *CLASS_VIRUS;
#endif


#if INCLUDE_PROPERTY_CHARGE
sslog_property_t *PROPERTY_CHARGE;
#endif
#if INCLUDE_PROPERTY_SCORE
sslog_property_t *PROPERTY_SCORE;
#endif
#if INCLUDE_PROPERTY_FROM
sslog_property_t *PROPERTY_FROM;
#endif
#if INCLUDE_PROPERTY_SEND
sslog_property_t *PROPERTY_SEND;
#endif
#if INCLUDE_PROPERTY_HAS
sslog_property_t *PROPERTY_HAS;
#endif
#if INCLUDE_PROPERTY_TO
sslog_property_t *PROPERTY_TO;
#endif
#if INCLUDE_PROPERTY_COLOR
sslog_property_t *PROPERTY_COLOR;
#endif



/**
 * @brief Register ontology.
 *
 * It creates all structures, such as classes and properties. Use it firs in your propgramm.
 */
void register_ontology()
{    
#if INCLUDE_PROPERTY_CHARGE
PROPERTY_CHARGE =  sslog_new_property("http://oss.fruct.org/virusgame#charge", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_SCORE
PROPERTY_SCORE =  sslog_new_property("http://oss.fruct.org/virusgame#score", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_FROM
PROPERTY_FROM =  sslog_new_property("http://oss.fruct.org/virusgame#from", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_SEND
PROPERTY_SEND =  sslog_new_property("http://oss.fruct.org/virusgame#send", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HAS
PROPERTY_HAS =  sslog_new_property("http://oss.fruct.org/virusgame#has", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_TO
PROPERTY_TO =  sslog_new_property("http://oss.fruct.org/virusgame#to", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_COLOR
PROPERTY_COLOR =  sslog_new_property("http://oss.fruct.org/virusgame#color", SSLOG_PROPERTY_TYPE_DATA);
#endif



#if INCLUDE_CLASS_THING
CLASS_THING = sslog_new_class("http://www.w3.org/2002/07/owl#Thing");
#endif
#if INCLUDE_CLASS_PARTICLE
CLASS_PARTICLE = sslog_new_class("http://oss.fruct.org/virusgame#Particle");
#endif
#if INCLUDE_CLASS_NOTHING
CLASS_NOTHING = sslog_new_class("http://www.w3.org/2002/07/owl#Nothing");
#endif
#if INCLUDE_CLASS_GAMER
CLASS_GAMER = sslog_new_class("http://oss.fruct.org/virusgame#Gamer");
#endif
#if INCLUDE_CLASS_VIRUS
CLASS_VIRUS = sslog_new_class("http://oss.fruct.org/virusgame#Virus");
#endif



}


