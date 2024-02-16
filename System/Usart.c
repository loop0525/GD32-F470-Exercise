#include "usart.h"

int fputc(int ch ,FILE* f)
{
	usart_data_transmit(USART0, (uint8_t)ch);
	while(usart_flag_get(USART0, USART_FLAG_TBE) == RESET);
	return ch;
}


void Usart_Init()
{
	rcu_periph_clock_enable(RCU_GPIOA);
	rcu_periph_clock_enable(RCU_USART0);
	
	gpio_af_set(GPIOA, GPIO_AF_7, GPIO_PIN_9);
	gpio_af_set(GPIOA, GPIO_AF_7, GPIO_PIN_9);
	
	gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_9);
	gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);
	
	gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_10);
	gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_10);

	usart_deinit(USART0);
	usart_baudrate_set(USART0, 115200);
	usart_parity_config(USART0, USART_PM_NONE);
	usart_word_length_set(USART0, USART_WL_8BIT);
	usart_stop_bit_set(GPIOA, USART_STB_1BIT);
	
	usart_transmit_config(USART0, USART_TRANSMIT_ENABLE); 	// ??????
	usart_receive_config(USART0, USART_RECEIVE_ENABLE); 	// ??????
	
	//usart_interrupt_enable(USART0, USART_INT_RBNE); // ????????????????? 
	usart_interrupt_enable(USART0, USART_INT_IDLE); // DLE?????
	
	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
	nvic_irq_enable(USART0_IRQn, 2, 2);

	usart_enable(USART0);		
}



