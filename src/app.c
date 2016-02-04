/******************************************************************************
 
 Copyright (c) 2015, Focusrite Audio Engineering Ltd.
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 * Neither the name of Focusrite Audio Engineering Ltd., nor the names of its
 contributors may be used to endorse or promote products derived from
 this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 *****************************************************************************/

//______________________________________________________________________________
//
// Headers
//______________________________________________________________________________

#include "app.h"
#include "mode/handler.h"
#include "music/chord.h"
#include "music/scale.h"
#include "utils/buttons.h"

//______________________________________________________________________________
//
// This is where the fun is!  Add your code to the callbacks below to define how
// your app behaves.
//______________________________________________________________________________

void app_surface_event(u8 type, u8 index, u8 value)
{
	switch (type)
	{
		case TYPEPAD:
		{
			if (index >= BT_SESSION && index <= BT_USER){
				change_current_mode(index);
			} else {
				mode_handle(index, value);
			}
		}
		break;

		case TYPESETUP:
		{
			mode_setup_toggle(index, value);
		}
		break;
	}
}

//______________________________________________________________________________

void app_midi_event(u8 port, u8 status, u8 d1, u8 d2)
{
}

//______________________________________________________________________________

void app_sysex_event(u8 port, u8 * data, u16 count)
{
}

//______________________________________________________________________________

void app_aftertouch_event(u8 index, u8 value)
{
	if (setup_mode_flag == 0){
		mode_aftertouch(index, value);
	}
}
	
//______________________________________________________________________________

void app_cable_event(u8 type, u8 value)
{
}

//______________________________________________________________________________


void app_timer_event()
{
}

//______________________________________________________________________________

void app_init()
{
	// Initializing scales
	scale_list_init();

	// Initializing chords
	chord_list_init();

	// Displaying "S" in blue
	hal_plot_led(TYPEPAD, 11, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 12, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 13, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 14, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 24, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 34, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 41, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 42, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 43, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 44, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 51, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 61, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 71, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 81, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 82, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 83, 0x00, 0x20, 0x3F);
	hal_plot_led(TYPEPAD, 84, 0x00, 0x20, 0x3F);

	// Displaying "k" in green
	hal_plot_led(TYPEPAD, 15, 0x20, 0x3F, 0x00);
	hal_plot_led(TYPEPAD, 18, 0x20, 0x3F, 0x00);
	hal_plot_led(TYPEPAD, 25, 0x20, 0x3F, 0x00);
	hal_plot_led(TYPEPAD, 27, 0x20, 0x3F, 0x00);
	hal_plot_led(TYPEPAD, 35, 0x20, 0x3F, 0x00);
	hal_plot_led(TYPEPAD, 36, 0x20, 0x3F, 0x00);
	hal_plot_led(TYPEPAD, 45, 0x20, 0x3F, 0x00);
	hal_plot_led(TYPEPAD, 55, 0x20, 0x3F, 0x00);
	hal_plot_led(TYPEPAD, 56, 0x20, 0x3F, 0x00);
	hal_plot_led(TYPEPAD, 65, 0x20, 0x3F, 0x00);
	hal_plot_led(TYPEPAD, 67, 0x20, 0x3F, 0x00);
	hal_plot_led(TYPEPAD, 75, 0x20, 0x3F, 0x00);
	hal_plot_led(TYPEPAD, 78, 0x20, 0x3F, 0x00);
}
