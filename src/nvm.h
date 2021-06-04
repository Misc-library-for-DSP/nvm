////////////////////////////////////////////////////////////////////////////////
/**
*@file      nvm.h
*@brief     Non-Volatile memory
*@author    Ziga Miklosic
*@date      04.06.2021
*@version	V1.0.0
*/
////////////////////////////////////////////////////////////////////////////////
/**
*@addtogroup NVM
* @{ <!-- BEGIN GROUP -->
*/
////////////////////////////////////////////////////////////////////////////////

#ifndef _NVM_H_
#define _NVM_H_

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include <stdint.h>
#include <stdbool.h>


////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

/**
 * 	Status
 */
typedef enum
{
	eNVM_OK 	= 0,		/**<Normal operation */
	eNVM_ERROR	= 0x01,		/**<General error */

} nvm_status_t;

/**
 * 	Memory device driver
 */
typedef struct
{
	nvm_status_t (*pf_nvm_init)		(void);
	nvm_status_t (*pf_nvm_write)	(const uint32_t addr, const uint32_t size, const uint8_t * const p_data);
	nvm_status_t (*pf_nvm_read)		(const uint32_t addr, const uint32_t size, uint8_t * const p_data);
	nvm_status_t (*pf_nvm_erase)	(const uint32_t addr, const uint32_t size);
} nvm_mem_driver_t;

/**
 * 	Memory region
 */
typedef struct nvm_region_s
{
	const uint32_t 	start_addr;		/**<Start address of region */
	const uint32_t 	end_addr;		/**<End address of region */
	const char		name;			/**<Name of region */
} nvm_region_t;


////////////////////////////////////////////////////////////////////////////////
// Functions Prototypes
////////////////////////////////////////////////////////////////////////////////
nvm_status_t 	nvm_init	(void);
bool			nvm_is_init	(void);
nvm_status_t 	nvm_write	(const uint8_t driver, const uint8_t region, const uint32_t addr, const uint32_t size, const uint8_t * const p_data);
nvm_status_t 	nvm_read	(const uint8_t driver, const uint8_t region, const uint32_t addr, const uint32_t size, uint8_t * const p_data);
nvm_status_t 	nvm_erase	(const uint8_t driver, const uint8_t region, const uint32_t addr, const uint32_t size);

#endif // _NVM_H_
