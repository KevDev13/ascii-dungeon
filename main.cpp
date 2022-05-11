#include "BearLibTerminal.h"
#include "entt.hpp"

#include "vector.h"
#include "layers.h"

int main() {
  terminal_open();

  terminal_bkcolor(color_from_name("grey"));

  int x = 5;
  int y = 5;

  bool quit = false;
  while(!quit) {
    terminal_clear();
    terminal_color(color_from_name("green"));
    terminal_put(x, y, '@');
    terminal_refresh();
    int k = terminal_read();
    quit = k == TK_CLOSE;

    if(k == TK_W) {
      --y;
    } else if(k == TK_S) {
      ++y;
    } else if(k == TK_A) {
      --x;
    } else if(k == TK_D) {
      ++x;
    }
  }

  terminal_close();

  return 0;
}
