/*
 ============================================================================
 *  adc.c
 *  Date: OCT 3, 2022
 *  Author: Yousef_Osama
 *  Description: The Source File of ADC Driver
 ============================================================================
 */
#include "adc.h"
#include"avr/io.h"
#include"common_macros.h"
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr) {
	ADMUX=(ADMUX&0x3f)|(Config_Ptr->ref_volt<<6);
	SET_BIT(ADCSRA, ADEN);
	CLEAR_BIT(ADCSRA, ADIE);
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr->prescaler);
}
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channelNum) {
	ADMUX = (ADMUX & 0xe0) | (channelNum & 0x0f);
	SET_BIT(ADCSRA, ADSC);
	while (bit_is_clear(ADCSRA, ADIF))
		;
	SET_BIT(ADCSRA, ADIF);
	return ADC;
}
