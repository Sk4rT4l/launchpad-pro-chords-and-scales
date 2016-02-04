/*
 * buttons.c
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#include "utils/buttons.h"

/**
 * Clear all buttons
 */
void clear_buttons()
{
	for (u8 i = BT_FIRST; i <= BT_LAST; i++)
	{
		hal_plot_led(TYPEPAD, i, 0x00, 0x00, 0x00);
	}
}

/**
 * Clear only mode buttons (Session, Note, Device, User)
 */
void clear_mode_buttons()
{
	for (u8 i = BT_SESSION; i <= BT_USER; i++)
	{
		hal_plot_led(TYPEPAD, i, 0x00, 0x00, 0x00);
	}
}

/**
 * Clear only pads
 */
void clear_pads()
{
	for (u8 i = BT_PAD_FIRST; i <= BT_PAD_LAST; i++)
	{
		hal_plot_led(TYPEPAD, i, 0x00, 0x00, 0x00);
	}
}

/**
 * Clear selected button
 */
void clear_button(u8 index)
{
	hal_plot_led(TYPEPAD, index, 0x00, 0x00, 0x00);
}

/**
 * Color selected button with the specified color
 */
void color_button(u8 index, Color color)
{
	hal_plot_led(TYPEPAD, index, color.r, color.g, color.b);
}

/**
 * Clear the setup button
 */
void clear_setup_button()
{
	hal_plot_led(TYPESETUP, BT_SETUP, 0x00, 0x00, 0x00);
}

/**
 * Color the setup button
 */
void color_setup_button(Color color)
{
	hal_plot_led(TYPESETUP, BT_SETUP, color.r, color.g, color.b);
}

/**
 * Check if specified index is a pad
 */
int is_pad(u8 index){
	switch (index) {
		case BT_RECORD_ARM:
		case BT_TRACK_SELECT:
		case BT_MUTE:
		case BT_SOLO:
		case BT_VOLUME:
		case BT_PAN:
		case BT_SENDS:
		case BT_STOP_CLIP:
		case BT_RECORD:
		case BT_DOUBLE:
		case BT_DUPLICATE:
		case BT_QUANTISE:
		case BT_DELETE:
		case BT_UNDO:
		case BT_CLICK:
		case BT_SETUP:
		case BT_SHIFT:
		case BT_UP:
		case BT_DOWN:
		case BT_LEFT:
		case BT_RIGHT:
		case BT_SESSION:
		case BT_NOTE:
		case BT_DEVICE:
		case BT_USER:
		case BT_PLAY_1:
		case BT_PLAY_2:
		case BT_PLAY_3:
		case BT_PLAY_4:
		case BT_PLAY_5:
		case BT_PLAY_6:
		case BT_PLAY_7:
		case BT_PLAY_8:
			return 0;
			break;
		default:
			return 1;
			break;
	}
}
