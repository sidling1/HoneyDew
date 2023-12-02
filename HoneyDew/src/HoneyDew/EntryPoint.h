#pragma once

#ifdef HNY_PLATFORM_WINDOWS

extern Honey::Application* Honey::CreateApplication();

int main(int argc , char ** argv) {
	printf("Welcome to HoneyDew!!");
	auto sb = Honey::CreateApplication();
	sb->Run();
	delete sb;
}

#endif