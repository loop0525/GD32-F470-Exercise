#include "hw_spi.h"

void HW_SPI_Init()
{
	rcu_periph_clock_enable(RCU_GPIOF);    // 使用F端口
	rcu_periph_clock_enable(RCU_SPI4);     // 使能SPI4
	//引脚复用
	gpio_af_set(GPIOF, GPIO_AF_5, GPIO_PIN_7);
	gpio_af_set(GPIOF, GPIO_AF_5, GPIO_PIN_8);
	gpio_af_set(GPIOF, GPIO_AF_5, GPIO_PIN_9);
	//引脚模式
	gpio_mode_set(GPIOF, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_7);
	gpio_mode_set(GPIOF, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_8);
	gpio_mode_set(GPIOF, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_9);
	//输出模式
	gpio_output_options_set(GPIOF, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_7);
	gpio_output_options_set(GPIOF, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_8);
	gpio_output_options_set(GPIOF, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);
		
	//开启CS引脚时钟
	rcu_periph_clock_enable(RCU_GPIOF);
	//配置CS引脚模式
	gpio_mode_set(GPIOF, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, GPIO_PIN_6);
	//配置CS输出模式
	gpio_output_options_set(GPIOF, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_6);
	//W25Q64不选中
	gpio_bit_write(GPIOF, GPIO_PIN_6, SET);
	
	
	//SPI参数定义结构体
	spi_parameter_struct spi_init_struct;
	spi_init_struct.trans_mode        = SPI_TRANSMODE_FULLDUPLEX; // 传输模式全双工
	spi_init_struct.device_mode       = SPI_MASTER;                // 配置为主机
	spi_init_struct.frame_size         = SPI_FRAMESIZE_8BIT;         // 8位数据
	spi_init_struct.clock_polarity_phase = SPI_CK_PL_LOW_PH_1EDGE;  //极性相位  模式0 时钟空闲为低，第一个边沿传输数据
	spi_init_struct.nss               = SPI_NSS_SOFT;              // 软件cs
	spi_init_struct.prescale           = SPI_PSC_2;                 //SPI时钟预调因数为2
	spi_init_struct.endian            = SPI_ENDIAN_MSB;           //高位在前
	//将参数填入SPI4
	spi_init(SPI4, &spi_init_struct);
	//使能SPI
	spi_enable(SPI4);
}


uint8_t HW_SPI_Exchange(uint8_t dat)
{
    //等待发送缓冲区为空
    while(RESET == spi_i2s_flag_get(SPI4,  SPI_FLAG_TBE) );
    //通过SPI4发送一个字节数据 
    spi_i2s_data_transmit(SPI4, dat);
 
    //等待接收缓冲区不空标志
    while(RESET == spi_i2s_flag_get(SPI4,  SPI_FLAG_RBNE) );
    //读取并返回在SPI4读取到的单字节数据
    return spi_i2s_data_receive(SPI4);
}

void HW_SPI_Test()
{
	uint8_t rec, rec1, rec2; 
	HW_SPI_Init();
	
	gpio_bit_reset(GPIOF, GPIO_PIN_6);
	
	rec = HW_SPI_Exchange(0x9f);
	rec1 = HW_SPI_Exchange(0x00);
	rec2 = HW_SPI_Exchange(0x00);
	
	gpio_bit_set(GPIOF, GPIO_PIN_6);
	
	printf("接收数据:%X \n", rec);
	printf("接收制造商ID:%X \n", rec1);
	printf("接收设备ID:%X \n", rec2);
}

