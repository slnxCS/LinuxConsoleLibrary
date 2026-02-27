Please note: This library only supports console operation on Linux systems. It has not been tested on other systems.

Library functions:

1. void lc_clear(void) :
     This function clears the console.

2. void lc_goto(int x, int y) :
     This function moves the console cursor to a specified position.

3. void lc_hide_cursor(void) : 
     This function hides the cursor.

4. void lc_show_cursor(void) : 
     This function shows the cursor

5. void lc_set_color(lc_color fg, lc_color bg) : 
     This function sets the color

6. void lc_reset_color(void) : 
     This function restores color

7. void lc_raw_on(void) :
     This feature enables console control

8. void lc_raw_off(void) :
     This feature disables console control.

9. void lc_sleep_ms(long ms) : 
     This function turns off the console for a specified time.

10. int  lc_getch(void) :
     This function returns the key pressed, and if no key is pressed, then -1

11. int lc_get_console_width() : 
     This function returns the width of the console.

12. int lc_get_console_heigth() : 
     This function returns the height of the console.
