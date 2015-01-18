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

    void    displayBarChart(GraphList graphs);
    void    displayBarChart(NWindow *window, GraphList graphs);

    void    displaySprite(Position p, StringList list, int h, int w, int color);
    void    displaySprite(NWindow *window, Position p, StringList list, int h, int w, int color);

    void    updateWindow(IMonitorModule *module);
    void    deleteWindow(std::string const &title);

    void    initWindows(std::list<IMonitorModule *> const &windows);

    // exceptions

private:

    static bool                         _VERBOSE;
    std::map<std::string, NWindow *>    _windows;

};

// overload
std::ostream            &operator<<(std::ostream &o, NcursesDisplay const &i);

#endif /* NCURSESDISPLAY_H */


