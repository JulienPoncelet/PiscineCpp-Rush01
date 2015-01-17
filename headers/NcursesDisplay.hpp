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
    void    displayWindow(std::string title);
    void    displayText(std::string const &text);
    void    displayUnit(std::string const &text, std::string const &unit);
    void    displayBarChart(std::vector<int> const &data);
    void    displayCurve(std::vector<int> const &data);
    void    displaySprite(std::string const *sprite, int h, int w);

    void    initWindows(std::list<Data *> const &windows);
    void    reorderWindows(std::list<Data *> windows);
    void    hideWindow(std::list<Data *>::const_iterator at);
    void    showWindow(std::list<Data *>::const_iterator at);

    void    changeSkin(std::string const &skin);

    // exceptions

private:

    static bool         _VERBOSE;

};

// overload
std::ostream            &operator<<(std::ostream &o, NcursesDisplay const &i);

#endif /* NCURSESDISPLAY_H */


