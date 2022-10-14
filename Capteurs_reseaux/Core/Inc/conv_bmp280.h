/*
 * conv_bmp280.h
 *
 *  Created on: Oct 14, 2022
 *      Author: coren
 */

#ifndef INC_CONV_BMP280_H_
#define INC_CONV_BMP280_H_

#include <stdio.h>

int32_t bmp280_compensate_T_int32(int32_t adc_T);
uint32_t bmp280_compensate_P_int32(int32_t adc_P);



#endif /* INC_CONV_BMP280_H_ */
