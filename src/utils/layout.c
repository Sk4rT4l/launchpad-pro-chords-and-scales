/*
 * layout.c
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#include "utils/layout.h"

// Initializing variables
u8 pad_notes[GRID_SIZE][GRID_SIZE];
PadCoordinate pad_coordinates[BT_LAST];
Layout current_layout = {DEFAULT_ROOT_NOTE,DEFAULT_OCTAVE};

/**
 * Initializing pad coordinates
 */
void layout_initialize_pad_coordinates(){
	u8 current_pad = BT_PAD_FIRST;

	for (int y = 0; y < GRID_SIZE; y++){
		for (int x = 0; x < GRID_SIZE; x++){
			PadCoordinate coord = {y, x};
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
			pad_notes[x][y] = root_note + index;
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
