[PayPal.Me Donate](https://paypal.me/AvanVught?locale.x=nl_NL)
# GD32F107RC Bootloader TFTP

This bootloader will install your application by means of the TFTP protocol. There is no need to change your application code. 
Per default DHCP is used for obtaining the ip-address.

The bootloader is active during reset of the board:

* Or when the `KEY_BOOTLOADER_TFTP_GPIO_PINx` is pressed. Which is defined in file `lib-gd32/include/board/gd32f107r.h`. 
	
		#define KEY3_PINx						GPIO_PIN_11
		#define KEY3_GPIOx						GPIOA
		#define KEY3_RCU_GPIOx					RCU_GPIOA
		
		#define KEY_BOOTLOADER_TFTP_GPIO_PINx	KEY3_PINx
		#define KEY_BOOTLOADER_TFTP_GPIOx		KEY3_GPIOx
		#define KEY_BOOTLOADER_TFTP_RCU_GPIOx	KEY3_RCU_GPIOx

* Or when `bkp_data_read(BKP_DATA_1) == 0xA5A5`. This is set in your application by means of human readable UDP messages. See for more information: [https://www.gd32-dmx.org/bootloader.html](https://www.gd32-dmx.org/bootloader.html). There is also a sample Java UI application available for working with the UDP messages: [https://github.com/vanvught/GD32F-Firmware-Update-UI](https://github.com/vanvught/GD32F-Firmware-Update-UI)

Otherwise the bootloader will directly jump to your application. With the snippet: 

	    	// 8. Call the reset handler
	    	const uint32_t* reset_p = (uint32_t *)(FLASH_BASE + OFFSET_UIMAGE + 4);
	    	asm volatile ("bx %0;" : : "r"(*reset_p));

The bootloader can be installed with the tools supplied by GigaDevice: [http://www.gd32mcu.com/en/download/7?kw=GD32F1](http://www.gd32mcu.com/en/download/7?kw=GD32F1)

The limitation for the firmware file to be uploaded is given by the RAM available. For example, the MCU on [https://github.com/vanvught/GD32FxxxR-dev-board](https://github.com/vanvught/GD32FxxxR-dev-board) is the [GD32F107RCT6](https://www.gigadevice.com/microcontroller/gd32f107rct6/). With the 96K RAM we have the firmware file size limit of 74K.

There are 2 places for this configuration:

File: `gd32f107rc_flash.ld`

	  __heap_size = DEFINED(__heap_size) ? __heap_size : 75K;
	  __stack_size = DEFINED(__stack_size) ? __stack_size : 1K;

File: `spiflashinstall.h`

	# if defined (BOARD_GD32F107R)
	#  define OFFSET_UIMAGE		0x007000		// 28K
	#  define FIRMWARE_MAX_SIZE (74 * 1024)		// 74K

The 1K difference is needed for other `new` (`malloc`) within the bootloader.

The change to be made in your build configuration is in the file `gd32f107rc_flash.ld`. 

	/* Specify the memory areas */
	MEMORY
	{
	  FLASH (rx)      : ORIGIN = 0x08007000, LENGTH = 74K
	  RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 96K
	}
	
The `FLASH ORIGIN` must match the `OFFSET_UIMAGE` from the bootloader file `spiflashinstall.h`

The code for the bootloader is a fork from [https://github.com/vanvught/rpidmx512](https://github.com/vanvught/rpidmx512). In order to reduce the memory footprint, some functions are not available.