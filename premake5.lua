workpace "HoneyDew"

-- The platform architechture
architechture "x64"

configurations{
	"Debug",
	"Release",
	"Dist"
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architechture}"

project "HoneyDew"
	location "HoneyDew"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines{
			"HNY_PLATFORM_WINDOWS",
			"HNY_BLD_DLL"
		}

		postbuildcommand{
			("{COPY} %{cfg.buildtarget.relpath} .. /bin/" .. outputdir .. "/sandbox")
		}

	filter "configurations::Debug"
		defines "HNY_DEBUG"
		symbols "On"

	filter "configurations::Release"
		defines "HNY_RELEASE"
		optimize "On"

	filter "configurations::Dist"
		defines "HNY_DIST"
		optimize "On"

project "sandbox"

	location "sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"HoneyDew/vendor/spdlog/include",
		"HoneyDew/src"
	}

	links {
		"HoneyDew"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines{
			"HNY_PLATFORM_WINDOWS"
		}

	filter "configurations::Debug"
		defines "HNY_DEBUG"
		symbols "On"

	filter "configurations::Release"
		defines "HNY_RELEASE"
		optimize "On"

	filter "configurations::Dist"
		defines "HNY_DIST"
		optimize "On"

