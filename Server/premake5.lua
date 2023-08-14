project "Server"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	
	includedirs
	{
		"Source",
		"%{IncludeDir.spdlog}",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		files
		{
			"Source/**.h",
			"Source/**.cpp",
			"Source/**.c"
		}

	filter "configurations:Debug"
		defines "MODE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "MODE_RELEASE"
		runtime "Release"
		optimize "On"
