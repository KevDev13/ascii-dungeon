
#include <cstring>

#include "BearLibTerminal.h"
#include "entt.hpp"

#include "vector.h"
#include "layers.h"

int main() {
  terminal_open();

  terminal_bkcolor(color_from_name("black"));

  const char* winsize = terminal_get("window.size");
  char str_winwidth[3];
  memcpy(str_winwidth, &winsize[0], 2);
  str_winwidth[2] = '\0';
  char str_winheight[3];
  memcpy(str_winheight, &winsize[3], 2);
  str_winheight[2] = '\0';

  int x = 5;
  int y = 5;

  bool quit = false;
  while(!quit) {
    terminal_clear();
    terminal_color(color_from_name("green"));
    terminal_put(x, y, 1);
    terminal_refresh();
    int k = terminal_read();
    quit = k == TK_CLOSE;

    if(k == TK_W) {
      if(y > 0) {
        --y;
      }
    } else if(k == TK_S) {
      if(y < 49) {
        ++y;
      }
    } else if(k == TK_A) {
      if(x > 0) {
        --x;
      }
    } else if(k == TK_D) {
      if(x < 79) {
        ++x;
      }
    }
  }

  terminal_close();

  return 0;
}
