/*
 * note.c
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#include "mode/note.h"

// Initializing variables for differents note modes
int note_mode_solo_flag = 1;

/**
 * Initializing the note mode layout
 */
void note_mode_open(){
	clear_pads();

	// Activating "Note" button
	color_button(BT_NOTE, green);

	// Activating solo mode
	color_button(BT_SOLO, yellow);

	// Initializing pad coordinates
	layout_initialize_pad_coordinates();

	// Recalculate pad notes
	layout_recalculate_pad_notes();
}

/**
 * Closing the note mode layout
 */
void note_mode_close(){
	clear_buttons();
}

/**
 * Handling events
 */
void note_mode_handle(u8 index, u8 value){
	switch (index) {
		case BT_SOLO:
			if (value > 0){
				if (note_mode_solo_flag) {
					// Toggle chord mode on
					note_mode_solo_flag = 0;
					clear_button(BT_SOLO);
				} else {
					// Toggle solo mode on
					note_mode_solo_flag = 1;
					color_button(BT_SOLO, yellow);
				}
			}
			break;
		default:
			// Handling pad events
			if (index >= BT_PAD_FIRST && index <= BT_PAD_LAST){
				if (note_mode_solo_flag){
					// Send only one note
					if (value > 0){
						// Send midi note on
						midi_send_note(index, value);
						color_button(index, blue);
					} else {
						// Send midi note off
						midi_stop_note(index, value);
						clear_button(index);
					}
				} else {
					// Send chord
				}
			}
			break;
	}
}

/**
 * Handling aftertouch events
 */
void note_mode_aftertouch(u8 index, u8 value){
	if (note_mode_solo_flag){
		midi_send_aftertouch(index, value);
	} else {

	}
}
