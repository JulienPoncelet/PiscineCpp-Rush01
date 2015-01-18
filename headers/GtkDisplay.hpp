#ifndef WINDOW_CLASS
# define WINDOW_CLASS

# include <ft_gkrellm.hpp>

class GtkDisplay : public IMonitorDisplay {

public:

	class Win : public Gtk::Window{

	public:

		bool on_idle(ModuleList modules);
		void on_button_clicked();

		Gtk::Box 		m_Box;
		Gtk::Button 	m_ButtonQuit;
		LabelList 		labels;
		Win(ModuleList modules);
		~Win();

	private:

		Win();
		Win(Win const & display);
		Win & operator=(Win const & display);
		
	};

	// constructor/destructor
	GtkDisplay(int argc, char *argv[]);
	GtkDisplay(GtkDisplay const & window);
	virtual ~GtkDisplay();
	GtkDisplay & operator=(GtkDisplay const & window);

	void refresh(void);
	// void refresh(CPUInfoModule *cpuinfo) const;

private:
	GtkDisplay();
};

#endif