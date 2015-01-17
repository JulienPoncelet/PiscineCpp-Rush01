#ifndef POSITION_HPP
# define POSITION_HPP
#include <ft_gkrellm.hpp>

class Position {
public:
    Position( void );
    Position(int x, int y);
    Position(Position const & src);
    virtual ~Position( void );
    Position &	operator=(Position const & rhs);

    bool		operator==(Position const & rhs) const;

    int			getX() const;
    int			getY() const;
    void		update(int const x, int const y);
    std::string	toString(void) const;

private:
    int			_x;
    int			_y;
};

std::ostream &	operator<<(std::ostream & o, Position const & rhs);

#endif /* POSITION_HPP */