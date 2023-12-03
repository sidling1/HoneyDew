#pragma once

#ifdef HNY_PLATFORM_WINDOWS

extern Honey::Application* Honey::CreateApplication();

int main(int argc , char ** argv) {

	Honey::HnyLog::Init();
	Honey::HnyLog::GetClientLogger()->warn("Logger Working :)");
	Honey::HnyLog::GetCoreLogger()->info("We can move forward now !");


	printf("Welcome to HoneyDew!!");
	auto sb = Honey::CreateApplication();
	sb->Run();
	delete sb;
}

#endif