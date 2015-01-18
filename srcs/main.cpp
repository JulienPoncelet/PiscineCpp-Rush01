#include <ft_gkrellm.hpp>

std::ostream 				& operator<<(std::ostream & out, IMonitorModule const & rhs){
	out << rhs.toString();
	return out;
}


void body(std::list<IMonitorModule *> list, NcursesDisplay *display) {
	std::list<IMonitorModule *>::const_iterator	it;
	std::list<IMonitorModule *>::const_iterator	ite = list.end();
	AModuleSimple								*module;
	AModuleGraph								*graph;

	for (it = list.begin(); it != ite; ++it) {
		if ((*it)->getType() == GRAPH) {
			graph = reinterpret_cast<AModuleGraph *>(*it);
			graph->fillContent();
			graph->fillGraph(graph->getContent());
		}
		else {
			module = static_cast<AModuleSimple *>(*it);
			module->fillContent();
		}
		display->updateWindow(*it);
		refresh();
	}

}

void timer(int seconds, std::list<IMonitorModule*> list, NcursesDisplay *display) {
	double time_counter = 0;

	clock_t this_time = clock();
	clock_t last_time = this_time;

	while (getch() != 'q') {
		this_time = clock();
		time_counter += static_cast<double>(this_time - last_time);
		last_time = this_time;
		if (time_counter > static_cast<double>(seconds * CLOCKS_PER_SEC)) {
			time_counter -= static_cast<double>(seconds * CLOCKS_PER_SEC);
			body(list, display);
		}
	}
}

int									main(int ac, char **av) {
	Options							options = getOptions(--ac, ++av);

	if (options['h']) {
		printHelp();
		return 0;
	}

	ModuleList						modules = fillModules(options);

	if (options['g']) {
		Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(ac, av, "org.gtkmm.examples.base");

  		Gtk::Window window;
  		window.set_default_size(200, 200);

  		return app->run(window);
	}
	else {
		NcursesDisplay					* display = new NcursesDisplay();

		display->init();
		display->initWindows(modules);
	
		timer(1, modules, display);

		display->restore();

		delete display;
	}
	return 0;
}
	
	