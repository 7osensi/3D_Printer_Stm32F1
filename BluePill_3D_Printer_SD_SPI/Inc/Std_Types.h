/*============================== ========================================================
===========================   - STD_TYPES					 ============================
===========================   - Created: 5/5/2021			 ============================
===========================   - Author: Hussein Mohamed      ===========================
===========================   - Version : _1_				 ============================
===========================   - Note :
									*-
									*-
=======================================================================================*/


#ifndef STD_TYPES_H_
#define STD_TYPES_H_
		/*
		 * Boolean Values
		 */
		
#ifndef		FALSE
	#define	FALSE   							 0U
#endif
	
#ifndef		TRUE
	#define	TRUE    							 1U
#endif
	
#define 	HIGH				  				 1U
#define 	LOW					   				 0U
	

typedef 	unsigned char						 u8		  	  	;				/*	0		      :	    	 255	     */
typedef 	unsigned short int				     u16		  	;				/*  0		      :	    	 65535		 */
typedef 	unsigned long  int				     u32		  	;				/*	0	          :	    	4294967295   */
																											  	    
typedef 	signed char							 s8		  	  	;				/*	-128		  :	    	+127		 */
typedef 	signed short int					 s16		  	;				/*	-32768		  :	    	+32768		 */
typedef 	signed long  int					 s32		  	;				/*	-2147483648   :	    	+2147483647	 */

typedef 	unsigned long long int				 u64		  	;
typedef 	signed long long int				 s64		  	;

typedef 	float								 f32	  	  	;
typedef 	double								 f64	      	;

#define 	E_NOK								 0x01		  	;

/**
 * @brief Because E_OK is already defined within OSEK, the symbol E_OK has to be shared.
          To avoid name clashes and redefinition problems, the symbols have to be defined in the following way
 */
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED

#define E_OK 0x00u
/**
 * @brief OSEK compliance
 */
typedef unsigned char StatusType;
#endif
#define E_NOT_OK 0x01u

/**
 * @brief This type can be used as standard API return type which is shared between the RTE and the BSW modules.
 */
typedef		u8									 Std_ReturnType	;

/**
 * @brief This type shall be used to request the version of a BSW module using the <Modulename>_GetVersionInfo() function.
 */
typedef struct
{
	u16 vendorID			;
	u16 moduleID			;
	u8  sw_major_version	;
	u8  sw_minor_version	;
	u8  sw_patch_version	;
}Std_VersionInfoType;

#endif /* STD_TYPES_H_ */
