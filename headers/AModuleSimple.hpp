#ifndef AMODULESIMPLE_HPP
# define AMODULESIMPLE_HPP

# include <ft_gkrellm.hpp>

class AModuleSimple : public IMonitorModule {

public:

	AModuleSimple(void);
	AModuleSimple(AModuleSimple const & src);
	virtual ~AModuleSimple(void);

	AModuleSimple			& operator=(AModuleSimple const & src);

	std::string				toString(void) const;

	virtual void			fillContent(void) = 0;

	std::string const		& getTitle(void) const;
	displayType_e const		& getType(void) const;
	std::string const		& getContent(void) const;

	void					setTitle(std::string title);
	void					setType(displayType_e type);
	void					setContent(std::string content);

protected:

	std::string 			_content;

};

std::ostream				& operator<<(std::ostream & out, AModuleSimple const & src);

#endif
