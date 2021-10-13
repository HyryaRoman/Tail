project "GLAD"
    kind "StaticLib"
    language "C"
    staticruntime "Off"

    targetdir ("build/" .. outputdir .. "/%{prj.name}")
    objdir ("build-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "include/glad/gl.h",
        "include/KHR/khrplatform.h",
        "src/gl.c"
    }

    includedirs
    {
        "include"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"