#ifndef NCURSESDISPLAY_H
# define NCURSESDISPLAY_H

#include <ft_gkrellm.hpp>

class NcursesDisplay : public IMonitorDisplay {
public:

    // constructor and destructor
    NcursesDisplay(void);
    NcursesDisplay(NcursesDisplay const &src);
    virtual ~NcursesDisplay(void);

    //setters and getters

    // overload
    NcursesDisplay          &operator=(NcursesDisplay const &rhs);

    // methods
    void    init(void);
    void    restore(void);

    void    displayWindow(Position p, IMonitorModule *module, int h, int w, int color);

    void    displayText(Position p, std::string const &text, int color);
    void    displayText(NWindow *window, Position p, std::string const &text, int color);

    void    displayUnit(Position p, std::string const &text, std::string const &unit, int color);
    void    displayUnit(NWindow *window, Position p, std::string const &text, std::string const &unit, int color);

    void    displayBarChart(Position p, std::vector<int> const &data);
    void    displayBarChart(NWindow *window, Position p, std::vector<int> const &data);

    void    displayCurve(Position p, std::vector<int> const &data, int color);
    void    displayCurve(NWindow *window, Position p, std::vector<int> const &data, int color);

    void    displaySprite(Position p, StringList list, int h, int w, int color);
    void    displaySprite(NWindow *window, Position p, StringList list, int h, int w, int color);

    void    updateWindow(IMonitorModule *module);
    void    deleteWindow(std::string const &title);

    void    initWindows(std::list<IMonitorModule *> const &windows);
    void    reorderWindows(std::list<IMonitorModule *> windows);
    void    refreshWindows(void);
    void    hideWindow(std::list<IMonitorModule *>::const_iterator at);
    void    showWindow(std::list<IMonitorModule *>::const_iterator at);

    void    changeSkin(std::string const &skin);

    // exceptions

private:

    static bool                         _VERBOSE;
    std::map<std::string, NWindow *>    _windows;

};

// overload
std::ostream            &operator<<(std::ostream &o, NcursesDisplay const &i);

#endif /* NCURSESDISPLAY_H */


