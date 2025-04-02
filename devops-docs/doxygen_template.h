////////////////////////////////////////////////////////////////////////////////
//! \addtogroup system_subsystem
//! @{
//
// Copyright (c) 2024-2025 Tyrell Corp.
//
//! \file doxygen_template.h
//! \brief Brief description here...
//!
//! Detailed description here...
//!
//! \see Cross-references (optional)
////////////////////////////////////////////////////////////////////////////////
#ifndef _DOXYGEN_TEMPLATE_H
#define _DOXYGEN_TEMPLATE_H

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////
//! \brief Brief description of typedef here.
typedef struct _doxygen_FooThing
{
	    
	int32_t (*Init)(void); //!< \brief Description of \c Init.    
	int32_t (*GetByte)(void); //!< \brief Description of \c GetByte.
	int32_t (*Shutdown)(void); //!< \brief Description of \c Shutdown.
	int32_t (*Error)(void); //!< \brief Description of \c Error.
} doxygen_FooThing_t;

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//! \brief Brief description here.
//!
//! \fntype Function
//!
//! The full description of the function goes here. It can
//! be as many lines and paragraphs as you like.
//!
//! \param[in]  x Description of parameter x.
//! \param[in]  z Description of parameter z.
//! \param[out] y Description of parameter y.
//!
//! \return Status of call or error.
//! \retval 0            If no error has occurred.
//! \retval SOME_ERR     Occurs when \c x is greater than \c z.
//! \retval ANOTHER_ERR  Occurs when when \c y is NULL.
//!
//! \pre Describe precondition here.
//! \pre Another precondition.
//! \post Describe postcondition here.
//!
//! \note Use one "note" command for each note.
//!
//! \internal
//! To view function details, see doxygen_template.c.
////////////////////////////////////////////////////////////////////////////////
int32_t foo_Init(int x, int * y, int z);

#endif // _DOXYGEN_TEMPLATE_H

////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}
