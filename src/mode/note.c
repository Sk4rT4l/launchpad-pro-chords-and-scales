/*
 * note.c
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#include "mode/note.h"

// Initializing variables for differents note modes
int note_mode_solo_flag = 1;
int note_mode_hold_flag = 0;
int bt_shift_pressed = 0;
int bt_record_arm_pressed = 0;
Chord current_chord;
ChordType stored_chords[8] = { CHORD_NULL, CHORD_NULL, CHORD_NULL, CHORD_NULL, CHORD_NULL, CHORD_NULL, CHORD_NULL, CHORD_NULL };

/**
 * Initializing the note mode layout
 */
void note_mode_open(){
	clear_buttons();

	// Activating "Note" button
	color_button(BT_NOTE, white);

	// Activating solo mode
	if (note_mode_solo_flag){
		color_button(BT_SOLO, yellow);
	}

	// Initializing pad coordinates
	layout_initialize_pad_coordinates();

	// Initializing pad indexes
	layout_initialize_pad_indexes();

	// Initializing pad scales
	layout_initialize_pad_scales();

	// Recalculate pad notes
	layout_recalculate_pad_notes();

	// Activating buttons up and down for octaves
	layout_refresh_octave_buttons();

	// Drawing current scale
	layout_draw_scale();

	// Refresh stored chords
	note_mode_refresh_stored_chords();

	// Initializing midi channels
	layout_initialize_pad_midi_channels();
}

/**
 * Closing the note mode layout
 */
void note_mode_close(){
	clear_buttons();
}

void note_mode_setup_open(){
	note_mode_close();

	// Activating "Note" button
	color_button(BT_NOTE, white);	

	// Coloring the setup button
	color_setup_button(red);

	// Drawing a list of scales
	layout_list_scales();

	// Drawing a list of midi channels
	layout_list_midi_channels();
}

void note_mode_setup_close(){
	clear_setup_button();

	note_mode_open();
}

/**
 * Handling events
 */
void note_mode_handle(u8 index, u8 value){
	switch (index) {
		case BT_SHIFT:
			// Updating the bt_shift_pressed flag
			if (value > 0){
				bt_shift_pressed = 1;
				color_button(BT_SHIFT, yellow);
				color_button(BT_UP, yellow);
				color_button(BT_DOWN, yellow);
			} else {
				bt_shift_pressed = 0;
				clear_button(BT_SHIFT);
				layout_refresh_octave_buttons();
			}
			break;
		case BT_CLICK:
			// Toggling between hold mode and normal mode
			if (value > 0){
				if (!note_mode_hold_flag){
					note_mode_hold_flag = 1;
					color_button(BT_CLICK, orange);
				} else {
					note_mode_hold_flag = 0;
					clear_button(BT_CLICK);
				}
			}
			break;
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
			if (value > 0){
				if (bt_shift_pressed) {
					// Changing chord up
					chord_select_next();
					note_mode_refresh_stored_chords();
				} else {
					// Changing octave up
					if (current_layout.octave < 10){
						current_layout.octave++;
						current_layout.root_note += OCTAVE_LENGTH;
					}
					layout_recalculate_pad_notes();
					layout_refresh_octave_buttons();
				}
			}
			break;
		case BT_DOWN:
			if (value > 0){
				if (bt_shift_pressed){
					// Changing chord down
					chord_select_previous();
					note_mode_refresh_stored_chords();
				} else {
					// Changing octave down
					if (current_layout.octave > 0){
						current_layout.octave--;
						current_layout.root_note -= OCTAVE_LENGTH;
					}
					layout_recalculate_pad_notes();
					layout_refresh_octave_buttons();
				}
			}
			break;
		case BT_RECORD_ARM:
			if (value > 0){
				bt_record_arm_pressed = 1;
				color_button(BT_RECORD_ARM, yellow);
				color_button(BT_PLAY_1, yellow);
				color_button(BT_PLAY_2, yellow);
				color_button(BT_PLAY_3, yellow);
				color_button(BT_PLAY_4, yellow);
				color_button(BT_PLAY_5, yellow);
				color_button(BT_PLAY_6, yellow);
				color_button(BT_PLAY_7, yellow);
				color_button(BT_PLAY_8, yellow);
			} else {
				bt_record_arm_pressed = 0;
				clear_button(BT_RECORD_ARM);
				note_mode_refresh_stored_chords();
			}
			break;
		case BT_PLAY_1:
		case BT_PLAY_2:
		case BT_PLAY_3:
		case BT_PLAY_4:
		case BT_PLAY_5:
		case BT_PLAY_6:
		case BT_PLAY_7:
		case BT_PLAY_8:
			if (value > 0){
				if (bt_record_arm_pressed){
					// Storing the current chordtype
					stored_chords[((index - BT_PLAY_1) / 10)] = current_chord_type;
					note_mode_refresh_stored_chords();
				} else {
					if (stored_chords[((index - BT_PLAY_1) / 10)] != CHORD_NULL) {
						current_chord_type = stored_chords[((index - BT_PLAY_1) / 10)];
						current_chord = chord_list[current_chord_type];
						note_mode_refresh_stored_chords();
					}
				}
			}
			break;
		default:
			// Handling pad events
			if (is_pad(index)){
				if (note_mode_solo_flag){
					// Send only one note
					if (value > 0){
						// Send midi note on
						midi_send_note(index, value);
						color_button(index, chartreuse);
					} else {
						if (!note_mode_hold_flag){
							// Send midi note off if hold flag is off
							midi_stop_note(index, value);
							clear_button(index);
							layout_draw_scale();
						}
					}
				} else {
					Chord chord = chord_list[current_chord_type];
					current_chord = chord;
					// Send chord
					if (value > 0){
						midi_send_chord(index, value, chord);
						u8 pad_index = layout_get_pad_index(index);
						for (int i = 0; i < chord.size; i++){
							u8 bt_index = layout_get_pad_button(pad_index + chord.offsets[i]);
							if (bt_index >= 0){
								color_button(bt_index, chartreuse);
							}
						}
					} else {
						if (!note_mode_hold_flag){
							// Send noteoff on chord if hold flag is off
							midi_stop_chord(index, value, chord);
							u8 pad_index = layout_get_pad_index(index);
							for (int i = 0; i < chord.size; i++){
								u8 bt_index = layout_get_pad_button(pad_index + chord.offsets[i]);
								if (bt_index >= 0){
									clear_button(bt_index);
								}
							}
							layout_draw_scale();
						}
					}
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
			if (is_pad(index)){
				if (index >= BT_FIRST_MIDI_CHANNEL && index <= BT_LAST_MIDI_CHANNEL){
					// midi channel selection
					layout_set_midi_channel(index);
				} else {
					// scale selection
					layout_set_scale(index);
				}
				layout_list_scales();
				layout_list_midi_channels();
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
		midi_send_chord_aftertouch(index, value, current_chord);
	}
}

/**
 * Refreshing the play buttons with stored chordtypes
 */
void note_mode_refresh_stored_chords(){
	u8 start_index = BT_PLAY_1;
	for (int i = 0; i < 8; i++){
		if (stored_chords[i] != CHORD_NULL){
			if (stored_chords[i] != current_chord_type){
				color_button((start_index + (10 * i)), olive_green1);
			} else {
				color_button((start_index + (10 * i)), green);
			}
		} else {
			clear_button((start_index + (10 * i)));
		}
	}
}
