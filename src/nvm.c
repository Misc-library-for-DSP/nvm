////////////////////////////////////////////////////////////////////////////////
/**
*@file      nvm.c
*@brief     Non-Volatile memory
*@author    Ziga Miklosic
*@date      04.06.2021
*@version	V1.0.0
*/
////////////////////////////////////////////////////////////////////////////////
/**
*@addtogroup NVM
* @{ <!-- BEGIN GROUP -->
*
* 	Non-volatile memory API functions definition.
*/
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "nvm.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

/**
 * 	Initialization guard
 */
static bool gb_is_init = false;

/**
 * 	Pointer to NVM
 */
static const nvm_region_t * gp_nvm_regions = NULL;


////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////


nvm_status_t nvm_init(void)
{
	nvm_status_t 	status 	= eNVM_OK;
	uint8_t			reg_num	= 0U;

	// Get table configuration
	gp_nvm_regions = nvm_cfg_get_regions();
	NVM_ASSERT( NULL != gp_nvm_regions );

	// Low level driver init
	for ( reg_num = 0; reg_num < eNVM_REGION_NUM_OF; reg_num++ )
	{
		if ( NULL != gp_nvm_regions[reg_num].p_driver->pf_nvm_init )
		{
			gp_nvm_regions[reg_num].p_driver->pf_nvm_init();
		}
	}



	// TODO: Remove only testing...
	gb_is_init = true;


	return status;
}

bool nvm_is_init(void)
{
	return gb_is_init;
}

nvm_status_t nvm_write(const nvm_region_name_t region, const uint32_t addr, const uint32_t size, const uint8_t * const p_data)
{
	nvm_status_t status = eNVM_OK;

	// Is init
	NVM_ASSERT( true == gb_is_init );

	// Check inputs
	NVM_ASSERT( region < eNVM_REGION_NUM_OF );
	NVM_ASSERT(( addr >= gp_nvm_regions[region].start_addr ) && (( addr + size ) < ( gp_nvm_regions[region].start_addr + gp_nvm_regions[region].size )));

	gp_nvm_regions[region].p_driver->pf_nvm_write( addr, size, p_data );

	return status;
}


nvm_status_t nvm_read(const nvm_region_name_t region, const uint32_t addr, const uint32_t size, uint8_t * const p_data)
{
	nvm_status_t status = eNVM_OK;

	// Is init
	NVM_ASSERT( true == gb_is_init );

	// Check inputs
	NVM_ASSERT( region < eNVM_REGION_NUM_OF );
	NVM_ASSERT(( addr >= gp_nvm_regions[region].start_addr ) && (( addr + size ) < ( gp_nvm_regions[region].start_addr + gp_nvm_regions[region].size )));

	gp_nvm_regions[region].p_driver->pf_nvm_read( addr, size, p_data );

	return status;
}

nvm_status_t nvm_erase(const nvm_region_name_t region, const uint32_t addr, const uint32_t size)
{
	nvm_status_t status = eNVM_OK;

	// Is init
	NVM_ASSERT( true == gb_is_init );

	// Check inputs
	NVM_ASSERT( region < eNVM_REGION_NUM_OF );
	NVM_ASSERT(( addr >= gp_nvm_regions[region].start_addr ) && (( addr + size ) < ( gp_nvm_regions[region].start_addr + gp_nvm_regions[region].size )));

	gp_nvm_regions[region].p_driver->pf_nvm_erase( addr, size );

	return status;
}


////////////////////////////////////////////////////////////////////////////////
/**
* @} <!-- END GROUP -->
*/
////////////////////////////////////////////////////////////////////////////////
