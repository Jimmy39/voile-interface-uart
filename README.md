# voile-interface-uart
Define class uart in voile library

```C
/**
 * @brief Class for UART
 * 
 */
typedef const struct{
    voile_const_uartOperate_t *Operate; ///< Operate the uart
    voile_const_uartGet_t *Get;         ///< Get date or status from uart
} voile_const_uart_t;
```

## Define

This struct only have pulic interface.__Do not use it define anything.__

For more information of voile library, see [voile-library](https://github.com/Jimmy39/voile-library)

## Declare

```C
voile_const_uart_t myuart;
```

## Use

There is a docs created by doxygen.https://jimmy39.github.io/voile-interface-uart/index.html

