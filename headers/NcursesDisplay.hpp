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

    void    displayWindow(Position p, std::string title);
    void    displayText(Position p, std::string const &text);
    void    displayUnit(Position p, std::string const &text, std::string const &unit);
    void    displayBarChart(Position p, std::vector<int> const &data);
    void    displayCurve(Position p, std::vector<int> const &data);
    void    displaySprite(Position p, std::string const *sprite, int h, int w);

    void    initWindows(std::list<IMonitorModule *> const &windows);
    void    reorderWindows(std::list<IMonitorModule *> windows);
    void    hideWindow(std::list<IMonitorModule *>::const_iterator at);
    void    showWindow(std::list<IMonitorModule *>::const_iterator at);

    void    changeSkin(std::string const &skin);

    // exceptions

private:

    static bool         _VERBOSE;

};

// overload
std::ostream            &operator<<(std::ostream &o, NcursesDisplay const &i);

#endif /* NCURSESDISPLAY_H */


