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
     * @brief Transmit message by uart
     * 
     * @param[in] name :[voile_const_uart_t *] This uart object.
     * @param[in] value :[uint8_t *] Message for transmit.
     * @param[in] byte :[uint8_t] Byte of message.
     * @return voile_status_t defined in common.h
     *
     * @par Sample
     * @code
     * myuart.Operate->Transmit(&myuart, "Hello world", 12);
     * @endcode
     *  
     */
    voile_status_t (*Transmit)(void *, uint8_t *, uint8_t);

    /**
     * @brief Receive message from uart
     * 
     * @param[in] name :[voile_const_uart_t *] This uart object.
     * @param[in] value :[uint8_t *] Message for receive.
     * @param[in] byte :[uint8_t] Byte of message.
     * @return voile_status_t defined in common.h
     *
     * @par Sample
     * @code
     * uint8_t buffer[20];
     * myuart.Operate->Receive(&myuart, buffer, 20);
     * @endcode
     *  
     */
    voile_status_t (*Receive)(void *, uint8_t *, uint8_t);
} voile_const_uartOperations_t;


/**
 * @brief Class for UART
 * 
 */
typedef const struct{
    voile_const_uartOperations_t *Operate;  ///< Operate the uart
} voile_const_uart_t;


#endif // !__VOILE_INTERFACE_UART_H__
