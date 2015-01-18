#include <ft_gkrellm.hpp>

GtkDisplay::Win::Win(ModuleList modules) :  
  m_Box(Gtk::ORIENTATION_VERTICAL, 5),
  m_ButtonQuit("_Quit", true)
  {
	// set_default_size(200, 200);
	set_title("ft_gkrellm");
	set_border_width(5);

	ModuleList::iterator			it = modules.begin();
	ModuleList::iterator			ite = modules.end();

	for (; it != ite; ++it) {
		add(m_Box);
		Gtk::Frame 					* ftFrame = new Gtk::Frame(((*it)->getTitle().c_str()));
		m_Box.pack_start(*Gtk::manage(ftFrame));

		StringList					content = (*it)->getContent();
		StringList::iterator		sit = content.begin();
		StringList::iterator		site = content.end();
		std::string 				str;

		for (; sit != site; ++sit) {
			str.append((*sit));
			str.append("\n");
		}

		Gtk::Label 					* ftLabel = new Gtk::Label(str.c_str(), true);
		labels.push_back(ftLabel);
		ftFrame->add(*ftLabel);
	}

	Gtk::Box* hbox = Gtk::manage( new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL,10));
	m_Box.pack_start(*hbox);
	hbox->pack_start(m_ButtonQuit, Gtk::PACK_EXPAND_PADDING);

	m_ButtonQuit.signal_clicked().connect( sigc::mem_fun(*this, &GtkDisplay::Win::on_button_clicked) );

	Glib::signal_idle().connect( sigc::bind(sigc::mem_fun(*this, &GtkDisplay::Win::on_idle), modules));

	show_all_children();
}

void GtkDisplay::Win::on_button_clicked()
{
  hide();
}

bool GtkDisplay::Win::on_idle(ModuleList modules) {
	ModuleList::iterator			it = modules.begin();
	ModuleList::iterator			ite = modules.end();
	LabelList::iterator				lit = labels.begin();
	LabelList::iterator				lite = labels.end();

	for (; it != ite; ++it) {
		if ((*it)->getType() == SIMPLE) {
			AModuleSimple 			* module = static_cast< AModuleSimple * >(*it);

			module->fillContent();

			StringList					content = module->getContent();
			StringList::iterator		sit = content.begin();
			StringList::iterator		site = content.end();
			std::string 				str;

			for (; sit != site; ++sit) {
				str.append((*sit));
				str.append("\n");
			}

			(*lit)->set_text(str.c_str());

			lit++;
		}

		if ((*it)->getType() == GRAPH) {
			AModuleGraph 			* module = static_cast< AModuleGraph * >(*it);

			module->fillContent();

			StringList					content = module->getContent();
			StringList::iterator		sit = content.begin();
			StringList::iterator		site = content.end();
			std::string 				str;

			for (; sit != site; ++sit) {
				str.append((*sit));
				str.append("\n");
			}

			(*lit)->set_text(str.c_str());

			lit++;
		}		
	}

  	return true;  // return false when done
}


GtkDisplay::GtkDisplay(void) {}

GtkDisplay::Win::~Win(void) {}

GtkDisplay::~GtkDisplay(void) {}

// void GtkDisplay::refresh(CPUInfoModule *cpuinfo) const {
// 	cpuinfo->update();
// }

void GtkDisplay::refresh(void) {}

