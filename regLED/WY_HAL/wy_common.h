#ifndef CD9F1D66_3EDD_4E66_AFB6_3F0E9EB9EECF
#define CD9F1D66_3EDD_4E66_AFB6_3F0E9EB9EECF
#include "stdint.h"
typedef enum
{
    DISABLE = 0,
    ENABLE = !DISABLE
} FunctionalState;
typedef enum
{
    RESET = 0,
    SET = !RESET
} FlagStatus,
ITStatus;
typedef enum
{
    ERROR = 0,
    SUCCESS = !ERROR
} ErrorStatus;

#endif /* CD9F1D66_3EDD_4E66_AFB6_3F0E9EB9EECF */
