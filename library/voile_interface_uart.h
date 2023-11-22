/**
 * @file voile_interface_uart.h
 * @author JimmyWang
 * @brief Define class ioPin for any single io
 * 
 */
#ifndef __VOILE_INTERFACE_UART_H__
#define __VOILE_INTERFACE_UART_H__

#include "voile_common.h"

/**
 * @brief Operations of uart
 * 
 */
typedef const struct{
    /**
     * @brief Initialise or reinitialise a uart, set burdrate
     * 
     * @param[in] name :[voile_const_uart_t *] This uart object.
     * @param[in] burdrate :[uint32_t] Set buridrate.
     * @return voile_status_t defined in common.h
     *
     * @par Sample
     * @code
     * myuart.Operate->Init(&myuart, 115200);
     * @endcode
     * 
     */
    voile_status_t (*Init)(void *, uint32_t);
    
    /**
     * @brief Transmit byte by uart
     * 
     * @param[in] name :[voile_const_uart_t *] This uart object.
     * @param[in] value :[uint8_t] Byte for transmit.
     * @return voile_status_t defined in common.h
     *
     * @par Sample
     * @code
     * myuart.Operate->Transmit(&myuart, 'H');
     * @endcode
     *  
     */
    voile_status_t (*Transmit)(void *, uint8_t);

    /**
     * @brief Receive byte from uart
     * 
     * @param[in] name :[voile_const_uart_t *] This uart object.
     * @param[out] value :[uint8_t *] Byte for receive.
     * @return voile_status_t defined in common.h
     *
     * @par Sample
     * @code
     * uint8_t buffer;
     * myuart.Operate->Receive(&myuart, &buffer);
     * @endcode
     *  
     */
    voile_status_t (*Receive)(void *, uint8_t *);
} voile_const_uartOperate_t;


/**
 * @brief Get something from uart
 * 
 */
typedef const struct{
    /**
     * @brief Receive byte from uart
     * 
     * @param[in] name :[voile_const_uart_t *] This uart object.
     * @return [uint8_t] Byte for receive.
     *
     * @par Sample
     * @code
     * uint8_t buffer;
     * buffer = myuart.Get->Receive(&myuart);
     * @endcode
     *  
     */
    uint8_t (*Receive)(void *);
} voile_const_uartGet_t;


/**
 * @brief Class for UART
 * 
 */
typedef const struct{
    voile_const_uartOperate_t *Operate; ///< Operate the uart
    voile_const_uartGet_t *Get;         ///< Get date or status from uart
} voile_const_uart_t;


#endif // !__VOILE_INTERFACE_UART_H__
