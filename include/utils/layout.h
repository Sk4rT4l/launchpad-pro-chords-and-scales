/*
 * layout.h
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#ifndef LAYOUT_H_
#define LAYOUT_H_

#include "app.h"
#include "music/scale.h"
#include "utils/buttons.h"

#define GRID_SIZE 8
#define DEFAULT_OCTAVE 3
#define DEFAULT_ROOT_NOTE 36

typedef struct {
	int x;
	int y;
} PadCoordinate;

typedef struct {
	// 0-127
	u8 root_note;
	// 0-10
	u8 octave;
} Layout;

extern Layout current_layout;

void layout_initialize_pad_coordinates();
void layout_initialize_pad_indexes();
u8 layout_get_pad_index(u8 bt_index);
u8 layout_get_pad_button(u8 index);
void layout_recalculate_pad_notes();
void layout_initialize_pad_scales();
u8 layout_get_midi_note(u8 index);
void layout_draw_scale();
void layout_refresh_octave_buttons();
void layout_list_scales();
void layout_set_scale(u8 index);

#endif /* LAYOUT_H_ */
