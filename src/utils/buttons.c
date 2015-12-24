/*
 * buttons.c
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#include "utils/buttons.h"

void clear_buttons()
{
	for (u8 i = BT_FIRST; i <= BT_LAST; i++)
	{
		hal_plot_led(TYPEPAD, i, 0x00, 0x00, 0x00);
	}
}

void clear_mode_buttons()
{
	for (u8 i = BT_SESSION; i <= BT_USER; i++)
	{
		hal_plot_led(TYPEPAD, i, 0x00, 0x00, 0x00);
	}
}

void clear_pads()
{
	for (u8 i = BT_PAD_FIRST; i <= BT_PAD_LAST; i++)
	{
		hal_plot_led(TYPEPAD, i, 0x00, 0x00, 0x00);
	}
}

void clear_button(u8 index)
{
	hal_plot_led(TYPEPAD, index, 0x00, 0x00, 0x00);
}

void color_button(u8 index, Color color)
{
	hal_plot_led(TYPEPAD, index, color.r, color.g, color.b);
}
