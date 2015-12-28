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

	// Initializing pad scales
	layout_initialize_pad_scales();

	// Recalculate pad notes
	layout_recalculate_pad_notes();

	// Activating buttons up and down for octaves
	layout_refresh_octave_buttons();

	// Drawing current scale
	layout_draw_scale();
}

/**
 * Closing the note mode layout
 */
void note_mode_close(){
	clear_buttons();
}

void note_mode_setup_open(){
	clear_pads();

	// Drawing a list of scales
	layout_list_scales();
}

void note_mode_setup_close(){
	note_mode_open();
}

/**
 * Handling events
 */
void note_mode_handle(u8 index, u8 value){
	switch (index) {
		case BT_SOLO:
			// Toggling between solo and chord mode
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
		case BT_UP:
			// Changing octave up
			if (value > 0){
				if (current_layout.octave < 10){
					current_layout.octave++;
					current_layout.root_note += OCTAVE_LENGTH;
				}
				layout_recalculate_pad_notes();
				layout_refresh_octave_buttons();
			}
			break;
		case BT_DOWN:
			// Changing octave down
			if (value > 0){
				if (current_layout.octave > 0){
					current_layout.octave--;
					current_layout.root_note -= OCTAVE_LENGTH;
				}
				layout_recalculate_pad_notes();
				layout_refresh_octave_buttons();
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
						layout_draw_scale();
					}
				} else {
					// Send chord
				}
			}
			break;
	}
}

/**
 * Handling setup events
 */
void note_mode_setup_handle(u8 index, u8 value){
	switch (index) {
		case BT_SHIFT:

			break;
		default:
			if (index >= BT_PAD_FIRST && index <= BT_PAD_LAST){
				layout_set_scale(index);
			}
			break;
	}
}

/**
 * Handling aftertouch events
 */
void note_mode_aftertouch(u8 index, u8 value){
	// TODO Disable aftertouch if setup mode is on
	if (note_mode_solo_flag){
		midi_send_aftertouch(index, value);
	} else {

	}
}
