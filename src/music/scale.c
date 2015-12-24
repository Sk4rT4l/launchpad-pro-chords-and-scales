/*
 * scale.c
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#include "music/scale.h"

ScaleType current_scale_type = SCALE_MAJOR;
Scale scale_list[SCALE_LIST_SIZE];

void scale_list_init()
{
	Scale scale_major = {
		8,
		{1,0,1,0,1,1,0,1,0,1,0,1},
		{0,2,4,5,7,9,11}
	};
	scale_list[SCALE_MAJOR] = scale_major;
	Scale scale_minor = {
		8,
		{1,0,1,1,0,1,0,1,1,0,1,0},
		{0,2,3,5,7,8,10}
	};
	scale_list[SCALE_MINOR] = scale_minor;
	Scale scale_harmonic_minor = {
		8,
		{1,0,1,1,0,1,0,1,1,0,0,1},
		{0,2,3,5,7,8,11}
	};
	scale_list[SCALE_HARMONIC_MINOR] = scale_harmonic_minor;
	Scale scale_melodic_minor = {
		8,
		{1,0,1,1,0,1,0,1,0,1,0,1},
		{0,2,3,5,7,9,11}
	};
	scale_list[SCALE_MELODIC_MINOR] = scale_melodic_minor;
	Scale scale_ionian = {
		8,
		{1,0,1,0,1,1,0,1,0,1,0,1},
		{0,2,4,5,7,9,11}
	};
	scale_list[SCALE_IONIAN] = scale_ionian;
	Scale scale_dorian = {
		8,
		{1,0,1,1,0,1,0,1,0,1,1,0},
		{0,2,3,5,7,9,10}
	};
	scale_list[SCALE_DORIAN] = scale_dorian;
}
