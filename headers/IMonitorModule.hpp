#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <ft_gkrellm.hpp>

class IMonitorModule {

public:

	virtual ~IMonitorModule(void) {};

	virtual std::string const		& getTitle(void) const = 0;
	virtual displayType_e const		& getType(void) const = 0;

	virtual void					setTitle(std::string title) = 0;
	virtual void					setType(displayType_e type) = 0;

protected:

	std::string				_title;
	displayType_e			_type;

};

#endif
