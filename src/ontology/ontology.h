
//Set path to SmartSlog KP Library
#include <smartslog.h>

#ifndef _GENERATED_ONTOLOGY
#define	_GENERATED_ONTOLOGY


#ifdef	__cplusplus
extern "C" {
#endif


#define INCLUDE_ALL_ONT_ENTITIES 1
#ifdef INCLUDE_ALL_ONT_ENTITIES

#define INCLUDE_PROPERTY_CHARGE 1
#define INCLUDE_PROPERTY_SCORE 1
#define INCLUDE_PROPERTY_FROM 1
#define INCLUDE_PROPERTY_SEND 1
#define INCLUDE_PROPERTY_HAS 1
#define INCLUDE_PROPERTY_TO 1
#define INCLUDE_PROPERTY_COLOR 1
#define INCLUDE_CLASS_THING 1
#define INCLUDE_CLASS_PARTICLE 1
#define INCLUDE_CLASS_NOTHING 1
#define INCLUDE_CLASS_GAMER 1
#define INCLUDE_CLASS_VIRUS 1


#else

#define INCLUDE_PROPERTY_CHARGE 0
#define INCLUDE_PROPERTY_SCORE 0
#define INCLUDE_PROPERTY_FROM 0
#define INCLUDE_PROPERTY_SEND 0
#define INCLUDE_PROPERTY_HAS 0
#define INCLUDE_PROPERTY_TO 0
#define INCLUDE_PROPERTY_COLOR 0
#define INCLUDE_CLASS_THING 0
#define INCLUDE_CLASS_PARTICLE 0
#define INCLUDE_CLASS_NOTHING 0
#define INCLUDE_CLASS_GAMER 0
#define INCLUDE_CLASS_VIRUS 0


#endif


#if INCLUDE_CLASS_THING
extern sslog_class_t *CLASS_THING;
#endif
#if INCLUDE_CLASS_PARTICLE
extern sslog_class_t *CLASS_PARTICLE;
#endif
#if INCLUDE_CLASS_NOTHING
extern sslog_class_t *CLASS_NOTHING;
#endif
#if INCLUDE_CLASS_GAMER
extern sslog_class_t *CLASS_GAMER;
#endif
#if INCLUDE_CLASS_VIRUS
extern sslog_class_t *CLASS_VIRUS;
#endif


#if INCLUDE_PROPERTY_CHARGE
extern sslog_property_t *PROPERTY_CHARGE;
#endif
#if INCLUDE_PROPERTY_SCORE
extern sslog_property_t *PROPERTY_SCORE;
#endif
#if INCLUDE_PROPERTY_FROM
extern sslog_property_t *PROPERTY_FROM;
#endif
#if INCLUDE_PROPERTY_SEND
extern sslog_property_t *PROPERTY_SEND;
#endif
#if INCLUDE_PROPERTY_HAS
extern sslog_property_t *PROPERTY_HAS;
#endif
#if INCLUDE_PROPERTY_TO
extern sslog_property_t *PROPERTY_TO;
#endif
#if INCLUDE_PROPERTY_COLOR
extern sslog_property_t *PROPERTY_COLOR;
#endif



void register_ontology();

	
#ifdef	__cplusplus
}
#endif

#endif /* _GENERATED_ONTOLOGY */
