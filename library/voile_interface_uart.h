/**
 * @file voile_interface_uart.h
 * @author JimmyWang
 * @brief Define class uart for any uart
 *
 */
#ifndef __VOILE_INTERFACE_UART_H__
#define __VOILE_INTERFACE_UART_H__

#define __FOR_VOILE_UART__
#include "voile_common.h"
#undef __FOR_VOILE_UART__

#include "voile_errorno.h"

/**
 * @brief Class for UART
 *
 */
typedef const struct voile_uart_interface_struct *voile_const_uart_t;

typedef enum {
    UART_TXbuffer_full,
    UART_TXbuffer_empty,
    UART_RXbuffer_full,
    UART_RXbuffer_empty
} voile_uart_flag_t;

#include "voile_uart_interface_struct.h"

/**
 * @brief Initialise or reinitialise a uart, set baudrate.
 *
 * @param[in] name :[voile_const_uart_t *] This uart object.
 * @param[in] baudrate :[uint32_t] Set.
 * @return voile_status_t defined in common.h
 *
 * @par Sample
 * @code
 * myuart.Operate->Init(&myuart, 115200);
 * @endcode
 *
 */
static inline void Vuart_init(voile_const_uart_t *uart_p) {
    (*uart_p)->init(uart_p);
}

static inline uint32_t Vuart_setBaudrate(
    voile_const_uart_t *uart_p, uint32_t baudrate) {
    return (*uart_p)->setBaudrate(uart_p, baudrate);
}

static inline uint32_t Vuart_getBaudrate(voile_const_uart_t *uart_p) {
    return (*uart_p)->setBaudrate(uart_p, 0);
}

/**
 * @brief Transmit byte by uart.
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
static inline void Vuart_send(
    voile_const_uart_t *uart_p, uint8_t *data_p, uint8_t length) {
    (*uart_p)->send(uart_p, data_p, length);
}

/**
 * @brief Receive byte from uart.
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
static inline void Vuart_receive(
    voile_const_uart_t *uart_p, uint8_t *data_p, uint8_t length) {
    (*uart_p)->receive(uart_p, data_p, length);
}

/**
 * @brief Receive byte from uart.
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
static inline uint8_t Vuart_receiveByte(voile_const_uart_t *uart_p) {
    return (*uart_p)->receive(uart_p, NULL, 1);
}

/**
 * @brief Determine if transmit is available.
 *
 * @param[in] name :[voile_const_uart_t *] This uart object.
 * @return [bool] True means transmit is available.
 *
 * @par Sample
 * @code
 * if(myuart.Get->IsWriteable(&myuart)){
 * }
 * @endcode
 *
 */
static inline bool Vuart_getFlag(
    voile_const_uart_t *uart_p, voile_uart_flag_t flag) {
    return (*uart_p)->getFlag(uart_p, flag);
}

/**
 * @brief Determine if receive is available.
 *
 * @param[in] name :[voile_const_uart_t *] This uart object.
 * @return [bool] True means receive is available.
 *
 * @par Sample
 * @code
 * if(myuart.Get->IsReadable(&myuart)){
 * }
 * @endcode
 *
 */

#endif  // !__VOILE_INTERFACE_UART_H__
