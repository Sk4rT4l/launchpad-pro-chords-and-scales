/*
 * handler.c
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#include "mode/handler.h"

// Initializing defaults variables
Mode current_mode;
int setup_mode_flag = 0;

/**
 * Handling mode buttons pressure
 */
void change_current_mode(u8 index){
	// Deactivating current mode if different from selected
	switch (current_mode) {
		case MODE_NOTE:
			if (index != BT_NOTE) {
				note_mode_close();
			}
			break;
		default:
			break;
	}

	// Activating selected mode
	switch (index) {
		case BT_NOTE:
			if (current_mode != MODE_NOTE){
				current_mode = MODE_NOTE;
				note_mode_open();
			}
			break;
		default:
			current_mode = MODE_DISABLED;
			break;
	}
}

/**
 * Dispatching the surface event to the current mode
 */
void mode_handle(u8 index, u8 value){
	switch (current_mode) {
		case MODE_NOTE:
			note_mode_handle(index, value);
			break;
		default:
			break;
	}
}

/**
 * Dispatching the aftertouch event to the current mode
 */
void mode_aftertouch(u8 index, u8 value){
	switch (current_mode) {
		case MODE_NOTE:
			note_mode_aftertouch(index, value);
			break;
		default:
			break;
	}
}
