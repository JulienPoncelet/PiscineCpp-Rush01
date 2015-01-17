#include <ft_gkrellm.hpp>

std::ostream 				& operator<<(std::ostream & out, IMonitorModule const & rhs){
	out << rhs.toString();
	return out;
}


void body(std::list<IMonitorModule *> list, NcursesDisplay *display) {
	std::list<IMonitorModule *>::const_iterator	it;
	std::list<IMonitorModule *>::const_iterator	ite = list.end();
	AModuleSimple								*module;

/*	(void) it;
	(void) ite;
	(void) module;
	(void) list;
	(void) display; */

	for (it = list.begin(); it != ite; ++it) {
		module = static_cast<AModuleSimple *>(*it);
		module->fillContent();
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

int						main(void) {

	NcursesDisplay		*display = new NcursesDisplay();
	ModuleHostname		* module0 = new ModuleHostname();
	ModuleOSInfo		* module1 = new ModuleOSInfo();
	ModuleTime			* module2 = new ModuleTime();
	IMonitorModule		* module3 = new ModuleCPU();

	std::list<IMonitorModule*> list;

	list.push_back(module0);
	list.push_back(module1);
	list.push_back(module2);
	list.push_back(module3);

	display->init();
	display->initWindows(list);

	timer(1, list, display);

	display->restore();

	delete display;
	delete module0;
	delete module1;
	delete module2;
	delete module3;

	return 0;
}

