struct voile_uart_interface_struct {

    void (*init)(voile_const_uart_t *uart_p);

    uint32_t (*setBaudrate)(voile_const_uart_t *uart_p, uint32_t baudrate);

    void (*send)(voile_const_uart_t *uart_p, uint8_t *data_p, uint8_t length);

    uint8_t (*get)(voile_const_uart_t *uart_p, uint8_t *data_p, uint8_t length);

    uint8_t (*getflag)(voile_const_uart_t *uart_p, voile_uart_flag_t flag);
};
