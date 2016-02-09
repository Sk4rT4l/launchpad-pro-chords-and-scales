/*
 * layout.c
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#include "utils/layout.h"

// Initializing variables
u8 pad_notes[GRID_SIZE][GRID_SIZE];
// TODO Change pad_scales size to SCALE_LIST_SIZE
ScaleType pad_scales[GRID_SIZE][GRID_SIZE];
int pad_midi_channels[16];
PadCoordinate pad_coordinates[BT_LAST];
u8 pad_indexes[GRID_SIZE*GRID_SIZE];
Layout current_layout = {DEFAULT_ROOT_NOTE,DEFAULT_OCTAVE};

/**
 * Initializing pad coordinates
 */
void layout_initialize_pad_coordinates(){
	u8 current_pad = BT_PAD_FIRST;

	for (int y = 0; y < GRID_SIZE; y++){
		for (int x = 0; x < GRID_SIZE; x++){
			PadCoordinate coord = {.y = y, .x = x};
			pad_coordinates[current_pad] = coord;
			current_pad++;
		}
		current_pad += 2;
	}
}

/**
 * Initialize pad indexes
 */
void layout_initialize_pad_indexes(){
	u8 current_pad = BT_PAD_FIRST;
	u8 index = 0;

	for (int y = 0; y < GRID_SIZE; y++){
		for (int x = 0; x < GRID_SIZE; x++){
			pad_indexes[index] = current_pad;
			index++;
			current_pad++;
		}
		current_pad += 2;
	}
}

/**
 * Retrieve the pad index in pad_indexes array
 */
u8 layout_get_pad_index(u8 bt_index){
	u8 pad_index = -1;

	for (int i = 0; i < (GRID_SIZE*GRID_SIZE); i++){
		if (pad_indexes[i] == bt_index){
			pad_index = i;
			break;
		}
	}

	return pad_index;
}

/**
 * Get the button index in the pad_indexes array
 */
u8 layout_get_pad_button(u8 index){
	u8 bt_index = -1;
	
	if (index < (GRID_SIZE*GRID_SIZE)){
		bt_index = pad_indexes[index];
	}
	
	return bt_index;
}

/**
 * Recalculating pad notes
 */
void layout_recalculate_pad_notes(){
	u8 root_note = current_layout.root_note;
	u8 index = 0;

	for (int y = 0; y < GRID_SIZE; y++){
		for (int x = 0; x < GRID_SIZE; x++){
			pad_notes[y][x] = root_note + index;
			index++;
		}
	}
}

/**
 * Initializing array containing pad scales refering to coordinates
 */
void layout_initialize_pad_scales(){
	u8 index = 0;

	for (int y = 0; y < GRID_SIZE; y++){
		for (int x = 0; x < GRID_SIZE; x++){
			pad_scales[y][x] = (int)index;
			// DEBUG
//			hal_send_midi(USBMIDI,NOTEON,(u8)y,index);
//			hal_send_midi(USBMIDI,NOTEON,(u8)x,index);
//			hal_send_midi(USBMIDI,NOTEOFF,(u8)y,index);
//			hal_send_midi(USBMIDI,NOTEOFF,(u8)x,index);
			index++;
			if (index == SCALE_LIST_SIZE){
				break;
			}
		}
		if (index == SCALE_LIST_SIZE){
			break;
		}
	}
}

/**
 * Initializing array containing midi channels
 */
void layout_initialize_pad_midi_channels(){
	for (int i = 0; i < 16; i++){
		pad_midi_channels[i] = i + 1;
	}
}

/**
 * Getting midi note for selected pad
 */
u8 layout_get_midi_note(u8 index){
	PadCoordinate coord = pad_coordinates[index];
	return pad_notes[coord.y][coord.x];
}

/**
 * Drawing current scale
 */
void layout_draw_scale()
{
	int index = BT_PAD_FIRST;
	Scale current_scale = scale_list[current_scale_type];
	int scale_index = 0;

	for (int y = 0; y < GRID_SIZE; y++)
	{
		for (int x = 0; x < GRID_SIZE; x++)
		{
			Color color = aquamarine;
			if (scale_index == 0){
				color = orchid;
			}

			if (current_scale.notes[scale_index]) {
				color_button(index, color);
			}

			index++;
			scale_index++;
			if (scale_index == OCTAVE_LENGTH) {
				scale_index = 0;
			}
		}
		index += 2;
	}
}

/**
 * Refreshing buttons for current octave
 */
void layout_refresh_octave_buttons(){
	if (current_layout.octave > DEFAULT_OCTAVE){
		color_button(BT_UP,blue);
		color_button(BT_DOWN,navy);
	} else if (current_layout.octave < DEFAULT_OCTAVE){
		color_button(BT_UP,navy);
		color_button(BT_DOWN,blue);
	} else {
		color_button(BT_UP,navy);
		color_button(BT_DOWN,navy);
	}
}

/**
 * Drawing a list of scales
 */
void layout_list_scales(){
	u8 pad_index = BT_PAD_FIRST;
	for (int i = 0; i < SCALE_LIST_SIZE; i++){
		if (i != 0 && (i % 8 == 0)){
			pad_index += 2;
		}
		if (i != current_scale_type){
			color_button(pad_index, orchid);
		} else {
			// current_scale
			color_button(pad_index, fuchsia);
		}
		pad_index++;
	}
}

/**
 * Setting the current scale
 */
void layout_set_scale(u8 index){
	// DEBUG
//	hal_send_midi(USBMIDI,NOTEON,index,0);
//	hal_send_midi(USBMIDI,NOTEOFF,index,0);
	PadCoordinate coord = pad_coordinates[index];
	ScaleType pad_scale = pad_scales[coord.y][coord.x];
	// DEBUG
//	hal_send_midi(USBMIDI,NOTEON,(u8)pad_scale,0);
//	hal_send_midi(USBMIDI,NOTEOFF,(u8)pad_scale,0);
//	hal_send_midi(USBMIDI,NOTEON,(u8)SCALE_MINOR,0);
//	hal_send_midi(USBMIDI,NOTEOFF,(u8)SCALE_MINOR,0);
	if (pad_scale <= SCALE_LIST_SIZE){
		current_scale_type = pad_scale;
	}
}

/**
 * Drawing a list of all midi channels
 */
void layout_list_midi_channels(){
	u8 pad_index = 71;

	for (int i = 1; i <= 16; i++){
		if (!is_pad(pad_index)){
			pad_index += 2;
		}
		if (i == current_midi_channel){
			color_button(pad_index, green);
		} else {
			color_button(pad_index, olive_green1);
		}
		pad_index++;
	}
}

/**
 * Setting the current midi channel
 */
void layout_set_midi_channel(u8 index){
	u8 array_index = index - 71;
	if (index >= 81){
		array_index = index - 71 - 2;
	}
	current_midi_channel = pad_midi_channels[array_index];
}