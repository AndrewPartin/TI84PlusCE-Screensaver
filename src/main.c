#include <graphx.h>
#include <keypadc.h>
#include <sys/util.h>

#include "gfx/gfx.h"

#define X_MAX (320 - troll_width)
#define Y_MAX (240 - troll_height)

int main(void) {

  uint16_t x = randInt(0, X_MAX), y = randInt(0, Y_MAX);
  uint16_t dir[2] = {1, 1};

  gfx_Begin();
  gfx_SetDrawBuffer();

  gfx_SetPalette(global_palette, sizeof(global_palette), 0);
  gfx_FillScreen(2);
  gfx_SetTransparentColor(0);

  gfx_sprite_t *troll_redraw = gfx_MallocSprite(troll_width, troll_height);
  gfx_GetSprite(troll_redraw, x, y);

  do {

    gfx_Sprite(troll_redraw, x, y);

    if (x == X_MAX || x == 0) {
      dir[0] = -dir[0];
    }
    if (y == Y_MAX || y == 0) {
      dir[1] = -dir[1];
    }

    x += dir[0];
    y += dir[1];

    gfx_TransparentSprite_NoClip(troll, x, y);

    gfx_BlitBuffer();

  } while (kb_Data[6] != kb_Clear);

  gfx_End();

  return 0;
}
