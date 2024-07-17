/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_config.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Ziad_Ashraf
 *  Layer   : MCAL
 *  SW      : ADC
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADC_STATUS   ADC_ENABLE
#define INT_STATUS   INT_ENABLE
#define ADC_VREF  INTERNAL_2_56
#define ADC_ADJUSTMENT RIGHT_ADJUSTMENT
#define ADC_CHANNEL  ADC_CHANNEL0
#define ADC_TRIGGERING_SOURCE   ADC_SINGLE_CONVERSION
#define ADC_PRESCALLER   ADC_PRE_128
#define ADC_TIMEOUT      50000

#endif /* ADC_CONFIG_H_ */
