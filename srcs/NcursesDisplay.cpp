#include <iostream>
#include <vector>
#include <list>
#include <ft_gkrellm.hpp>
#include "NcursesDisplay.hpp"

bool    NcursesDisplay::_VERBOSE = true;

// ***************************************************
// ***************** MISC FUNCTIONS ******************
// ***************************************************

void    switchDefaultColors(bool save) {
    static short black[3];
    static short red[3];
    static short green[3];
    static short yellow[3];
    static short blue[3];
    static short magenta[3];
    static short cyan[3];
    static short white[3];

    if (save) {
        color_content(COLOR_BLACK, &black[0], &black[1], &black[2]);
        color_content(COLOR_RED, &red[0], &red[1], &red[2]);
        color_content(COLOR_GREEN, &green[0], &green[1], &green[2]);
        color_content(COLOR_YELLOW, &yellow[0], &yellow[1], &yellow[2]);
        color_content(COLOR_BLUE, &blue[0], &blue[1], &blue[2]);
        color_content(COLOR_MAGENTA, &magenta[0], &magenta[1], &magenta[2]);
        color_content(COLOR_CYAN, &cyan[0], &cyan[1], &cyan[2]);
        color_content(COLOR_WHITE, &white[0], &white[1], &white[2]);
    }
    else {
        init_color(COLOR_BLACK, black[0], black[1], black[2]);
        init_color(COLOR_RED, red[0], red[1], red[2]);
        init_color(COLOR_GREEN, green[0], green[1], green[2]);
        init_color(COLOR_YELLOW, yellow[0], yellow[1], yellow[2]);
        init_color(COLOR_BLUE, blue[0], blue[1], blue[2]);
        init_color(COLOR_MAGENTA, magenta[0], magenta[1], magenta[2]);
        init_color(COLOR_CYAN, cyan[0], cyan[1], cyan[2]);
        init_color(COLOR_WHITE, white[0], white[1], white[2]);
    }
}

void    initColors() {
    // init default color - TODO: later create different games color profiles
    init_color(COLOR_BLACK, 0, 0, 0);
    init_color(COLOR_RED, 700, 0, 0);
    init_color(COLOR_GREEN, 0, 0, 700);
    init_color(COLOR_YELLOW, 700, 700, 0);
    init_color(COLOR_BLUE, 0, 0, 700);
    init_color(COLOR_MAGENTA, 700, 0, 700);
    init_color(COLOR_CYAN, 0, 400, 700);
    init_color(COLOR_WHITE, 700, 700, 700);
}

void    setColors(void) {
    // color support is required for this game
    if (!can_change_color()) {
        printw("ERROR: Your terminal can't change colors");
        getch();
        endwin();
        exit(1);
    }
    if (has_colors() == FALSE) {
        printw("ERROR: Your terminal does not support color\n");
        getch();
        endwin();
        exit(1);
    }

    start_color();
    switchDefaultColors(true);
    initColors();

    // init pairs
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_MAGENTA);

}

// ***************************************************
// ***************** CLASS BODY **********************
// ***************************************************

// constructor and destructor
NcursesDisplay::NcursesDisplay(void) : IMonitorDisplay() {
    if (NcursesDisplay::_VERBOSE) {
        std::cout << "\033[35mNcursesDisplay default constructor\033[0m" << std::endl;
    }
}

NcursesDisplay::NcursesDisplay(NcursesDisplay const &src) {
    *this = src;

    if (NcursesDisplay::_VERBOSE) {
        std::cout << "\033[33mNcursesDisplay Copy constructor\033[0m" << std::endl;
    }
}

NcursesDisplay::~NcursesDisplay(void) {
    if (NcursesDisplay::_VERBOSE) {
        std::cout << "\033[31mNcursesDisplay Destructor\033[0m" << std::endl;
    }
}

//setters and getters

// overload
NcursesDisplay &NcursesDisplay::operator=(NcursesDisplay const &rhs) {
    (void) rhs;
    return *this;
}

std::ostream    &operator<<(std::ostream &o, NcursesDisplay const &i) {
    o << "hello world!";
    (void) i;
    return o;
}

// exceptions

// methods

void    NcursesDisplay::init(void) {
    initscr();
    raw();
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    setColors();
    refresh();
}

void    NcursesDisplay::restore(void) {
    switchDefaultColors(false);
    endwin();
}

void    NcursesDisplay::displayWindow(Position p, std::string title, int color) {
    (void) color;
    (void) p;
    (void) title;
}

void    NcursesDisplay::displayText(Position p, std::string const &text, int color) {
    attron(COLOR_PAIR(color));
    mvprintw(p.getY(), p.getX(), text.c_str());
    attroff(COLOR_PAIR(color));
}

void    NcursesDisplay::displayUnit(Position p, std::string const &text, std::string const &unit, int color) {
    std::string str;

    str = text + " " + unit;
    attron(COLOR_PAIR(color));
    mvprintw(p.getY(), p.getX(), str.c_str());
    attroff(COLOR_PAIR(color));
}

void    NcursesDisplay::displayBarChart(Position p, std::vector<int> const &data) {
    (void) p;
    (void) data;
}

void    NcursesDisplay::displayCurve(Position p, std::vector<int> const &data, int color) {
    (void) color;
    (void) p;
    (void) data;
}

void    NcursesDisplay::displaySprite(Position p, std::string const *sprite, int h, int w, int color) {
    (void) color;
    (void) p;
    (void) sprite;
    (void) h;
    (void) w;
}

void    NcursesDisplay::initWindows(std::list<IMonitorModule *> const &windows) {
    (void) windows;
}

void    NcursesDisplay::reorderWindows(std::list<IMonitorModule *> windows) {
    (void) windows;
}

void    NcursesDisplay::hideWindow(std::list<IMonitorModule *>::const_iterator at) {
    (void) at;
}
void    NcursesDisplay::showWindow(std::list<IMonitorModule *>::const_iterator at) {
    (void) at;
}

void    NcursesDisplay::changeSkin(std::string const &skin) {
    (void) skin;
}
