#include <ft_gkrellm.hpp>
#include "NWindow.hpp"

NWindow::NWindow(int const x, int const y, int const h, int const w, int const color) : _x(x), _y(y), _h(h), _w(w), _color(color) {
    WINDOW	*win;

    win = newwin(this->_h, this->_w, this->_y, this->_x);

    wattron(win, COLOR_PAIR(color));
    wborder(win, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    wrefresh(win);
    wattroff(win, COLOR_PAIR(color));

    this->_window = win;
}

NWindow::NWindow(NWindow const & src) {
    *this = src;
}

NWindow::~NWindow( void ) {
    delwin(this->_window);
   // endwin();
}

NWindow &			NWindow::operator=(NWindow const & rhs) {
    this->_x = rhs.getX();
    this->_y = rhs.getY();
    this->_h = rhs.getH();
    this->_w = rhs.getW();
    this->_color = rhs.getColor();

    return *this;
}


void				NWindow::refreshWindow(void) {
    refresh();
}

int					NWindow::getX(void) const {
    return this->_x;
}

int					NWindow::getY(void) const {
    return this->_y;
}

int					NWindow::getH(void) const {
    return this->_h;
}

int					NWindow::getW(void) const {
    return this->_w;
}

int					NWindow::getColor(void) const {
    return this->_color;
}

WINDOW 				*NWindow::getWindow(void) const {
    return this->_window;
}

