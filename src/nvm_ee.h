// Copyright (c) 2023 Ziga Miklosic
// All Rights Reserved
////////////////////////////////////////////////////////////////////////////////
/**
*@file      nvm_ee.h
*@brief     NVM EEPROM Emulation
*@author    Ziga Miklosic
*@email		ziga.miklosic@gmail.com
*@date      14.02.2023
*@version   V2.0.0
*/
////////////////////////////////////////////////////////////////////////////////
/**
*@addtogroup NVM_EE_API
* @{ <!-- BEGIN GROUP -->
*
*/
////////////////////////////////////////////////////////////////////////////////

#ifndef __NVM_EE_H
#define __NVM_EE_H

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "nvm.h"
//#include "../../nvm_cfg.h"


////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////
nvm_status_t nvm_ee_init    (void);
nvm_status_t nvm_ee_write   (const nvm_region_name_t region, const uint32_t addr, const uint32_t size, const uint8_t * const p_data);
nvm_status_t nvm_ee_read    (const nvm_region_name_t region, const uint32_t addr, const uint32_t size, uint8_t * const p_data);
nvm_status_t nvm_ee_erase   (const nvm_region_name_t region, const uint32_t addr, const uint32_t size);
nvm_status_t nvm_ee_sync    (void);

#endif // __NVM_EE_H

////////////////////////////////////////////////////////////////////////////////
/**
* @} <!-- END GROUP -->
*/
////////////////////////////////////////////////////////////////////////////////
