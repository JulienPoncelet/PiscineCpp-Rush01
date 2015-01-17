#ifndef I_MONITOR_DISPLAY_H
# define I_MONITOR_DISPLAY_H

#include <iostream>
#include <vector>
#include <list>

class IMonitorDisplay {
public:

    // constructor and destructor
    virtual ~IMonitorDisplay(void);

    // methods

    virtual void    displayWindow(std::string title) = 0;
    virtual void    displayText(std::string const &text) = 0;
    virtual void    displayUnit(std::string const &text, std::string const &unit) = 0;
    virtual void    displayBarChart(std::vector<int> const &data) = 0;
    virtual void    displayCurve(std::vector<int> const &data) = 0;
    virtual void    displaySprite(std::string const *sprite, int h, int w) = 0;

    virtual void    initWindows(std::list<Data *> const &windows) = 0;
    virtual void    reorderWindows(std::list<Data *> windows) = 0;
    virtual void    hideWindow(std::list<Data *>::const_iterator at) = 0;
    virtual void    showWindow(std::list<Data *>::const_iterator at) = 0;

    virtual void    changeSkin(std::string const &skin) = 0;
};

#endif /* I_MONITOR_DISPLAY_H */


