/*
 * layout.c
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#include "utils/layout.h"

// Initializing variables
u8 pad_notes[GRID_SIZE][GRID_SIZE];
ScaleType pad_scales[GRID_SIZE][GRID_SIZE];
PadCoordinate pad_coordinates[BT_LAST];
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

void layout_initialize_pad_scales(){
	u8 index = 0;

	for (int y = 0; y < GRID_SIZE; y++){
		for (int x = 0; x < GRID_SIZE; x++){
			pad_scales[y][x] = (int)index;
//			hal_send_midi(USBMIDI,NOTEON,(u8)y,index);
//			hal_send_midi(USBMIDI,NOTEON,(u8)x,index);
//			hal_send_midi(USBMIDI,NOTEOFF,(u8)y,index);
//			hal_send_midi(USBMIDI,NOTEOFF,(u8)x,index);
			index++;
		}
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
			Color color = aqua;
			if (scale_index == 0){
				color = fuchsia;
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
		color_button(pad_index, fuchsia);
		pad_index++;
		if (i != 0 && i % 8 == 0){
			pad_index += 2;
		}
	}
}

/**
 * Setting the current scale
 */
void layout_set_scale(u8 index){
	hal_send_midi(USBMIDI,NOTEON,index,0);
	hal_send_midi(USBMIDI,NOTEOFF,index,0);
	PadCoordinate coord = pad_coordinates[index];
	ScaleType pad_scale = pad_scales[coord.y][coord.x];
	hal_send_midi(USBMIDI,NOTEON,(u8)pad_scale,0);
	hal_send_midi(USBMIDI,NOTEOFF,(u8)pad_scale,0);
	hal_send_midi(USBMIDI,NOTEON,(u8)SCALE_MINOR,0);
	hal_send_midi(USBMIDI,NOTEOFF,(u8)SCALE_MINOR,0);
//	if (pad_scale <= SCALE_LIST_SIZE){
		current_scale_type = pad_scale;
//	}
}
