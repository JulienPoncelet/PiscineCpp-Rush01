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
    init_color(COLOR_BLACK, 0, 0, 100);
    init_color(COLOR_RED, 700, 0, 0);
    init_color(COLOR_GREEN, 0, 0, 700);
    init_color(COLOR_YELLOW, 700, 700, 0);
    init_color(COLOR_BLUE, 0, 0, 900);
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
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_CYAN);

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

// HERE ARE MY BRICKS

void    NcursesDisplay::init(void) {
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    setColors();
    nodelay(stdscr, true);
    refresh();
}

void    NcursesDisplay::restore(void) {
    switchDefaultColors(false);
    endwin();
}



void    NcursesDisplay::displayText(Position p, std::string const &text, int color) {
    attron(COLOR_PAIR(color));
    mvprintw(p.getY(), p.getX(), text.c_str());
    attroff(COLOR_PAIR(color));
}
void    NcursesDisplay::displayText(NWindow *window, Position p, std::string const &text, int color) {
    WINDOW  *win = window->getWindow();

    wattron(win, COLOR_PAIR(color));
    mvwprintw(win, p.getY(), p.getX(), text.c_str());
    wattroff(win, COLOR_PAIR(color));
}

void    NcursesDisplay::displayUnit(Position p, std::string const &text, std::string const &unit, int color) {
    std::string str;

    str = text + " " + unit;
    attron(COLOR_PAIR(color));
    mvprintw(p.getY(), p.getX(), str.c_str());
    attroff(COLOR_PAIR(color));
}
void    NcursesDisplay::displayUnit(NWindow *window, Position p, std::string const &text, std::string const &unit, int color) {
    std::string str;
    WINDOW  *win = window->getWindow();

    str = text + " " + unit;
    wattron(win, COLOR_PAIR(color));
    wattron(win, COLOR_PAIR(color));
    mvwprintw(win, p.getY(), p.getX(), str.c_str());
    wattroff(win, COLOR_PAIR(color));
}

void    NcursesDisplay::displayBarChart(GraphList graphs) {
    (void) graphs;
}

void    NcursesDisplay::displayBarChart(NWindow *window, GraphList graphs) {
	GraphList::const_iterator it = graphs.begin();
	GraphList::const_iterator ite = graphs.end();
	int	x = 5;
	int y = 10;
	for (; it != ite; ++it) {
		IntList::const_iterator iit = (*it).begin();
		IntList::const_iterator iite = (*it).end();
		for (; iit != iite; ++iit) {
			mvwprintw(window->getWindow(), y, x, "%d", (*it).size());
			x +=2;
		}
		wrefresh(window->getWindow());
		break;
	}
}

void    NcursesDisplay::displaySprite(Position p, StringList list, int h, int w, int color) {
    (void) color;
    (void) p;
    (void) list;
    (void) h;
    (void) w;
}
void    NcursesDisplay::displaySprite(NWindow *window, Position p, StringList list, int h, int w, int color) {
    StringList::const_iterator      it;
    StringList::const_iterator      ite = list.end();
    int                             y = p.getY();
    std::string                     str;

    for (it = list.begin(); it != ite; ++it) {
        str = *it;
        mvwprintw(window->getWindow(), y, p.getX(), str.c_str());
        y++;
    }
    (void) color;
    (void) p;
    (void) list;
    (void) h;
    (void) w;
    (void) window;
}

// AND THE MAGIC IS HERE
void    NcursesDisplay::initWindows(std::list<IMonitorModule *> const &windows) {
    std::list<IMonitorModule *>::const_iterator     it;
    std::list<IMonitorModule *>::const_iterator     ite = windows.end();
    IMonitorModule                                  *module;
    int                                             y = 0, w = 70, h;
    for (it = windows.begin(); it != ite; ++it) {
        module = *it;
        h = module->getHeight() + 2;
        this->displayWindow(Position(y, 0), module, h, w, 2);
        y += h;
    }
}

void    NcursesDisplay::displayWindow(Position p, IMonitorModule *module, int h, int w, int color) {
    NWindow     *window = new NWindow(p.getY(), p.getX(), h, w, color);
    WINDOW      *win = window->getWindow();
	AModuleGraph	*graph;

    this->_windows.insert(std::pair<std::string, NWindow *>(module->getTitle(), window));
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, 0, 1, module->getTitle().c_str());
    wattroff(win, COLOR_PAIR(3));
    wattron(win, COLOR_PAIR(2));
    this->displaySprite(window, Position(1, 1), module->getContent(), module->getContent().size(), 0, 1);
    if (module->getType() == GRAPH) {
		graph = static_cast<AModuleGraph *>(module);
        this->displayBarChart(window, graph->getGraphs());
	}
    wattroff(win, COLOR_PAIR(2));
    wrefresh(win);
}

void    NcursesDisplay::updateWindow(IMonitorModule *module) {
    std::map<std::string, NWindow *>::iterator it;
    NWindow     *window;
    WINDOW      *win;
	AModuleGraph	*graph;

    it = this->_windows.find(module->getTitle());
    window = &(*it->second);
    win = &(*it->second->getWindow());
    werase(win);
    wborder(win, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, 0, 1, module->getTitle().c_str());
    wattroff(win, COLOR_PAIR(3));
    this->displaySprite(window, Position(1, 1), module->getContent(), module->getContent().size(), 0, 1);
    if (module->getType() == GRAPH) {
		graph = static_cast<AModuleGraph *>(module);
        this->displayBarChart(window, graph->getGraphs());
	}
    wrefresh(win);
}

void    NcursesDisplay::deleteWindow(std::string const &title) {
    std::map<std::string, NWindow *>::iterator it;

    it = this->_windows.find(title);
    delete &(*it->second);
    this->_windows.erase(it);
}

