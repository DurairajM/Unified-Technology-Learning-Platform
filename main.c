#include "macros.h"
#include<ulk.h>

int main(void) PROGRAM_ENTRY;

struct PIXEL
{
	unsigned int x;
	unsigned int y;
};
extern struct PIXEL pixel;
extern struct PIXEL ulk_proc_touch_spi_enable(void);
extern struct PIXEL ulk_proc_touch_spi_poll(void);
extern void ulk_proc_touch_spi_disable(void);
int main()
{
	ulk_cpanel_printf("Select the PRODUCTS \n GREEN -PENDRIVE \n RED - BACKCASE\n BLUE -FLIPCOVER \n BLACK - TEMPER GLASS");
	ulk_fpga_7seg_led_enable();
	ulk_fpga_clcd_init();
				ulk_fpga_clcd_display_on();
			ulk_fpga_clcd_display_clear();
			ulk_fpga_clcd_cursor_home();

	int cg=0,cd=0,cn=0,cb=0,count=0,ig=0;
	int i=0,j=0,k,l=0, *address = 0x80500000;
	for(i=0;i<120;i++)
	{
for(j=0; j<160; j++)
{
			*(address+(i*320+j)) = 0xff0000;
}
	}
	for(i=120;i<240;i++)
		{
	for(j=0; j<160; j++)
	{
				*(address+(i*320+j)) = 0x00ff00;
	}
		}
	for(i=0;i<120;i++)
		{
	for(j=160; j<320; j++)
	{
				*(address+(i*320+j)) = 0x0000ff;
	}
		}

	for(i=120;i<240;i++)
		{
	for(j=160; j<320; j++)
	{
				*(address+(i*320+j)) = 0x000000;
	}
		}

	ulk_proc_touch_spi_enable();

while(ig<5)
{



	ulk_fpga_clcd_display_string("*****CHOOSE PRODUCTS");
	ulk_proc_delay(ULK_SEC(6));

	pixel=ulk_proc_touch_spi_poll();
	if (pixel.x<160 && pixel.y<120)
	{
			cg++;
		ulk_fpga_clcd_init();
			ulk_fpga_clcd_display_on();
			ulk_fpga_clcd_display_clear();
			ulk_fpga_clcd_cursor_home();
			ulk_fpga_clcd_display_string("PENDRIVE");

		        int count=500;

			ulk_fpga_7seg_led_write(180);


	}

	 if (pixel.x<160 && pixel.y>120)
	{
		 cd++;
	ulk_fpga_clcd_init();
		ulk_fpga_clcd_display_on();
		ulk_fpga_clcd_display_clear();
		ulk_fpga_clcd_cursor_home();
		ulk_fpga_clcd_display_string("BACKCASE");
		ulk_fpga_clcd_shift_left(4);
		ulk_fpga_clcd_shift_right(7);
			int count=600;
			ulk_fpga_7seg_led_write(count);




	}


	 if (pixel.x>160 && pixel.y>120)
	{
		 cb++;
	ulk_fpga_clcd_init();
		ulk_fpga_clcd_display_on();
		ulk_fpga_clcd_display_clear();
		ulk_fpga_clcd_cursor_home();
		ulk_fpga_clcd_display_string("FLIPCOVER");
		ulk_fpga_clcd_shift_left(4);
		ulk_fpga_clcd_shift_right(7);
		int count=400;
		ulk_fpga_7seg_led_write(count);





	}
	 if (pixel.x>160 && pixel.y<120)
	{
		 cn++;
	ulk_fpga_clcd_init();
		ulk_fpga_clcd_display_on();
		ulk_fpga_clcd_display_clear();
		ulk_fpga_clcd_cursor_home();
		ulk_fpga_clcd_display_string("TEMPER GLASS");
		ulk_fpga_clcd_shift_left(4);
		ulk_fpga_clcd_shift_right(7);
	    int count=550;
	    ulk_fpga_7seg_led_write(count);





	}


ig++;
}
if(cg>cd && cg>cn && cg>cb)
{
	ulk_fpga_clcd_display_on();
			ulk_fpga_clcd_display_clear();
			ulk_fpga_clcd_cursor_home();
			ulk_fpga_clcd_display_string("PRODUCT PRICE DISPLAYED");
			ulk_fpga_clcd_shift_left(4);
					ulk_fpga_clcd_shift_right(7);
}
if(cd>cg && cd>cn && cd>cb)
{
	ulk_fpga_clcd_display_on();
				ulk_fpga_clcd_display_clear();
				ulk_fpga_clcd_cursor_home();
				ulk_fpga_clcd_display_string("PRODUCT PRICE DISPLAYED");
				ulk_fpga_clcd_shift_left(4);
						ulk_fpga_clcd_shift_right(7);
}
if(cb>cg && cb>cn && cb>cd)
{
	ulk_fpga_clcd_display_on();
				ulk_fpga_clcd_display_clear();
				ulk_fpga_clcd_cursor_home();
				ulk_fpga_clcd_display_string("PRODUCT PRICE DISPLAYED");
				ulk_fpga_clcd_shift_left(4);
						ulk_fpga_clcd_shift_right(7);
}
if(cn>cb && cn>cd && cn>cg)
{
	ulk_fpga_clcd_display_on();
				ulk_fpga_clcd_display_clear();
				ulk_fpga_clcd_cursor_home();
				ulk_fpga_clcd_display_string("PRODUCT PRICE DISPLAYED");
				ulk_fpga_clcd_shift_left(4);
						ulk_fpga_clcd_shift_right(7);
}
return 0;
}
