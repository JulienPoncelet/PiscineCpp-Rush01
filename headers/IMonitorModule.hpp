#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <ft_gkrellm.hpp>

class IMonitorModule {

public:

	virtual ~IMonitorModule(void) {};

	virtual std::string const		& getTitle(void) const = 0;
	virtual displayType_e const		& getType(void) const = 0;
	virtual StringList const		& getContent(void) const = 0;
	virtual int const				& getHeight(void) const = 0;

	virtual void					setTitle(std::string title) = 0;
	virtual void					setType(displayType_e type) = 0;
	virtual void					setContent(StringList content) = 0;
	virtual void					setHeight(int height) = 0;
	virtual std::string				toString(void) const = 0;

protected:

	std::string				_title;
	int						_height;
	displayType_e			_type;

};

#endif
