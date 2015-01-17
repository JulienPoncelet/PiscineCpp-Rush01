#include <iostream>
#include <vector>
#include <list>
#include <ft_gkrellm.hpp>
#include "NcursesDisplay.hpp"

bool    NcursesDisplay::_VERBOSE = true;


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

void    NcursesDisplay::displayWindow(std::string title) {
    (void) title;
}

void    NcursesDisplay::displayText(std::string const &text) {
    (void) text;
}

void    NcursesDisplay::displayUnit(std::string const &text, std::string const &unit) {
    (void) text;
    (void) unit;
}

void    NcursesDisplay::displayBarChart(std::vector<int> const &data) {
    (void) data;
}

void    NcursesDisplay::displayCurve(std::vector<int> const &data) {
    (void) data;
}

void    NcursesDisplay::displaySprite(std::string const *sprite, int h, int w) {
    (void) sprite;
    (void) h;
    (void) w;
}

void    NcursesDisplay::initWindows(std::list<Data *> const &windows) {
    (void) windows;
}

void    NcursesDisplay::reorderWindows(std::list<Data *> windows) {
    (void) windows;
}

void    NcursesDisplay::hideWindow(std::list<Data *>::const_iterator at) {
    (void) at;
}
void    NcursesDisplay::showWindow(std::list<Data *>::const_iterator at) {
    (void) at;
}

void    NcursesDisplay::changeSkin(std::string const &skin) {
    (void) skin;
}

