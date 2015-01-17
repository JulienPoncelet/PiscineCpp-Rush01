#ifndef I_MONITOR_DISPLAY_H
# define I_MONITOR_DISPLAY_H

#include <iostream>
#include <vector>
#include <list>
#include <ft_gkrellm.hpp>

class IMonitorDisplay {
public:

    // constructor and destructor
    virtual ~IMonitorDisplay(void) {}

    // methods

    virtual void    init(void) = 0;
    virtual void    restore(void) = 0;

    virtual void    displayWindow(Position p, IMonitorModule *module, int h, int w, int color) = 0;
    virtual void    displayText(Position p, std::string const &text, int color) = 0;
    virtual void    displayUnit(Position p, std::string const &text, std::string const &unit, int color) = 0;
    virtual void    displayBarChart(Position p, std::vector<int> const &data) = 0;
    virtual void    displayCurve(Position p, std::vector<int> const &data, int color) = 0;
    virtual void    displaySprite(Position p, StringList list, int h, int w, int color) = 0;

    virtual void    updateWindow(IMonitorModule *module) = 0;
    virtual void    deleteWindow(std::string const &title) = 0;

    virtual void    initWindows(std::list<IMonitorModule *> const &windows) = 0;
    virtual void    reorderWindows(std::list<IMonitorModule *> windows) = 0;
    virtual void    hideWindow(std::list<IMonitorModule *>::const_iterator at) = 0;
    virtual void    showWindow(std::list<IMonitorModule *>::const_iterator at) = 0;

    virtual void    changeSkin(std::string const &skin) = 0;
};

#endif /* I_MONITOR_DISPLAY_H */


