#ifndef WINDOW_HPP
# define WINDOW_HPP

#include <ft_gkrellm.hpp>

class NWindow {
public:
    NWindow(int const x, int const y, int const h, int const w, int const color);
    NWindow(NWindow const & src);
    ~NWindow( void );

    NWindow &			operator=(NWindow const & rhs);

    void				initWindow(void);
    void				refreshWindow(void);

    int					getX(void) const;
    int					getY(void) const;
    int					getH(void) const;
    int					getW(void) const;
    int					getColor(void) const;
    WINDOW 				*getWindow(void) const;

private:
    NWindow( void );

    int					_x;
    int					_y;
    int					_h;
    int					_w;
    int                 _color;
    WINDOW				*_window;
};

#endif /* WINDOW_HPP */
