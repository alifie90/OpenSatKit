/*
** Purpose: Define application configurations for the File Manager (FILEMGR)
**          application
**
** Notes:
**   1. The enumeration macro design is from 
**      https://stackoverflow.com/questions/147267/easy-way-to-use-variables-of-enum-types-as-string-in-c/202511 
**
** License:
**   Written by David McComas, licensed under the copyleft GNU
**   General Public License (GPL). 
**
** References:
**   1. OpenSatKit Object-based Application Developer's Guide.
**   2. cFS Application Developer's Guide.
*/
#ifndef _ini_lib_
#define _ini_lib_


/******************************************************************************
** Enumeration Macros
**
** These maintain consistency init file enumerations, string names and 
** structure names 
*/


/* expansion macro for enum value definition */
#define STRUCT_VALUE(name,type) type name;

/* expansion macro for enum value definition */
#define ENUM_VALUE(name,type) name,

/* expansion macro for enum to string conversion */
#define ENUM_CASE(name,type) case name: return #name;

/* expansion macro for string to enum conversion */
#define ENUM_STRCMP(name,type) if (!strcmp(str,#name)) return name;

/* declare the access function and define enum values */
#define DECLARE_ENUM(TypeName,ENUM_DEF) \
  typedef enum { \
    ENUM_DEF(ENUM_VALUE) \
  } INITBL_##TypeName##Enum; \
  typedef struct { \
    ENUM_DEF(STRUCT_VALUE) \
  } INITBL_##TypeName##Struct; \


/* define the access function names */
#define DEFINE_ENUM(TypeName,ENUM_DEF) \
  static const char *Get##TypeName##Str(INITBL_##TypeName##Enum value); \
  static INITBL_##TypeName##Enum Get##TypeName##Val(const char *string); \
  static const char *Get##TypeName##Str(INITBL_##TypeName##Enum value) \
  { \
    switch(value) \
    { \
      ENUM_DEF(ENUM_CASE) \
      default: return ""; /* handle input error */ \
    } \
  } \
  static INITBL_##TypeName##Enum Get##TypeName##Val(const char *str) \
  { \
    ENUM_DEF(ENUM_STRCMP) \
    return (INITBL_##TypeName##Enum)0; /* handle input error */ \
  } \
  
  
#endif /* _ini_lib_ */
